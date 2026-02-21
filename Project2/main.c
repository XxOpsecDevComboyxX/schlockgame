#include <windows.h>
#include <gl\GL.h>
#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include "Block.h"
int main(int argc, char* argv[])
{
	float yaw = 0.0;
	float pitch = 0.0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return 1;

	SDL_Window* window = SDL_CreateWindow(
		"SDL2 Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
	);

	if (!window)
		return 1;
	SDL_GLContext glCONTEXT = SDL_GL_CreateContext(window);

	if (!glCONTEXT)
		return 1;

	SDL_SetRelativeMouseMode(SDL_TRUE);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	//glEnable(GL_LIGHTING);
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	int running = 1;
	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;

			if (event.type == SDL_MOUSEMOTION)
			{
				yaw += event.motion.xrel * 0.1f;
				pitch += event.motion.yrel * 0.1f;
				if (pitch > 89.0f) pitch = 89.0f;
				if (pitch < -89.0f) pitch = -89.0f;
			}
		}

		float radYaw = yaw * M_PI / 180.0f;
		float radPitch = pitch * M_PI / 180.0f;

		float dirX = cos(radPitch) * cos(radYaw);
		float dirY = sin(radPitch);
		float dirZ = cos(radPitch) * sin(radYaw);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Where we render myfaef
		glLoadIdentity();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(-pitch, 1.0f, 0.0f, 0.0f); // pitch
		glRotatef(-yaw, 0.0f, 1.0f, 0.0f); // yaw

		renderBlock();

		SDL_GL_SwapWindow(window);

	}
	SDL_GL_DeleteContext(glCONTEXT);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}