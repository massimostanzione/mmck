#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../mmck.h"
#include "../utils/distr.h"

// TODO maggiore randomicità
void generate(int rows, int cols, double *output) {
    int max = 30, min = -30;

    // FIXME disparità processi/numero righe
    int count = rows * distribute_cols_count(rows, cols); //rows * (cols / (program_info.size));
    double *part = (double *) malloc(count * sizeof(double));
    if (!part) {
        printf("Won't generate!\n");
        exit(-1);
    }
    for (int i = 0; i < count; i++) {
        part[i] = rand() % (max + 1 - min) + min;
        //RANK_ECHO printf("%f ", part[i]);
    }
    //for (int i = 0; i < rows * cols; i++)  printf("%f ", part[i]);
    /* double *ret = (double *) malloc(rows * cols * sizeof(double));
     if (!ret) {
         printf("Won't generate!\n");
         exit(-1);
     }
     /*   for (int i = 0; i < rows * cols; i++)
            ret[i] = rand() % (max + 1 - min) + min;
     */
    MPI_Barrier(program_info.global_comm);
    MPI_Allgather(part, count, MPI_DOUBLE,
                  output, count, MPI_DOUBLE,
                  program_info.global_comm);
}
