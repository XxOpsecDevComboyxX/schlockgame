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
			float noise = stb_perlin_noise3(width * 0.1, length * 0.1, 0.1, 0, 0, 0);
			int terrainHeight = (int)((noise + 1.0f) * 5.0f);
			for (height = 0; height < 5; height++) {
				int index = width * 100 + length * 10 + height;
				float yPos = 2.0f * height + terrainHeight *2;
				if (yPos > 10) {
					int blockID = getIndex(2.0f * width, yPos + 2.0f, 2.0f * length);
					vec3 blockBelow = returnBlockData(blockID);
					if (blockBelow.y == (yPos + 2.0f)) {
						renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_DIRT));
					}
					else {
						renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_GRASS));
					}
				}
				else if (yPos > 8) 
				{
					renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_DIRT));
				}
				else
				{
					renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_STONE));
				}
				blockPos[index].x = 2.0f * width;
				blockPos[index].y = yPos;
				blockPos[index].z = 2.0f * length;
			}
		}
	}
}

int getIndex(double x, double y, double z)
{
	for (int i = 0; i < 1000; i++)
	{
		if (blockPos[i].x == x &&
			blockPos[i].y == y &&
			blockPos[i].z == z)
			return i;
	}
	return -1; // not found
}

vec3 returnBlockData(int Block) {
	return blockPos[Block];
}