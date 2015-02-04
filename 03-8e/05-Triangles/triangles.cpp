// triangles.cpp
// my first opengl Program!!
//
// It passes compilation, but generates RUNTIME ERROR in the form of segmentation fault.
// I am QUITE sure the error generates at the beginning of init()

#include <iostream>

#include "vgl.h"
#include "LoadShaders.h"

// please someone tell me the use of those enumerations.
// The red book(8th edition) says these are *Global Variables*.
enum VAO_IDs {Triangles, NumVAOs};
enum Buffer_IDs {ArrayBuffer, NumBuffers};
enum Attrib_IDs {vPosition = 0};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

// ------------------------------------------------
//   init

void
init() {
	GLuint ebo[1];
	GLuint vao[1];
	GLuint vbo[1];
	static const GLfloat vertex_positions[] = {
		-1.0f, -1.0f, 0.0f, 1.0f,
		 1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f,  1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 1.0f
	};

	static const GLfloat vertex_colors[] = {
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f
	};

	static const GLushort vertex_indices[] = {0, 1, 2};

	glGenBuffers(1, ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			sizeof(vertex_indices), vertex_indices, GL_STATIC_DRAW);

	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER,
			sizeof(vertex_positions) + sizeof(vertex_colors),
			NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0,
			sizeof(vertex_positions), vertex_positions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertex_positions),
			sizeof(vertex_colors), vertex_colors);
}


// -----------------------------------------------
//   display

void 
display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	model_matrix = vmath::translation(-3.0f, 0.0f, -5.0f);

	glFlush();
}

// -----------------------------------------------
// main

int 
main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(256, 256);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);

	glewExperimental = GL_TRUE;
	if (glewInit()) {
		std::cerr << "Unable to initize GLEW .. exiting" << std::endl;
		exit(EXIT_FAILURE);
	}

	init();

	glutDisplayFunc(display);

	glutMainLoop();
}
