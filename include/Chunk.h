#pragma once
#include "Blocks.h"

typedef struct {
	int x, y, z;
	int index;
	BlockType type;
} Vec3Block;

extern Vec3Block blockPos[10][10][10];

void renderChunk();
Vec3Block returnBlockData(int x, int y, int z);