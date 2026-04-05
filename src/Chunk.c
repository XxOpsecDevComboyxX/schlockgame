#include "Chunk.h"
#include "Block.h"
#include <stdio.h>
#include "stb_perlin.h"
#include "Blocks.h"

int width;
int length;
int height;
Vec3Block blockPos[10][10][10];

int countedBlocks = 0;

void renderChunk() {
	countedBlocks = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				countedBlocks++;
				if (k >= 3.0f) {
					blockPos[i][j][k].type = BLOCK_AIR;
					blockPos[i][j][k].x = i;
					blockPos[i][j][k].y = j;
					blockPos[i][j][k].z = k;
					blockPos[i][j][k].index = countedBlocks;
					renderBlock(2.0f * i, 2.0f * k, 2.0f * j, getBlockType(BLOCK_AIR));
				} else if (k >= 2.0f) {
					blockPos[i][j][k].type = BLOCK_GRASS;
					blockPos[i][j][k].x = i;
					blockPos[i][j][k].y = j;
					blockPos[i][j][k].z = k;
					blockPos[i][j][k].index = countedBlocks;
					renderBlock(2.0f * i, 2.0f * k, 2.0f * j, getBlockType(BLOCK_GRASS));
				} else {
					blockPos[i][j][k].type = BLOCK_DIRT;
					blockPos[i][j][k].x = i;
					blockPos[i][j][k].y = j;
					blockPos[i][j][k].z = k;
					blockPos[i][j][k].index = countedBlocks;
					renderBlock(2.0f * i, 2.0f * k, 2.0f * j, getBlockType(BLOCK_DIRT));
				}
			}
		}
	}
}

Vec3Block returnBlockData(int x, int y, int z) {
	 // printf("index: %d ", blockPos[x][y][z].index);
	return blockPos[x][y][z];
}