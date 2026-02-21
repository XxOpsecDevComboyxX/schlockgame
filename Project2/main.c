#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include "Block.h"
int main(int argc, char* argv[])
{
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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 640.0 / 480.0, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
//glEnable(GL_LIGHTING);
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	int running = 1;
	SDL_Event event;

	
	float yaw = 0.0;
	float pitch = 0.0;
	float radYaw = 0.0;
	float radPitch = 0.0;
	float dirX = 0.0;
	
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
//camera movement
			
			if (event.type == SDL_KEYDOWN)
			switch (event.key.keysym.sym) {
			case SDLK_w:
				printf("Up arrow pressed\n");
				break;
			case SDLK_s:
				printf("Down arrow pressed\n");
				break;
			case SDLK_a:
				printf("Left arrow pressed\n");
				break;
			case SDLK_d:
				printf("Right arrow pressed\n");
				break;
			default:
				break;
			}
//camera rotation

			if (event.type == SDL_MOUSEMOTION)
			{

				yaw += event.motion.xrel * 0.1f;
				pitch += event.motion.yrel * 0.1f;
				if (pitch > 89.0f) pitch = 89.0f;
				if (pitch < -89.0f) pitch = -89.0f;
			}
		}

		radYaw = yaw * M_PI / 180.0f;
		radPitch = pitch * M_PI / 180.0f;

		dirX = cos(radPitch) * cos(radYaw);
		float dirY = sin(radPitch);
		float dirZ = cos(radPitch) * sin(radYaw);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef(0.0, 0.0, -15.0);
		glRotatef(-pitch, 1.0f, 0.0f, 0.0f); // pitch
		glRotatef(-yaw, 0.0f, 1.0f, 0.0f); // yaw
//World gen//
		
		int width;
		int length;
		int height;
		
		float X = 0;
		for (width = 0; width <= 10; width++) {
			for (length = 0; length <= 10; length++) {
				for (height = 0; height <= 10; height++) {
					renderBlock(2.0f * width, 2.0f * height, 2.0f * length);
				}
			}
			
			
		}

		SDL_GL_SwapWindow(window);

	}
	SDL_GL_DeleteContext(glCONTEXT);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}