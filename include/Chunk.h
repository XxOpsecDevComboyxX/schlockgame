#pragma once
#include "Blocks.h"
#include "vec3.h"

typedef struct {
	int x, y, z;
	int index;
	BlockType type;
} Vec3Block;

extern Vec3Block blockPos[10][10][10];

void initChunk();
void renderChunk();
int isSolid(Ivec3 block);
Vec3Block returnBlockData(int x, int y, int z);