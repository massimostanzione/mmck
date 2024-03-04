cmake_minimum_required(VERSION 3.27)
project(mmck C)

set(CMAKE_C_STANDARD 11)

add_executable(mmck
        src/generator/generator.c
        src/utils/matrixutils.c
        src/utils/matrixutils.h
        launcher.c
        src/generator/generator.h
        mmck.h
)
