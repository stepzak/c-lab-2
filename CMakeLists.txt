cmake_minimum_required(VERSION 3.30)
project(lab3 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab3 main.c
        dichometry.c
        dichometry.h
        types.h
        newton.c
        newton.h
        iteration.c
        my_math.h
        my_math.c
)

target_link_libraries(lab3 m)
