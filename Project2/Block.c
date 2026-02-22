#include "Block.h"
#include <windows.h>
#include <gl\GL.h>

GLuint grassTex;
GLuint grassTopTex;

GLuint loadTexture(const char* filename) {
    int width, height, channels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    if (!image) {
        return 0;
    }
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    stbi_image_free(image);
    return textureID;
}

void initBlockTextures() {
	grassTex = loadTexture("grass_side.png");
	grassTopTex = loadTexture("grass_top.png");
}

void cleanupBlockTextures() {
    glDeleteTextures(1, &grassTex);
    glDeleteTextures(1, &grassTopTex);
}

void renderBlock(float x, float y, float z) {
	glBindTexture(GL_TEXTURE_2D, grassTex);
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

    glBindTexture(GL_TEXTURE_2D, grassTopTex);
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
