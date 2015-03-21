#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define X .525731112119133606
#define Z .850650808352039932

static float horizontalAngle = 0.0;
static float verticalAngle = M_PI / 3;

#define EYE_X ( sin(horizontalAngle) * sin(verticalAngle) )
#define EYE_Y ( cos(verticalAngle) )
#define EYE_Z ( cos(horizontalAngle) * sin(verticalAngle) )

static GLfloat vdata[12][3] = {
	{-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
	{0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X}, 
	{Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0}
};

static GLuint tindices[20][3] = {
	{1, 4, 0}, {4, 9, 0}, {4, 5, 9}, {8, 5, 4}, {1, 8, 4},
	{1, 10, 8}, {10, 3, 8}, {8, 3, 5}, {3, 2, 5}, {3, 7, 2},
	{3, 10, 7}, {10, 6, 7}, {6, 11, 7}, {6, 0, 11}, {6, 1, 0},
	{10, 1, 6}, {11, 0, 9}, {2, 11, 9}, {5, 2, 9}, {11, 2, 7}
};

static GLfloat ndata[20][3];

void drawAxes(GLfloat length) {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, length, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, length);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(length, 0.0, 0.0);
	glEnd();
}

void drawPlanes(GLfloat halfLength) {
	glColor4f(0.3, 0.3, 0.3, 0.5);
	GLfloat l = halfLength * 2;
	glBegin(GL_QUADS);
		glVertex3f(l, l, 0.0);
		glVertex3f(l, -l, 0.0);
		glVertex3f(-l, -l, 0.0);
		glVertex3f(-l, l, 0.0);
	glEnd();
}


void
init() {
	int i;
	GLfloat normal_vec[3];
	GLfloat * vec1, *vec2, *vec3;
	for (i = 0; i < 20; ++i) {
		vec1 = vdata[tindices[i][0]];
		vec2 = vdata[tindices[i][1]];
		vec3 = vdata[tindices[i][2]];
		normal_vec[0] = vec1[0] + vec2[0] + vec3[0];
		normal_vec[1] = vec1[1] + vec2[1] + vec3[1];
		normal_vec[2] = vec1[2] + vec2[2] + vec3[2];
		normalize3(normal_vec);
		memcpy(ndata[i], normal_vec, sizeof(normal_vec));
//		printf("length for %dth normal vector: %f\n", i, length);
//		printf("%f, %f, %f\n", ndata[i][0], ndata[i][1], ndata[i][2]);
	}


	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vdata);

	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shineness[] = {40.0};
	GLfloat mat_diffuse[] = {0.5, 1.0, 1.0, 1.0};
	GLfloat light_position[]  = {1.0, 1.0, 1.0, 0.0};
	GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat lmodel_ambient[] = {0.3, 0.3, 0.3, 1.0};
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shineness);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void
display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	static int i;
	
	glColor3f(0.5, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt(EYE_X * 3, EYE_Y * 3, EYE_Z * 3,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
	for (i = 0; i < 20; i++) {
		glNormal3fv(ndata[i]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, tindices[i]);
	}

	
	drawAxes(2.0);
//	drawPlanes(1.5);
	/**
	 * The above drawing commands enclosed in glBegin() and glEnd()
	 *   can be replaced by follows,
	 *   having called two functions in line 24-25:
	 */

/*	glBegin(GL_TRIANGLES);
	for (i = 0; i < 20; i++) {
		glArrayElement(tindices[i][0]);
		glArrayElement(tindices[i][1]);
		glArrayElement(tindices[i][2]);
	}
	glEnd();	
*/	
	/**
	 * By using glDrawElements(),
	 * the commands can be compressed furthur:
	 */

/*	for (i = 0; i < 20; i++) {
		glDrawElements(GL_TRIANGLES, 3, GL_UNSINGED_INT, tindices[i]);
	}
*/	
	/**
	 * Even furthur, if tindices[] array is one-dimensionally packed:
	 */

//	glDrawElements(GL_TRIANGLES, 3*20, GL_UNSINGED_INT, tindices);
	
	/**
	 * Or using glDrawArrays():
	 */

//	glDrawArrays(GL_TRIANGLES, 0, 3);
    glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'd':
			horizontalAngle = horizontalAngle + M_PI / 60;
			break;
		case 'a':
			horizontalAngle = horizontalAngle - M_PI / 60;
			break;
		case 'w':
			if (verticalAngle >= M_PI / 60)
				verticalAngle -= M_PI / 60;
			else 
				verticalAngle = 0.0;
			break;
		case 's':
			if (verticalAngle <= M_PI * 59 / 60)
				verticalAngle += M_PI / 60;
			else
				verticalAngle = M_PI;
			break;

		default:
			break;
	}
	glutPostRedisplay();
}

int
main( int argc, char **argv ) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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

