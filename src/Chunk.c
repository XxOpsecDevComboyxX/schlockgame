#include "Chunk.h"
#include "Block.h"
#include <stdio.h>
#include "stb_perlin.h"
#include "Blocks.h"

int width;
int length;
int height;
Vec3Block blockPos[9999];

int getIndex(double x, double y, double z);

void renderChunk() {
	for (width = 0; width < 10; width++) {
		for (length = 0; length < 10; length++) {
			float noise = stb_perlin_noise3(width * 0.1, length * 0.1, 0.1, 0, 0, 0);
			int terrainHeight = (int)((noise + 1.0f) * 10.0f);
			for (height = 0; height < 5; height++) {
				BlockType blockAssign;
				int index = width * 100 + length * 10 + height;
				float yPos = 2.0f * height + terrainHeight *2;
				if (yPos > 10) {
					int blockID = getIndex(2.0f * width, yPos + 2.0f, 2.0f * length);
					Vec3Block blockBelow = returnBlockData(blockID);
					if (blockBelow.type == BLOCK_GRASS && blockBelow.y == yPos + 2.0f) {
						renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_DIRT));
						blockAssign = BLOCK_DIRT;
					}
					else {
						renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_GRASS));
						blockAssign = BLOCK_GRASS;
					}
				}
				else if (yPos > 8) 
				{
					renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_DIRT));
					blockAssign = BLOCK_DIRT;
				}
				else
				{
					renderBlock(2.0f * width, yPos, 2.0f * length, getBlockType(BLOCK_STONE));
					blockAssign = BLOCK_STONE;
				}
				blockPos[index].x = 2.0f * width;
				blockPos[index].y = yPos;
				blockPos[index].z = 2.0f * length;
				blockPos[index].type = blockAssign;
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

Vec3Block returnBlockData(int Block) {
	return blockPos[Block];
}