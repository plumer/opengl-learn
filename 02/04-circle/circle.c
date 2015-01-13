#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void init() {
	glClearColor(0.0,0.0,0.0,0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.2, 1.2, -1.2, 1.2, -1.0, 1.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	const double PI = 3.14159265358979;
	GLint circlePoints = 96;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		int i;
		double angle;
		for (i = 0; i < circlePoints; i++) {
			angle = 2*PI*i / circlePoints;
			glVertex2f(cos(angle), sin(angle));
		}
	glEnd();
	glFlush();// forgotten again
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// don't use double buffers on STATIC image
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
