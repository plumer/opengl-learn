#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int shoulder = 0, elbow = 0;

void drawAxes(GLfloat length) {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(length, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, length, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, length);
	glEnd();
}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
		drawAxes(0.5);
		glTranslatef(-1.0, 0.0, 0.0);			// this call makes all objects translated
												// so as not to go beyond the window
		glRotatef( (GLfloat) shoulder, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);			// makes upper arm rotate about shoulder
												// instead of the center of the arm

		drawAxes(0.5);

		glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(1.0);
		glPopMatrix();

		glTranslatef(1.0, 0.0, 0.0);
		drawAxes(0.5);
		glRotatef( (GLfloat) elbow, 0.0, 0.0, 1.0);
		drawAxes(0.5);
		glTranslatef(1.0, 0.0, 0.0);

		drawAxes(0.5);

		glPushMatrix();
			glScalef(2.0, 0.4, 1.0);
			glutWireCube(1.0);
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0.0, 0.0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch(key) {
		case 's':
			shoulder = (shoulder + 5) % 360;
			glutPostRedisplay();
			break;
		case 'S':
			shoulder = (shoulder - 5) % 360;
			glutPostRedisplay();
			break;

		case 'e':
			elbow = (elbow + 5) % 360;
			glutPostRedisplay();
			break;
		case 'E':
			elbow = (elbow - 5) % 360;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

int main( int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
