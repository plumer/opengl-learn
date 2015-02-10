#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat colors[] = {
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0
};

static GLfloat vertices[] = {
	.25, .25,
	.75, .25,
	.25, .75
};

void
init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, colors);
	glVertexPointer(2, GL_FLOAT, 0, vertices);

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, -1.0);
}

void
display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glArrayElement(0);		
		glArrayElement(1);	
		glArrayElement(2);
	glEnd();

	glFlush();
}

int
main( int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(256, 256);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
