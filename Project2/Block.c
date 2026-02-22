#include "Block.h"
#include <windows.h>
#include <gl\GL.h>

GLuint textureID;

void initBlockTexture() {
    int width, height, channels;
    unsigned char* image = stbi_load("grass_side.png", &width, &height, &channels, 0);

    stbi_set_flip_vertically_on_load(1);
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    free(image);
}

void renderBlock(float x, float y, float z) {
	glBindTexture(GL_TEXTURE_2D, textureID); // Unbind any texture to ensure the block is rendered with its colors
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
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 1);
    glVertex3f(-1, 1, -1);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -1);
    glTexCoord2f(0, 0);
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