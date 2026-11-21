cmake_minimum_required(VERSION 3.20)

project(ChessEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download raylib automatically
include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

add_executable(ChessEngine
        src/main.cpp
        src/chess/LoadBoard.cpp
        src/chess/DrawPiece.cpp
        src/chess/MovePiece.cpp
)

target_include_directories(ChessEngine PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(ChessEngine PRIVATE raylib)