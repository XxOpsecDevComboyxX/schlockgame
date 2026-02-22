#include "chunk.h"
#include <stdio.h>

int checkCollision(vec3 blockPosition, vec3 playerPosition) {
	if (playerPosition.x >= -blockPosition.x - 1.0f && playerPosition.x <= -blockPosition.x + 1.0f &&
		playerPosition.y >= -blockPosition.y - 1.0f && playerPosition.y <= -blockPosition.y + 1.0f &&
		playerPosition.z >= -blockPosition.z - 1.0f && playerPosition.z <= -blockPosition.z + 1.0f) {
		printf("COLLIDED WITH BLOCK AT: %f, %f, %f\n", -blockPosition.x, -blockPosition.y, -blockPosition.z);
		return 1; // Collision detected
	}
	return 0; // No collision
}