#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../mmck.h"
#include "../utils/distr.h"

void generate(int rows, int cols, double *output) {
    int max = 30, min = -30;

    // generating by columns
    int elements_count = rows * distribute_cols_count(cols);

    // allocate memory for generating random values, according to the count of the elements to be generated
    double *part = (double *) malloc(elements_count * sizeof(double));
    if (!part) {
        printf("Won't generate!\n");
        exit(-1);
    }

    // generate random values
    // TODO maggiore randomicità
    for (int i = 0; i < elements_count; i++) {
        part[i] = rand() % (max + 1 - min) + min;
    }

    // cpmute recvcounts ----------------------------------------
    int recvcounts[program_info.size];
    MPI_Allgather(&elements_count, 1, MPI_INT,
                  recvcounts, 1, MPI_INT,
                  program_info.global_comm);

    // compute displs --------------------------------------------
    int local_displ = 0;
    int displs[program_info.size];

    for (int i = 0; i < process_info.rank; i++) local_displ += recvcounts[i];

    MPI_Allgather(&local_displ, 1, MPI_INT,
                  displs, 1, MPI_INT,
                  program_info.global_comm);

    // gather the complete matrix from all the processes
    MPI_Allgatherv(part, elements_count, MPI_DOUBLE,
                   output, recvcounts, displs, MPI_DOUBLE,
                   program_info.global_comm);
}
