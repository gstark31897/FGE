cmake_minimum_required(VERSION 2.8)
project(FGE)

set(SOURCE_FILES src/main.cpp src/rendermanager.cpp src/sprite.cpp src/animation.cpp src/combo.cpp src/keyboard.cpp src/event.cpp)
set(CMAKE_CXX_FLAGS "-g")

add_executable(FGE ${SOURCE_FILES})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR} "include/")
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
