#include "Chunk.h"
#include "Block.h"

int width;
int length;
int height;

void renderChunk() {
	for (width = 0; width <= 10; width++) {
		for (length = 0; length <= 10; length++) {
			for (height = 0; height <= 10; height++) {
				renderBlock(2.0f * width, 2.0f * height, 2.0f * length);
			}
		}

	}
}