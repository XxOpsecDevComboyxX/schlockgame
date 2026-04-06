#include "vec3.h"
#include "Raycast.h"

#include <math.h>
#include <stdio.h>

#include "Chunk.h"

static Ivec3 worldToBlock(vec3 p) {
    Ivec3 block;
    block.x = (int)(floorf((p.x / 2.0f)));
    block.y = (int)(floorf((p.z / 2.0f)));
    block.z = (int)(floorf((p.y / 2.0f)));
    return block;
}

Ivec3 getLookedAtblock(vec3 camPos, vec3 camDir) {
    float distance = 0.0f;
    Ivec3 none = {0, 0, 0};

    while (distance < 20.0f) {
        Ivec3 block = worldToBlock(camPos);
        printf("%f %f %f\n", block.x, block.y, block.z);
        if (isSolid(block)) {
            return block;
        }

        camPos.x += camDir.x * 0.1f;
        camPos.y += camDir.y * 0.1f;
        camPos.z += camDir.z * 0.1f;

        distance += 0.1f;
    }
    return none;
}