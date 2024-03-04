#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// TODO maggiore randomicità
// TODO generare in parallelo
double *generate(int rows, int cols) {
    int max = 30, min = -30;
    double *ret = (double *) malloc(rows * cols * sizeof(double));
    if (!ret) {
        printf("Won't generate!\n");
        exit(-1);
    }
    for (int i = 0; i < rows * cols; i++)
        ret[i] = rand() % (max + 1 - min) + min;

    return ret;
}
