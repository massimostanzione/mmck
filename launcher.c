#include <stdio.h>
#include "mmck.h"

int main(int argc, char **argv) {
    int rows = 3, cols = 3;
    double *gen = generate(rows, cols);
    for (int i = 0; i < rows * cols; i++) printf("%f ", gen[i]);

}