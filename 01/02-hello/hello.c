
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void display() {
	// clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);
	// draw white polygon
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	// don't wait! start processing buffered OpenGl routines
	glFlush();
}

void init() {
	// select clearing (background) color
	glClearColor(0.0,0.0,0.0,0.0);

	// initialize viewing values
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

// Declare initial window size, position, and display mode
// Open window with "hello" in its title bar.
// Call initialization routines.
// Register callback function to display graphics.
// Enter main loop and process events.

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
