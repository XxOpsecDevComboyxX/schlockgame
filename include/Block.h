#pragma once
#include "Blocks.h"

void initBlockTextures();
void cleanupBlockTextures();
void renderBlock(float x, float y, float z, Block* block);