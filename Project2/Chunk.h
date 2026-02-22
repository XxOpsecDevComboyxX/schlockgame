#pragma once

typedef struct {
	float x, y, z;
} vec3;

extern vec3 blockPos[999];

void renderChunk();
vec3 returnBlockPositions(int Block);