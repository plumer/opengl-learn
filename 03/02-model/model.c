#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

inline void draw_triangle() {
	glBegin(GL_TRIANGLES);
		glVertex2f(-.5, 0);
		glVertex2f( .5, 0);
		glVertex2f(  0, .5);
	glEnd();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0);
	draw_triangle();

	glEnable(GL_LINE_STIPPLE);

	glLineStipple(1, 0xF0F0);
	glLoadIdentity();
	glTranslatef( -.25, 0.0, 0.0);
	glColor3f(0.8, 0.8, 0.8);
	draw_triangle();

	glLineStipple(1, 0xF00F);
	glLoadIdentity();
	glScalef(1.5, 0.5, 1.0);
	glColor3f(0.6, 0.6, 0.6);
	draw_triangle();

	glLineStipple(1, 0x8888);
	glLoadIdentity();
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glColor3f(0.4, 0.4, 0.4);
	draw_triangle();
	
	glFlush();

	glDisable(GL_LINE_STIPPLE);
}

int main (int argc, char **argv) {
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
