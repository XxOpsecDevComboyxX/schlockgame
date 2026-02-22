#include "Chunk.h"
#include "Block.h"
#include <stdio.h>
#include "stb_perlin.h"
int width;
int length;
int height;
vec3 blockPos[999];

void renderChunk() {
	for (width = 0; width < 10; width++) {
		for (length = 0; length < 10; length++) {
			for (height = 0; height < 10; height++) {
				int index = width * 100 + length * 10 + height;
				renderBlock(2.0f * width, 2.0f * height, 2.0f * length);
				blockPos[index].x = 2.0f * width;
				blockPos[index].y = 2.0f * height;
				blockPos[index].z = 2.0f * length;
			}
		}

	}
}

int RandomNoise() {
	float x = 1;
	float y = 1;
	float z = 1;
	int x_wrap = 0;
	int y_wrap = 0;
	int z_wrap = 0;
	int	seed = 12345678;
	
	stb_perlin_noise3_seed(
		x,
		y,
		z,
		x_wrap,
		y_wrap,
		z_wrap,
		seed);
}

vec3 returnBlockPositions(int Block) {
	return blockPos[Block];
}