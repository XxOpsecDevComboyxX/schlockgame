#include "Block.h"
#include <windows.h>
#include <gl\GL.h>

void renderBlock() {
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(-1, 1, 1);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, 1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, -1, -1);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1, -1, -1);
	glVertex3f(1, 1, -1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);
	glVertex3f(1, -1, 1);
	glVertex3f(-1, -1, 1);

	glEnd();
}