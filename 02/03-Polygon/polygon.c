#include <GL/gl.h>
#include <GL/glut.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);	// you missed this.

	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 3.0);
		glVertex2f(4.0, 3.0);
		glVertex2f(5.5, 1.5);
		glVertex2f(4.0, 0.0);
	glEnd();

	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POINTS);
		glVertex2f(1.0, 4.0);
		glVertex2f(2.0, 5.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
		glVertex2f(2.0, 2.0);
		glVertex2f(3.0, 4.0);
		glVertex2f(8.0, 4.0);
		glVertex2f(7.0, 5.0);
	glEnd();

	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_LINE_STRIP);
		glVertex2f(1.0, 2.0);
		glVertex2f(2.0, 4.0);
		glVertex2f(6.0, 7.0);
	glEnd();


	glFlush(); // you missed this.
}


int main(int argc, char ** argv) {
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

