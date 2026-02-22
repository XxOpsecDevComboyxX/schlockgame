#include "Block.h"
#include <windows.h>
#include <gl\GL.h>

void renderBlock(float x, float y, float z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glBegin(GL_QUADS);
  
    //Red side
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    //Green side
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    //Blue side
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    //Magenta side
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);

    //Yellow side
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    //Cyan side
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
	
    glEnd();

	glPopMatrix();
}