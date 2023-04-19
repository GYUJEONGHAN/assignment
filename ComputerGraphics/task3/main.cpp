/*
 컴퓨터그래픽스 과제3
 
 작성일자 2022.12.2(금)
 작성자 미디어학과 201821133 한규정
 */

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include "toys.h"
#include "j3a.hpp"

const float PI = 3.14159265358979f;

void render(GLFWwindow* window);
void init();
void cursorPosCallback(GLFWwindow* win, double xpos, double ypos);
void scrollCallback(GLFWwindow* win, double xoffset, double yoffset);

int main()
{
    if ( !glfwInit() )    exit(EXIT_FAILURE);
        #ifdef __APPLE__
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
        glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
        #endif
    
    glfwInit();
    glfwWindowHint(GLFW_SAMPLES, 8);
    GLFWwindow* window = glfwCreateWindow(640,480,"Title",0,0);
    glfwSetCursorPosCallback(window,cursorPosCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwMakeContextCurrent(window);
    init();
    
    while( !glfwWindowShouldClose(window) ) {
        render(window);
        glfwPollEvents();
    }
    
}

GLuint vertexBuffer = 0;
GLuint normalBuffer = 0;
GLuint vertexArray = 0;
GLuint elementBuffer = 0;

Program program;

float cameraTheta = 0;
float cameraPhi = 0;
float scaleFactor = 1.0;
float cameraDistance = 5;
float fovy = 80 * PI / 180;

bool isShrinking = true;

using namespace glm;
using namespace std;

vec3 lightPosition = vec3(3, 10, 5);
vec3 lightColor = vec3(100);
vec3 ambientLight = vec3(0.0);


void cursorPosCallback(GLFWwindow* win, double xpos, double ypos) {
    static double lastX = 0;
    static double lastY = 0;
    if( glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_1)) {
        double dx = xpos - lastX;
        double dy = ypos - lastY;
        int w, h;
        glfwGetWindowSize(win, &w, &h);
        cameraTheta -= dx/w*PI;
        cameraPhi -= dy/h*PI;
        printf("%.3f %.3f\n", cameraTheta, cameraPhi);
    }
    lastX = xpos;
    lastY = ypos;
}


void scrollCallback(GLFWwindow* win, double xoffset, double yoffset) {
    //cameraDistance = cameraDistance*pow(1.05, yoffset);
    fovy += yoffset/30;
}

void init(){
    loadJ3A("Hebe.j3a"); //loadJ3A("dwarf.j3a");
    program.loadShaders("shader.vert","shader.frag");
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, nVertices[0]*sizeof(glm::vec3), vertices[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, nVertices[0]*sizeof(glm::vec3), normals[0], GL_STATIC_DRAW);

    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,0,0,0);
    
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,3,GL_FLOAT,0,0,0);
    
    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, nTriangles[0]*sizeof(glm::u32vec3), triangles[0], GL_STATIC_DRAW);
}

void render (GLFWwindow* window) {
    int w, h;
    glfwGetFramebufferSize(window, &w, &h );
    glViewport(0, 0, w, h);
    glClearColor(0, 0, 0.5, 0);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(program.programID);


    vec3 initialCameraPosition = vec3(0,0, cameraDistance);
    mat4 cameraRotationMatrix1 = rotate(cameraPhi, vec3(1,0,0));
    mat4 cameraRotationMatrix2 = rotate(cameraTheta, vec3(0,1,0));
    
    vec3 cameraPosition = cameraRotationMatrix2 * cameraRotationMatrix1 * vec4(initialCameraPosition, 1);
    
    mat4 viewMat = glm::lookAt(cameraPosition, vec3(0,0,0), vec3(0,1,0));
    mat4 projMat = glm::perspective(fovy,w/(float)h,0.01f,1000.f);
    
//  mat3 scalingMatrix = mat3(scaleFactor,0,0,0,scaleFactor,0,0,0,1);
    GLuint modelMatLocation = glGetUniformLocation(program.programID, "modelMat");
    glUniformMatrix4fv (modelMatLocation,1,0,value_ptr(mat4(1)));
    
    GLuint viewMatLocation = glGetUniformLocation(program.programID, "viewMat");
    glUniformMatrix4fv (viewMatLocation,1,0,value_ptr(viewMat));
    
    GLuint projMatLocation = glGetUniformLocation(program.programID, "projMat");
    glUniformMatrix4fv (projMatLocation,1,0,value_ptr(projMat));
    
    GLuint colorLocation = glGetUniformLocation(program.programID, "color");
    glUniform4fv(colorLocation, 1, value_ptr(diffuseColor[0]));
    
    GLuint shininessLocation = glGetUniformLocation(program.programID, "shininess");
    glUniform1f(shininessLocation, shininess[0]);
    
    GLuint lightPositionLocation = glGetUniformLocation(program.programID, "lightPosition");
    glUniform3fv (lightPositionLocation,1,value_ptr(lightPosition));
    GLuint lightColorLocation = glGetUniformLocation(program.programID, "lightColor");
    glUniform3fv (lightColorLocation,1,value_ptr(lightColor));
    
    GLuint ambientLightLocation = glGetUniformLocation(program.programID, "ambientLight");
    glUniform3fv (ambientLightLocation,1,value_ptr(ambientLight));
    GLuint cameraPositionLocation = glGetUniformLocation(program.programID, "cameraPosition");
    glUniform3fv (cameraPositionLocation,1,value_ptr(cameraPosition));
    

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glDrawElements(GL_TRIANGLES, nTriangles[0]*3, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
}
