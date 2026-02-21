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
	/////////////////////
	//MY CODE jigga!!!!//
	/////////////////////
	SDL_GLContext glCONTEXT = SDL_GL_CreateContext(window);

	if (!glCONTEXT)
		return 1;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	int running = 1;
	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					printf("Up arrow pressed\n");
					yaw += 1;
					break;
				case SDLK_DOWN:
					printf("Down arrow pressed\n");
					yaw -= 1;
					break;
				case SDLK_LEFT:
					printf("Left arrow pressed\n");
					pitch += 1;
					break;
				case SDLK_RIGHT:
					printf("Right arrow pressed\n");
					pitch -= 1;
					break;
				default:
					break;
				}
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
		glRotatef(pitch, dirX, 0.0, 0.0); // pitch
		glRotatef(yaw, dirX, 0.0, 0.0); // yaw
		glBegin(GL_QUADS);

		renderBlock();

		SDL_GL_SwapWindow(window);

	}
	SDL_GL_DeleteContext(glCONTEXT);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}