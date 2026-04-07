#include <SDL_surface.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLuint createTexturesFromSurface(SDL_Surface* surface, SDL_Surface* rgbaSurface) {
    GLuint texID;
    glBindTexture(GL_TEXTURE_2D, texID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgbaSurface->pixels);

    return texID;
}

void drawTexturedQuad(GLuint texture, float x, float y, float w, float h) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(x, y);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(x + w, y);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(x + w, y +h);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(x, y + h);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}