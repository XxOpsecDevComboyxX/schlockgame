#include "Blocks.h"
#ifdef _WIN32
#include <windows.h>
#include <gl\GL.h>
#elif defined(__linux__)
#include <unistd.h>
#include <GL/gl.h>
#endif
#include "Blocks.h"
#include <stdio.h>

void renderBlock(float x, float y, float z, Block* block) {
	if (block->isTransparent != 1) {
		glBindTexture(GL_TEXTURE_2D, block->textureID);
		glPushMatrix();
		glTranslatef(x, y, z);
		glBegin(GL_QUADS);

		//Red side
		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 0);
		glVertex3f(-1, -1, 1);
		glTexCoord2f(1, 0);
		glVertex3f(1, -1, 1);
		glTexCoord2f(1, 1);
		glVertex3f(1, 1, 1);
		glTexCoord2f(0, 1);
		glVertex3f(-1, 1, 1);

		//Green side
		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 0);
		glVertex3f(1, -1, -1);
		glTexCoord2f(1, 0);
		glVertex3f(-1, -1, -1);
		glTexCoord2f(1, 1);
		glVertex3f(-1, 1, -1);
		glTexCoord2f(0, 1);
		glVertex3f(1, 1, -1);

		//Blue side
		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 0);
		glVertex3f(-1, -1, -1);
		glTexCoord2f(1, 0);
		glVertex3f(-1, -1, 1);
		glTexCoord2f(1, 1);
		glVertex3f(-1, 1, 1);
		glTexCoord2f(0, 1);
		glVertex3f(-1, 1, -1);

		//Magenta side
		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 0);
		glVertex3f(1, -1, 1);
		glTexCoord2f(1, 0);
		glVertex3f(1, -1, -1);
		glTexCoord2f(1, 1);
		glVertex3f(1, 1, -1);
		glTexCoord2f(0, 1);
		glVertex3f(1, 1, 1);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, block->topTextureID);
		glBegin(GL_QUADS);
		//Top side
		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 1);
		glVertex3f(-1, 1, -1);
		glTexCoord2f(1, 1);
		glVertex3f(-1, 1, 1);
		glTexCoord2f(1, 0);
		glVertex3f(1, 1, 1);
		glTexCoord2f(0, 0);
		glVertex3f(1, 1, -1);
		glEnd();

		//Back side
		glBindTexture(GL_TEXTURE_2D, block->topTextureID);
		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 1);
		glVertex3f(-1, -1, -1);
		glTexCoord2f(1, 1);
		glVertex3f(1, -1, -1);
		glTexCoord2f(1, 0);
		glVertex3f(1, -1, 1);
		glTexCoord2f(0, 0);
		glVertex3f(-1, -1, 1);

		glEnd();
		glPopMatrix();
	}
}
