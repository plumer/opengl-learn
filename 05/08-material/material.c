#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.0};
	
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	GLfloat no_mat [] = {0.0, 0.0, 0.0, 1.0};
	GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
	GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
	GLfloat mat_diffuse[] = {0.1, 0.5, 0.8, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat no_shininess[] = {0.0};
	GLfloat low_shininess[] = {5.0};
	GLfloat high_shininess[] = {100.0};
	GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
		glTranslatef(-3.75, 3.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(1.0, 16, 16);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.25, 3.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT,	no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE,	mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR,	mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS,low_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(1.0, 16, 16);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.25, 3.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT,	no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE,	mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR,	mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS,high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		glutSolidSphere(1.0, 16, 16);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3.75, 3.0, 0.0);
		glMaterialfv(GL_FRONT, GL_AMBIENT,	no_mat);
		glMaterialfv(GL_FRONT, GL_DIFFUSE,	mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR,	no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS,no_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		glutSolidSphere(1.0, 16, 16);
	glPopMatrix();
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) 
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h/ (GLfloat)w,
				1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho( -1.5*(GLfloat)w/ (GLfloat)h,
				1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	
	return 0;
}
