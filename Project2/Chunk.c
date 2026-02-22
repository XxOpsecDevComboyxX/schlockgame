#include "Chunk.h"
#include "Block.h"
#include <stdio.h>
#include "stb_perlin.h"
#include "Blocks.h"

int width;
int length;
int height;
vec3 blockPos[999];

void renderChunk() {
	for (width = 0; width < 10; width++) {
		for (length = 0; length < 10; length++) {
			for (height = 0; height < 3; height++) {
				int index = width * 100 + length * 10 + height;

				int heightmulti = 15;
				float noise = stb_perlin_noise3(width * 0.1, length * 0.1, 0.1, 0, 0, 0);
				float i = noise * heightmulti;
				int r = (int)i;
				float yPos = 2.0f * height + r *2;
				renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_GRASS));
				blockPos[index].x = 2.0f * width;
				blockPos[index].y = yPos;
				blockPos[index].z = 2.0f * length;
			}
		}

	}
}

vec3 returnBlockPositions(int Block) {
	return blockPos[Block];
}