#include "Chunk.h"
#include "Block.h"
#include <stdio.h>
#include "stb_perlin.h"
#include "Blocks.h"
#include "vec3.h"

int width;
int length;
int height;
Vec3Block blockPos[10][10][10];

int countedBlocks = 0;

int init = 0;

Vec3Block getBlockByIndex(int index);

void initChunk() {
	countedBlocks = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				countedBlocks++;
				if (k >= 3.0f) {
					blockPos[i][j][k].type = BLOCK_STONE;
					blockPos[i][j][k].x = 2.0f * i;
					blockPos[i][j][k].y = 2.0f * k;
					blockPos[i][j][k].z = 2.0f * j;
					blockPos[i][j][k].index = countedBlocks;
				} else if (k >= 2.0f) {
					blockPos[i][j][k].type = BLOCK_GRASS;
					blockPos[i][j][k].x = 2.0f * i;
					blockPos[i][j][k].y = 2.0f * k;
					blockPos[i][j][k].z = 2.0f * j;
					blockPos[i][j][k].index = countedBlocks;
				} else {
					blockPos[i][j][k].type = BLOCK_DIRT;
					blockPos[i][j][k].x = 2.0f * i;
					blockPos[i][j][k].y = 2.0f * k;
					blockPos[i][j][k].z = 2.0f * j;
					blockPos[i][j][k].index = countedBlocks;
				}
			}
		}
	}
}

void renderChunk() {
	for (int i = 1; i <= countedBlocks; i++) {
		Vec3Block newBlock = getBlockByIndex(i);
		renderBlock(newBlock.x, newBlock.y, newBlock.z, getBlockType(newBlock.type));
	}
}

int isSolid(Ivec3 block) {
	if (block.x < 0 || block.x >= 10) return 0;
	if (block.y < 0 || block.y >= 10) return 0;
	if (block.z < 0 || block.z >= 10) return 0;

	return blockPos[block.x][block.y][block.z].type != BLOCK_AIR;
}

Vec3Block returnBlockData(int x, int y, int z) {
	 // printf("index: %d ", blockPos[x][y][z].index);
	return blockPos[x][y][z];
}

Vec3Block getBlockByIndex(int index) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (blockPos[i][j][k].index == index) {
					return blockPos[i][j][k];
				}
			}
		}
	}
}
