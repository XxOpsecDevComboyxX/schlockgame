#include "Block.h"
#ifdef _WIN32
#include <windows.h>
#include <gl\GL.h>
#elif defined(__linux__)
#include <unistd.h>
#include <gl\gl.h>
#endif
#include "Blocks.h"

void renderBlock(float x, float y, float z, Block* block) {
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

    //Back side
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);
	
    glEnd();
    glPopMatrix();
}
