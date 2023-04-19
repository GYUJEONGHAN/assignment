//201821133 한규정
//2022.10.16(일)

#define GLEW_STATIC

#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "toys.h"

Program program;
GLuint vertBuf = 0;
GLuint vertArray = 0;
GLuint elementBuf = 0;
GLuint triBuf = 0;

void render(GLFWwindow* window);
void init();

int main(void)
{
    if ( !glfwInit() )    exit(EXIT_FAILURE);
    #ifdef __APPLE__
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    #endif
    
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(640,480,"Title",0,0);
    glfwMakeContextCurrent(window);
    init();
    while( !glfwWindowShouldClose(window) ) {
        render(window);
        glfwPollEvents();
    }
    glfwDestroyWindow( window );
    glfwTerminate();
}

using namespace glm;
using namespace std;

void init(){
    program.loadShaders("/Users/gyujh/Desktop/graphics/graphics/shader.frag", "/Users/gyujh/Desktop/graphics/graphics/shader.vert");
    vector<vec3> vertices = {{-1,-1,0},{-0.5,0,0},{0,1,0},{0,-1,0},{0.5,0,0},{1,-1,0}};
    vector<u16vec3> elements = {{0,1,3},{1,2,4},{3,4,5}};
    glGenBuffers(1, &vertBuf);
    glBindBuffer(GL_ARRAY_BUFFER, vertBuf);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vec3)*vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glGenVertexArrays(1, &vertArray);
    glBindVertexArray(vertArray);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, 0, 0, 0);
    
    glGenBuffers(1, &elementBuf);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuf);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(u16vec3)*elements.size(), elements.data(), GL_STATIC_DRAW);
}

void render(GLFWwindow* window){
    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0,0,w,h);
    glClearColor(0,0,0.5,0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(program.programID);
    glBindVertexArray(vertArray);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuf);
    glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_SHORT, 0);
    
    glfwSwapBuffers(window);
}
