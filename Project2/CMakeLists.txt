cmake_minimum_required(VERSION 3.10)
project(Project2 C)

set(SOURCES
    main.c
    Block.c
    Blocks.c
    Chunk.c
    Collision.c
    stb.c
)

add_executable(Project2 ${SOURCES})

if(WIN32)
    # Windows: custom SDL2 paths
    target_include_directories(Project2 PRIVATE C:/ProjectFiles/include)
    target_link_directories(Project2 PRIVATE C:/ProjectFiles/lib/x86)
    target_link_libraries(Project2 SDL2main SDL2 opengl32 glu32)
elseif(UNIX AND NOT APPLE)
    # Linux: use find_package
    find_package(SDL2 REQUIRED)
    find_package(OpenGL REQUIRED)
    target_link_libraries(Project2 SDL2::SDL2 OpenGL::GL OpenGL::GLU)
endif()