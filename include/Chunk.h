#pragma once
#include "Blocks.h"

typedef struct {
	int x, y, z;
	BlockType type;
} Vec3Block;

extern Vec3Block blockPos[9999];

void renderChunk();
Vec3Block returnBlockData(int Block);