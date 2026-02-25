#pragma once
#include "Blocks.h"

typedef struct {
	float x, y, z;
	//BlockType type;
} vec3;

extern vec3 blockPos[999];

void renderChunk();
vec3 returnBlockData(int Block);