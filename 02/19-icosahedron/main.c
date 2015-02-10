#include <GL/gl.h>
#include <GL/glut.h>

#define X .525731112119133606
#define Z .850650808352039932

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

void
init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vdata);
}

void
display() {
	glClear(GL_COLOR_BUFFER_BIT);
	static int i;
	glColor3f(0.5, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	for (i = 0; i < 20; i++) {
		glVertex3fv(vdata[tindices[i][0]]);
		glVertex3fv(vdata[tindices[i][1]]);
		glVertex3fv(vdata[tindices[i][2]]);
	}
	glEnd();

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
}

int
main( int argc, char **argv ) {
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

