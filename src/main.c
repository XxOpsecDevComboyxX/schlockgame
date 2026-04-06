#include "Raycast.h"
#ifdef _WIN32
#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#elif defined(__linux__)
#include <unistd.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include "Block.h"
#include "Chunk.h"
#include "Collision.h"
#include <stdbool.h>
#include "stb_image.h"
#include "Blocks.h"
#include "vec3.h"
#include "Raycast.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return 1;

	SDL_Window* window = SDL_CreateWindow(
		"SDL2 Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280,
		1024,
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

	Uint32 lastTime = SDL_GetTicks();

	int chunkinit = 0;
	
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

	vec3 camPos = {};
	vec3 camDir = {};

	Ivec3 currentBlock;

	float dt = 0;

	float moveSpeed = 50.0f;

	const GLubyte* version = glGetString(GL_VERSION);
	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);

	bool set = false;

	printf("OpenGL Version: %s\n", version);
	printf("OpenGL Vendor: %s\n", vendor);
	printf("OpenGL Renderer: %s\n", renderer);

	while (running)
	{
		dt = (SDL_GetTicks() - lastTime) / 1000.0f;
		lastTime = SDL_GetTicks();

		// printf("Delta Time: %f seconds\n", dt);

		const Uint8* keystate = SDL_GetKeyboardState(NULL);

		if (keystate[SDL_SCANCODE_W]) {
			MovX -= dirX * moveSpeed * dt;
			MovZ -= dirZ * moveSpeed * dt;
			MovY += dirY * moveSpeed * dt;
		}

		if (keystate[SDL_SCANCODE_S]) {
			MovX += dirX * moveSpeed * dt;
			MovZ += dirZ * moveSpeed * dt;
			MovY -= dirY * moveSpeed * dt;
		}

		if (keystate[SDL_SCANCODE_D]) {
			MovX -= rightX * moveSpeed * dt;
			MovZ -= rightZ * moveSpeed * dt;
		}

		if (keystate[SDL_SCANCODE_Q]) {
			running = 0;
			return 0;
		}

		if (keystate[SDL_SCANCODE_A]) {
			MovX += rightX * moveSpeed * dt;
			MovZ += rightZ * moveSpeed * dt;
			printf("%f\n", MovX);
		}

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;

			//camera rotation
			if (event.type == SDL_MOUSEMOTION)
			{

				yaw += event.motion.xrel * 0.1f;
				pitch += event.motion.yrel * 0.1f;
				if (pitch > 89.0f) pitch = 89.0f;
				if (pitch < -89.0f) pitch = -89.0f;
			}

			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) {
					currentBlock = getLookedAtblock(camPos, camDir);
					if (isSolid(currentBlock)) {
						Vec3Block latestBlock = returnBlockData(currentBlock.x, currentBlock.y, currentBlock.z);
						blockPos[currentBlock.x][currentBlock.y][currentBlock.z].type = BLOCK_AIR;
					}
				}
			}
		}

		radYaw = yaw * M_PI / 180.0f;
		radPitch = pitch * M_PI / 180.0f;
		dirX = cos(radPitch) * sin(radYaw);
		dirY = sin(radPitch);
		dirZ = -cos(radPitch) * cos(radYaw);

		rightX = cos(radYaw);
		rightZ = sin(radYaw);

		camPos.x = -MovX;
		camPos.y = -MovY;
		camPos.z = -MovZ;

		camDir.x = dirX;
		camDir.y = dirY;
		camDir.z = dirZ;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		//physics//

		glRotatef(pitch, 1.0f, 0.0f, 0.0f); // pitch
		glRotatef(yaw, 0.0f, 1.0f, 0.0f); // yaw

		// for (int i = 0; i < 1000; i++) {
		// 	Vec3Block blockPos = returnBlockData(i);
		// 	if (checkCollision(blockPos, (vec3){MovX, MovY + 4.0f, MovZ})) {
		// 		MovY = -blockPos.y - 4.0f;
		// 		RelGravity = 0.0f;
		// 		Velocity = 0.0f;
		// 		Acceleration = 0.0f;
		// 		break;
		// 	}
		// }

		glTranslatef(MovX, MovY, MovZ);

		//World gen and Render//

		if (chunkinit == 0) {
			initChunk();
			chunkinit = 1;
		}

		initBlockTextures();
		renderChunk();
		cleanupBlockTextures();

		Vec3Block blockPos1 = returnBlockData(4, 5, 6);

		if (set == false) {
			MovX = -blockPos1.x;
			MovY = -blockPos1.y;
			MovZ = -blockPos1.z;
			set = true;
		}

		// RAYCAST LOGIC
		SDL_GL_SwapWindow(window);

	}
	SDL_GL_DeleteContext(glCONTEXT);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
