#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int year = 0, day = 0;
GLfloat height = 1.0;

void init() {
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt(0.0, height, 5.0,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
	glPushMatrix();

	glutWireSphere(1.0, 20, 16);
//	glTranslatef(2.0, 0.0, 0.0);	
	glRotatef( (GLfloat) year, -.1, 1.0, 0.0);
	glTranslatef(2.0, 0.2, 0.0);
	glRotatef( (GLfloat) day, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8);

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'd':
			day = (day + 10) % 360;
			break;
		case 'D':
			day = (day - 10) % 360;
			break;
		case 'y':
			year = (year + 5) % 360;
			break;
		case 'Y':
			year = (year - 5) % 360;
			break;
		case 'w':
			height += 0.05;
			break;
		case 's':
			height -= 0.05;
		default:
			break;
	}
	glutPostRedisplay();
}

int main( int argc, char ** argv ) {
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
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
