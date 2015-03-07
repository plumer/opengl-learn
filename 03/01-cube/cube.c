
#include <GL/glu.h>		/* we're using gluLookAt() */
#include <GL/glut.h>

#include <math.h>
#include <unistd.h>
#include <stdio.h>

GLfloat angle;
#define AXIS_LENGTH 2.0
GLfloat origin[3] = {0.0, 0.0, 0.0};
GLfloat xa[3] = {AXIS_LENGTH, 0.0, 0.0};
GLfloat ya[3] = {0.0, AXIS_LENGTH, 0.0};
GLfloat za[3] = {0.0, 0.0, AXIS_LENGTH};

void drawAxes() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
		glVertex3fv(origin);
		glVertex3fv(xa);
		glVertex3fv(origin);
		glVertex3fv(ya);
		glVertex3fv(origin);
		glVertex3fv(za);
	glEnd();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT); /* wtf? */
	angle = 0.0;
}

void display() {
//	angle += M_PI / 60;
//	printf("calling display: %f\n", angle);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity(); /* clear the matrix */

	/* viewing transformation */
	gluLookAt(3.0, 4.0, 2.0, /* look from here */
			0.0, 0.0, 0.0,   /* to here */
			0.0, 1.0, 0.0);
//	glScalef(1.0, 2.0, 1.0);
	glutWireCube(1.0);
	drawAxes();
	glFlush();
}

void reshape(int w, int h) {
//	puts("calling reshape");
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//	gluPerspective(0.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}

