#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "mmck.h"

int main(int argc, char **argv) {
    int rows = 3, cols = 3;

    MPI_Init(&argc, &argv);
    MPI_Comm_dup(MPI_COMM_WORLD, &program_info.global_comm);
    MPI_Comm_size(program_info.global_comm, &(program_info.size));
    MPI_Comm_rank(program_info.global_comm, &(process_info.rank));

    // TODO nel codice locale c'era una funzione apposita
    double *gen = (double *) calloc(rows * cols , sizeof(double));
    if (!gen) {
        printf("Won't generate!\n");
        exit(-1);
    }
    generate(rows, cols, gen);
    for (int i = 0; i < rows * cols; i++) ROOT printf("%f ", gen[i]);

    MMCK_Free_all();
    MPI_Finalize();


}