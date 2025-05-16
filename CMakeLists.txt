cmake_minimum_required(VERSION 3.10)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

# Ruta correcta (usa slashes /, no backslashes)
set(RAYLIB_DIR "C:/raylib/raylib")

include_directories(${RAYLIB_DIR}/src)
link_directories(${RAYLIB_DIR}/src)

add_executable(untitled1 main.cpp Heroe.cpp Enemigo.cpp Sala.cpp Arma.cpp)



target_link_libraries(untitled1 raylib opengl32 gdi32 winmm)
