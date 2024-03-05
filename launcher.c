#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "mmck.h"
#include "src/utils/matxutils.h"


int main(int argc, char **argv) {
    // TODO prendere da input
    int m = 3, n = 3, k = 3, mb = 1, nb = 1;

    MPI_Init(&argc, &argv);
    MPI_Comm comm;
    MPI_Comm_dup(MPI_COMM_WORLD, &comm);
    MMCK_Init(comm);

    // TODO nel codice locale c'era una funzione apposita
    double *A = (double *) allocate_mem(m * k * sizeof(double));
    double *B = (double *) allocate_mem(k * n * sizeof(double));
    double *C = (double *) allocate_mem(m * n * sizeof(double));
    generate(m, k, A);
    generate(k, n, B);
    generate(m, n, C);


    int desc_a[DLEN_], desc_b[DLEN_], desc_c[DLEN_];
    int info;
    MMCK_Desc_init(desc_a,
                   m, k,
                   mb, nb,
                   program_info.processes_per_dim[DIM_ROWS], program_info.processes_per_dim[DIM_COLS],
                   0, 0, &info);
    if (info < 0) {
        MMCK_Abort("Could not initialize matrix A descriptor.");
    }

    MMCK_Desc_init(desc_b,
                   k, n,
                   mb, nb,
                   program_info.processes_per_dim[DIM_ROWS], program_info.processes_per_dim[DIM_COLS],
                   0, 0, &info);
    if (info < 0) {
        MMCK_Abort("Could not initialize matrix B descriptor.");
    }

    MMCK_Desc_init(desc_c,
                   m, n,
                   mb, nb,
                   program_info.processes_per_dim[DIM_ROWS], program_info.processes_per_dim[DIM_COLS],
                   0, 0, &info);
    if (info < 0) {
        MMCK_Abort("Could not initialize matrix C descriptor.");
    }


    MMCK_Matrices_mult(m, n, k, A, desc_a, B, desc_b, C, desc_c);
    //for (int i = 0; i < rows * cols; i++) ROOT printf("\n%f ", gen[i]);
    RANK_ECHO
    printf("Terminating...\n");
    MMCK_Finalize();
    MPI_Finalize();


}


