#define NDEBUG
#include <GL/glut.h>

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);

	//以下语句二选一，看看效果
	glShadeModel(GL_SMOOTH);
	//glShadeModel(GL_FLAT);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//以下语句绘制三角形，请自行改成绘制立方体
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, -1.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	glFlush(); /* clear buffers */
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	//以下语句设置相机投影参数
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//以下两句二选一，看看效果
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glFrustum(-1.0, 1.0, -1.0, 1.0, 0.3, 10.0);


	//以下语句设置相机和物体的相对方位
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

/*
void idlefunc()
{
	//改变动画参数
	glutPostRedisplay();
}
*/

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutIdleFunc(idlefunc);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
