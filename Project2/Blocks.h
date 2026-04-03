#pragma once
#include <stdint.h>
#ifdef _WIN32
#include <windows.h>
#include <gl\GL.h>
#elif defined(__linux__)
#include <unistd.h>
#include <gl.h>
#endif

typedef enum {
	BLOCK_GRASS,
	BLOCK_STONE,
	BLOCK_DIRT,
	BLOCK_MISSING,
	BLOCK_COUNT
} BlockType;

typedef struct {
	BlockType type;
	uint8_t isSolid;
	const char* texturePath;
	const char* topTexturePath;
	GLuint textureID;
	GLuint topTextureID;
} Block;

Block* getBlockType(BlockType type);

void initBlockTextures(void);
void cleanupBlockTextures(void);