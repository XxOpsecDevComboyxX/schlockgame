#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include "Block.h"
#include "Chunk.h"
#include "Collision.h"
#include <stdbool.h>
#include "stb_image.h"

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
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_LIGHTING);
	glClearColor(0.0f, 0.5f, 0.7f, 1.0f);

	int running = 1;
	SDL_Event event;
	
	float yaw = 0.0;
	float pitch = 0.0;
	float radYaw = 0.0;
	float radPitch = 0.0;
	float MovX = 0.0;
	float MovY = 0.0;
	float MovZ = 0.0;
	float dirX = 0.0;
	float dirY = 0.0;
	float dirZ = 0.0;
	float rightX = 0.0;
	float rightZ = 0.0;
	float Velocity = 1.0f;
	float Acceleration = 0.0f;
	float RelGravity = 0.0f;

	bool set = false;

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
				MovX -= dirX;
				MovZ -= dirZ;
				MovY += dirY;
				printf("%f\n", RelGravity);
				break;
			case SDLK_s:
				MovX += dirX;
				MovZ += dirZ;
				MovY -= dirY;
				printf("%f\n", MovZ);
				break;
			case SDLK_a:
				MovX += rightX;
				MovZ += rightZ;
				printf("%f\n", MovX);
				break;
			case SDLK_d:
				MovX -= rightX;
				MovZ -= rightZ;
				printf("%f\n", MovX);
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
		dirX = cos(radPitch) * sin(radYaw);
		dirY = sin(radPitch);
		dirZ = -cos(radPitch) * cos(radYaw);

		rightX = cos(radYaw);
		rightZ = sin(radYaw);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		//physics//
		
		RelGravity = Velocity + MovY;
		Velocity = Velocity + Acceleration;
			Acceleration = Acceleration + 0.00001;
		glRotatef(pitch, 1.0f, 0.0f, 0.0f); // pitch
		glRotatef(yaw, 0.0f, 1.0f, 0.0f); // yaw
		glTranslatef(MovX, MovY, MovZ);

		for (int i = 0; i < 999; i++) {
			if (checkCollision(returnBlockPositions(i), (vec3){MovX, MovY + 0.5f, MovZ})) {
				MovY -= 0.005f;
				RelGravity = 0.0f;
				Velocity = 0.0f;
				Acceleration = 0.0f;
				break;
			}
		}

		//checkCollision(returnBlockPositions(999), (vec3){MovX, MovY, MovZ});
		//World gen and Render//

		initBlockTexture();
		renderChunk();

		vec3 blockPos = returnBlockPositions(999);

		if (set == false) {
			MovX = -blockPos.x;
			MovY = -blockPos.y - 2;
			MovZ = -blockPos.z;
			set = true;
		}

		//printf("|Block x: %f | Block y: %f | Block z: %f", blockPos.x, blockPos.y, blockPos.z);

		SDL_GL_SwapWindow(window);

	}
	SDL_GL_DeleteContext(glCONTEXT);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}