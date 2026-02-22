#include "Chunk.h"
#include "Block.h"
#include <stdio.h>

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
vec3 ReturnBlockIndex(float blockX,float blockY,float blockZ) {
	
}


vec3 returnBlockPositions(int Block) {
	return blockPos[Block];
}