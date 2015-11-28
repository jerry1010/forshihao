// ShihaoProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"GL/glew.h"
#include"GL/glut.h"
#include "drawApi.h"
float windowW = 0, windowH = 0;
void drawPoint(int x, int y)
{
	auto px = x / windowW * 2 - 1;
	auto py = y / windowH * 2 - 1;
	glVertex3f(px,-py,0);
}

void RenderScene()
{
	//清空颜色缓冲区，填充的颜色由 glClearColor( 0, 0.0, 0.0, 1 ); 指定为黑色

	glClear(GL_COLOR_BUFFER_BIT);


	glPolygonMode(GL_FRONT, GL_FILL); // 设置正面为填充模式

	glPolygonMode(GL_BACK, GL_LINE); // 设置反面为线形模式


									 //绘制一个三角形

	{
		glColor3f(1.0f, 0.0f, 0.0f);//指定颜色,红色

		//glBegin(GL_TRIANGLES);//开始画三角形

		//{
		//	glVertex3f(0.0f, 0.0f, 0.0f);
		//	glVertex3f(25.f, 25.f, 0);
		//	glVertex3f(50.f, 0, 0);

		//	glVertex3f(-50.f, 0.0f, 0.0f);
		//	glVertex3f(-25.f, 0, 0);
		//	glVertex3f(-75.f, 50.f, 0);
		//}
		//glEnd();//结束
		glBegin(GL_POINTS);

		onScenceRender();

		glEnd();
	}

	glutSwapBuffers();
}

void SetupRC()
{
	glClearColor(0, 0.0, 0.0, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
}

void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 1.f;

	// Prevent a divide by zero

	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions

	glViewport(0, 0, w, h);

	// Reset projection matrix stack

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)

	if (w <= h)
		glOrtho(-nRange, nRange, -nRange, nRange, -nRange, nRange);
	else
		glOrtho(-nRange, nRange, -nRange, nRange, -nRange, nRange);

	windowW = w;
	windowH = h;

	// Reset Model view matrix stack

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("带石豪装逼带石豪飞");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();

	return 1;
}