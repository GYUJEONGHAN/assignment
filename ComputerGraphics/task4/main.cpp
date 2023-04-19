/*
 컴퓨터그래픽스 과제4
 
 작성일자 2022.12.29(목)
 작성자 미디어학과 201821133 한규정
 */

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
const float PI = 3.14159265358979f;
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include "toys.h"
#include "j3a.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Program program;
GLuint vertexBuffer = 0;
GLuint textureCoordinateBuf = 0;
GLuint normalBuffer = 0;
GLuint vertexArray = 0;
GLuint elementBuffer = 0;
float cameraTheta = 0;
float cameraPhi = 0;
float scaleFactor = 1.0;
bool isShrinking = true;
float cameraDistance = 5;
float fovy = 80 * PI / 180;

using namespace glm;
using namespace std;
vec3 lightPosition = vec3(3, 10, 5);
vec3 lightColor = vec3(100);
vec3 ambientLight = vec3(0.0);
GLuint diffTex = 0;
GLuint bumpTex = 0;


void render(GLFWwindow* window);
void init();
void SetCursorPosCallback(GLFWwindow* win, double xpos, double ypos) {
    static double lastX = 0;
    static double lastY = 0;
    if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_1)) {
        double dx = xpos - lastX;
        double dy = ypos - lastY;
        int w, h;
        glfwGetWindowSize(win, &w, &h);
        cameraTheta -= dx / w * PI;
        cameraPhi -= dy / h * PI;
        
    }
    lastX = xpos;
    lastY = ypos;
}
void scrollcallback(GLFWwindow* win, double xoffset, double yoffset) {
    fovy += yoffset / 30;
}

int main() {

    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 8);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Title", 0, 0);
    glfwSetCursorPosCallback(window, SetCursorPosCallback);
    glfwSetScrollCallback(window, scrollcallback);
    glfwMakeContextCurrent(window);

    glewInit();
    glfwSwapInterval(1);

    init();

    while (
        !glfwWindowShouldClose(window)
        ) {

        render(window);

        glfwPollEvents();
    }
}

void init() {
    program.loadShaders("shader.vert", "shader.frag");
    loadJ3A("dwarf.j3a");

    int w, h, n;

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(glm::vec3), vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(glm::vec3), normals[0], GL_STATIC_DRAW);

    glGenBuffers(1, &textureCoordinateBuf);
    glBindBuffer(GL_ARRAY_BUFFER, textureCoordinateBuf);
    glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(glm::vec2), texCoords[0], GL_STATIC_DRAW);


    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, 0, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, 0, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, textureCoordinateBuf);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, 0, 0, 0);


    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nTriangles[0] * sizeof(glm::u32vec3), triangles[0], GL_STATIC_DRAW);

    stbi_set_flip_vertically_on_load(true);
    void* d = stbi_load(diffuseMap[0].c_str(), &w, &h, &n, 4);
    printf("image : %s %d x %d\n", diffuseMap[0].c_str(), w, h);
    glGenTextures(1, &diffTex);
    glBindTexture(GL_TEXTURE_2D, diffTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB8_ALPHA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, d);

    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(d);
    

    d = stbi_load(bumpMap[0].c_str(), &w, &h, &n, 4);
    printf("image : %s %d x %d\n", bumpMap[0].c_str(), w, h);
    glGenTextures(1, &bumpTex);
    glBindTexture(GL_TEXTURE_2D, bumpTex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 8);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, d);

    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(d);

}

void render(GLFWwindow* window) {

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glClearColor(0, 0, .5, 0);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(program.programID);


    vec3 initialCameraPosition = vec3(0, 0, cameraDistance);
    mat4 cameraRotationMatrix1 = rotate(cameraPhi, vec3(1, 0, 0));
    mat4 cameraRotationMatrix2 = rotate(cameraTheta, vec3(0, 1, 0));

    vec3 cameraPosition = cameraRotationMatrix2 * cameraRotationMatrix1 * vec4(initialCameraPosition, 1);

    mat4 viewMat = lookAt(cameraPosition, vec3(0, 0, 0), vec3(0, 1, 0));
    mat4 projMat = perspective(fovy, width / (float)height, 0.01f, 1000.f);

    // mat3 scalingMatrix = mat3(scaleFactor, 0, 0, 0, scaleFactor, 0, 0, 0, 1);
    GLuint modelMatLocation = glGetUniformLocation(program.programID, "modelMat");
    glUniformMatrix4fv(modelMatLocation, 1, 0, value_ptr(mat4(1)));


    GLuint viewMatLocation = glGetUniformLocation(program.programID, "viewMat");
    glUniformMatrix4fv(viewMatLocation, 1, 0, value_ptr(viewMat));

    GLuint projMatLocation = glGetUniformLocation(program.programID, "projMat");
    glUniformMatrix4fv(projMatLocation, 1, 0, value_ptr(projMat));

    GLuint lightPositionLocation = glGetUniformLocation(program.programID, "lightPosition");
    glUniform3fv(lightPositionLocation, 1, value_ptr(lightPosition));

    GLuint lightColorLocation = glGetUniformLocation(program.programID, "lightColor");
    glUniform3fv(lightColorLocation, 1, value_ptr(lightColor));

    GLuint colorLocation = glGetUniformLocation(program.programID, "color");
    glUniform4fv(colorLocation, 1, value_ptr(diffuseColor[0]));

    GLuint shininessLocation = glGetUniformLocation(program.programID, "shininess");
    glUniform1f(shininessLocation, shininess[0]);

    GLuint ambientLightLocation = glGetUniformLocation(program.programID, "ambientLight");
    glUniform3fv(ambientLightLocation, 1, value_ptr(ambientLight));

    GLuint cameraPositionLocation = glGetUniformLocation(program.programID, "cameraPosition");
    glUniform3fv(cameraPositionLocation, 1, value_ptr(cameraPosition));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffTex);
    GLuint diffTexLocation = glGetUniformLocation(program.programID, "diffTex");
    glUniform1i(diffTexLocation, 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, bumpTex);
    GLuint bumpTexLocation = glGetUniformLocation(program.programID, "bumpTex");
    glUniform1i(bumpTexLocation, 1);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glDrawElements(GL_TRIANGLES, nTriangles[0] * 3, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);

}
