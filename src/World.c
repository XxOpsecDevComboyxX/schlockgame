#include "World.h"
#include "Chunk.h"

int chunks = 2;
int worldInit = 0;

void generateWorld() {
    if (worldInit == 0) {
        for (int i = 1; i < chunks + 1; i++) {
            initChunk(i);
        }
        worldInit = 1;
    }

    renderChunk();
}