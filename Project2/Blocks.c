#include "Blocks.h"
#include "stb_image.h"

static Block blockTypes[BLOCK_COUNT] = {
	{ BLOCK_GRASS, 1, "grass_side.png", "grass_top.png", 0, 0},
	{ BLOCK_STONE, 1, "stone.png", "stone.png", 0, 0},
    { BLOCK_DIRT, 1, "dirt.png", "dirt.png", 0, 0},
    { BLOCK_MISSING, 1, "missing.png", "missing.png", 0, 0},
};

Block* getBlockType(BlockType type) {
	if (type < BLOCK_COUNT)
		return &blockTypes[type];
	return &blockTypes[BLOCK_MISSING];
}

GLuint loadTexture(const char* filename) {
    int width, height, channels;
    stbi_set_flip_vertically_on_load(1);
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    if (!image) {
        return 0;
    }
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    stbi_image_free(image);
    return textureID;
}

void initBlockTextures() {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        Block* block = getBlockType(i);
        block->textureID = loadTexture(block->texturePath);
        block->topTextureID = loadTexture(block->topTexturePath);
    }
}

void cleanupBlockTextures() {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        Block* block = getBlockType(i);
        glDeleteTextures(1, &block->textureID);
        glDeleteTextures(1, &block->topTextureID);
    }
}