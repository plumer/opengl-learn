#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>


void init() {
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shineness[] = {50.0};
	GLfloat light0_position[] = {1.0, 1.0, 1.0, 0.0};
	GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.0};
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shineness);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	GLfloat light1_ambient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat light1_diffuse[] = {0.5, 1.0, 1.0, 1.0};
	GLfloat light1_specular[] = {0.5, 1.0, 1.0, 1.0};
	GLfloat light1_position[] = {-2.0, -2.0, 1.0, 1.0};
	GLfloat spot_direction[] = {1.0, 1.0, 0.0};

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
	glLightf(GL_LIGHT1, GL_LIGHT_MODEL_AMBIENT, 0.2);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
}

static GLdouble spin = 0.0;

void display() {
//	gluLookAt(5.0, 1.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	GLfloat light_position[] = {0.0, 0.0, 1.5, 1.0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		gluLookAt(0.0, 0.0, 5.0, /**/ 0.0, 0.0, 0.0, /**/ 0.0, 1.0, 0.0);
		glPushMatrix();
			glRotated(spin, 1.0, 0.0, 0.0);
			glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glPopMatrix();
		glutSolidTorus(0.275, 0.85, 8, 25);
	glPopMatrix();
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) 
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat) w,
				1.5 * (GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w / (GLfloat) h,
				1.5 * (GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'a':
			spin += 5.0;
			break;
		case 'd':
			spin -= 5.0;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}


int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
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
