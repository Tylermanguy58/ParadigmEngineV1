cmake_minimum_required(VERSION 3.28.3)
project(PARADIGM_ENGINE CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL_SHARED OFF CACHE BOOL "Build shared library" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build static library" FORCE)

add_subdirectory(external/SDL3)

add_library(entt INTERFACE)
target_include_directories(entt INTERFACE external/entt/src)

#internal libraries

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/internal)

add_library(paradigm_physics STATIC internal/paradigm_physics/src/paradigm_physics.cpp)
target_include_directories(paradigm_physics PUBLIC internal/paradigm_physics/include)

add_library(linear_algebra STATIC internal/linear_algebra/src/linear_algebra.cpp)
target_include_directories(linear_algebra PUBLIC internal/linear_algebra/include)

file(GLOB ENGINE_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${ENGINE_SOURCES})

target_link_libraries(${PROJECT_NAME} 
	PRIVATE 
		paradigm_physics
		linear_algebra
		SDL3-static
		entt
)
