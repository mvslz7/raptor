cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "-O3")
set(CMAKE_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

project(raptor)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Include directories
include_directories(./src/)
include_directories(./include/textscreen/include/)
include_directories(./include/TinySoundFont/)

# Add subdirectory for textscreen
add_subdirectory(./include/textscreen/include)

# Source files
add_executable(${CMAKE_PROJECT_NAME}
    # Core
    src/core/rap.cpp
    src/core/m_misc.cpp

    # Assets
    src/assets/glbapi.cpp

    # Audio
    src/audio/mpualsa.cpp
    src/audio/mpucorea.cpp
    src/audio/mpucorem.cpp
    src/audio/mputsf.cpp
    src/audio/mpuwinmm.cpp
    src/audio/opl3.cpp
    src/audio/musapi.cpp
    src/audio/i_oplmusic.cpp
    src/audio/gssapi.cpp
    src/audio/fx.cpp

    # Entities
    src/entities/bonus.cpp
    src/entities/enemy.cpp
    src/entities/eshot.cpp
    src/entities/objects.cpp
    src/entities/shots.cpp

    # Gameplay
    src/gameplay/anims.cpp
    src/gameplay/loadsave.cpp
    src/gameplay/store.cpp

    # Graphics
    src/graphics/gfxapi.cpp
    src/graphics/gfxapi_a.cpp
    src/graphics/intro.cpp
    src/graphics/help.cpp
    src/graphics/shadow.cpp
    src/graphics/flame.cpp
    src/graphics/swdapi.cpp

    # Input
    src/input/imsapi.cpp
    src/input/input.cpp
    src/input/kbdapi.cpp
    src/input/joyapi.cpp
    src/input/ptrapi.cpp
    src/input/ptrapi_a.cpp

    # Media
    src/media/i_video.cpp
    src/media/i_lastscr.cpp
    src/media/movia_a.cpp
    src/media/movie.cpp

    # Utils
    src/utils/prefapi.cpp
    src/utils/vmemapi.cpp
    src/utils/dspapi.cpp

    src/demo.cpp
    src/tile.cpp
    src/tile_a.cpp
    src/windows.cpp
)

# Link libraries
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(ALSA REQUIRED)
    target_link_libraries(raptor
        textscreen
        asound
        SDL2::SDL2
        SDL2::SDL2main
    )
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    find_library(AUDIO_TOOLBOX AudioToolbox)
    find_library(AUDIO_UNIT AudioUnit)
    find_library(FOUNDATION_LIBRARY Foundation)
    find_library(COREMIDI_LIB CoreMIDI)
    target_link_libraries(raptor
        textscreen
        ${AUDIO_TOOLBOX}
        ${AUDIO_UNIT}
        ${FOUNDATION_LIBRARY}
        ${COREMIDI_LIB}
        SDL2::SDL2
        SDL2::SDL2main
    )
endif()
