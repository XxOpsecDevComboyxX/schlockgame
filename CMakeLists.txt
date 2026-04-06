cmake_minimum_required(VERSION 3.25)
project(untitled C)

set(CMAKE_C_STANDARD 17)

set(SOURCES src/main.c src/Block.c src/Blocks.c src/Chunk.c src/Collision.c src/stb.c
        src/Raycast.c
        )

set(HEADERS include/Blocks.h include/stb_image.h include/stb_perlin.h include/Block.h include/Collision.h include/vec3.h include/Chunk.h include/Raycast.h)
add_executable(untitled ${SOURCES} ${HEADERS})

if(WIN32)
set(SDL2_PATH "C:/ProjectFiles")
target_include_directories(untitled PRIVATE include ${SDL2_PATH}/include/SDL2)
target_link_libraries(untitled PRIVATE ${SDL2_PATH}/lib/libSDL2main.a ${SDL2_PATH}/lib/libSDL2.a opengl32 glu32 mingw32 setupapi imm32 winmm version ole32 oleaut32 shell32 gdi32 user32 uuid dinput8 dxguid -static-libgcc -static-libstdc++)
elseif(UNIX AND NOT APPLE)
    find_package(SDL2 REQUIRED)
    target_include_directories(untitled PRIVATE include ${SDL2_INCLUDE_DIRS})
    target_link_libraries(untitled PRIVATE SDL2::SDL2 SDL2::SDL2main GL GLU m)
endif ()