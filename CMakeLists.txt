cmake_minimum_required(VERSION 3.21)
project(ESKIMO_JUMPER LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES	   OFF CACHE BOOL "" FORCE)

if (EMSCRIPTEN)
    set(PLATFORM Web CACHE STRING "" FORCE) # -DPLATFORM=Web
endif()

add_subdirectory(_vendor/raylib)

set(SOURCE_FILES
    src/main.cpp
    src/debug.h
    src/debug.cpp
    src/game.h
    src/game.cpp
    src/window.h
    src/window.cpp
    src/statusbar.h
    src/statusbar.cpp
    src/input.h
    src/input.cpp
    src/vec2.h
    src/vec2.cpp
    src/canvas.h
    src/canvas.cpp
    src/assets.h
    src/assets.cpp
    src/text.h
    src/text.cpp
    src/tooltip.h
    src/tooltip.cpp

# refactored
    src/texture.h
    src/texture.cpp

    src/sprite.h
    src/sprite.cpp

    src/padding.h
    src/padding.cpp

    src/buttonbase.h
    src/buttonbase.cpp
    src/buttontext.h
    src/buttontext.cpp
    src/buttontexture.h
    src/buttontexture.cpp

    src/buttongroup.h
    src/buttongroup.cpp

    src/entity.h
    src/entity.cpp
    src/player.h
    src/player.cpp

    src/particle.h
    src/particle.cpp
    src/particlesystem.h
    src/particlesystem.cpp

    src/hitbox.h
    src/hitbox.cpp

    src/maths.h
    src/maths.cpp

    src/sound.h
    src/sound.cpp

    src/animatedsprite.h
    src/animatedsprite.cpp

    src/propsaw.h
    src/propsaw.cpp

    src/tile.h
    src/tile.cpp

)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#target_compile_options(${PROJECT_NAME} PRIVATE -Wall -pedantic)
#target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion)

if (${PLATFORM} STREQUAL "Web")
    # put assets directory relative to build path and use assets/foo.png or ../assets/foo.png for file name in source.cpp
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s WASM=1 -s TOTAL_MEMORY=16777216 -s ASYNCIFY --preload-file ../assets")
    target_link_options(${PROJECT_NAME} PRIVATE -sUSE_GLFW=3 -sWASM=1 -sTOTAL_MEMORY=16777216 -sASYNCIFY --preload-file ../assets)

#    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")

    target_link_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:-s ASSERTIONS=1 --profiling>
        $<$<CONFIG:Release>:--shell-file ${CMAKE_CURRENT_SOURCE_DIR}/shell.html>)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE src/)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

