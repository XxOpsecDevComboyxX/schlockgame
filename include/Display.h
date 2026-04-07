#pragma once
#include <GL/gl.h>

GLuint createTexturesFromSurface(SDL_Surface* surface);
void drawTexturedQuad(GLuint texture, float x, float y, float w, float h);