#include "window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <stdio.h>

void createWindow(struct WindowData* _window){
	// Initializing GLFW
	if(glfwInit() != GLFW_TRUE){
		printf("Failed to initialize GLFW\n");
	}

	// Window hints
	glfwWindowHint(GLFW_RED_BITS, 8);
	glfwWindowHint(GLFW_GREEN_BITS, 8);
	glfwWindowHint(GLFW_BLUE_BITS, 8);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// Window creation
	_window->ptr = (void*)glfwCreateWindow(_window->width, _window->height, "Ozone2D", NULL, NULL);
	if(!_window->ptr){
		printf("Failed to create window\n");
	}

	// Creating the opengl context
	glfwMakeContextCurrent(_window->ptr);

	// Initializing GLEW
	if(glewInit() != GLEW_OK){
		printf("Failed to initialize GLEW\n");
	}

	// Transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void updateWindow(struct WindowData* _window){
	glfwSwapBuffers(_window->ptr);
	glClear(GL_COLOR_BUFFER_BIT);
}

void destroyWindow(struct WindowData* _window){
	glfwTerminate();
	glfwDestroyWindow(_window->ptr);
}