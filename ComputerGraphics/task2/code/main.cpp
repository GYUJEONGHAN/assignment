#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include "toys.h"
#include "j3a.hpp"


const float PI = 3.14159265358979f;
Program program;
GLuint vertBuf = 0;
GLuint vertArray = 0;
GLuint triBuf = 0;
float theta = 0;
float scaleFactor = 1.0;
bool isShrinking = true;

using namespace glm;
using namespace std;


void render(GLFWwindow* window);
void init();

int main() {
    if ( !glfwInit() )
    exit(EXIT_FAILURE);
    #ifdef __APPLE__
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    #endif
    
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640, 480, "Title", 0, 0);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    init();

    while (
        !glfwWindowShouldClose(window)
        ) {
        render(window);
        glfwPollEvents();
    }
}
void init(){
    program.loadShaders("/Users/hangyujeong/Desktop/ajouuniv/2022-2/컴퓨터그래픽스/컴그 프로젝트/CPG/CPG/shader.vert", "/Users/hangyujeong/Desktop/ajouuniv/2022-2/컴퓨터그래픽스/컴그 프로젝트/CPG/CPG/shader.frag");
    loadJ3A("banana.j3a");

    glGenBuffers(1, &vertBuf);
    glBindBuffer(GL_ARRAY_BUFFER, vertBuf);
    glBufferData(GL_ARRAY_BUFFER, nVertices[0] * sizeof(glm::vec3), vertices[0], GL_STATIC_DRAW);
    glGenVertexArrays(1, &vertArray);
    glBindVertexArray(vertArray);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertBuf);
    glVertexAttribPointer(0, 3, GL_FLOAT, 0, 0, 0);

    glGenBuffers(1, &triBuf);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triBuf);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nTriangles[0] * sizeof(glm::u32vec3), triangles[0], GL_STATIC_DRAW);

}


void render(GLFWwindow* window) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glClearColor(0, 0, .5, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program.programID);
    GLuint colorLocation = glGetUniformLocation(program.programID, "color");
    glUniform4fv(colorLocation, 1, value_ptr(vec4(1, 1, 0, 1)));
    theta += 5.0f / 180 * PI;
    
    if (isShrinking) {
        scaleFactor -= 0.025;
        if (scaleFactor < 0.5) isShrinking = false;
    }
    
    else {
        scaleFactor += 0.025;
        if (scaleFactor > 1) isShrinking = true;
    }

    mat4 rotationMatrix = rotate(theta, vec3(0, 1, 0));
    GLuint transformLocation = glGetUniformLocation(program.programID, "transform");
    glUniformMatrix4fv(transformLocation, 1, 0, value_ptr(rotationMatrix));
    
    glBindVertexArray(vertArray);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triBuf);
    glDrawElements(GL_TRIANGLES, nTriangles[0] * 3, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
}
