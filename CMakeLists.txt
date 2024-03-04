cmake_minimum_required(VERSION 3.27)
project(mmck C)


find_package(MPI REQUIRED)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER mpicc)

add_executable(mmck
        mmck.h
        src/generator/generator.c
        launcher.c
        src/generator/generator.h
        src/utils/distr.c
        src/utils/distr.h
        src/utils/misc.c
)
