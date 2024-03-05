
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "../../mmck.h"

void MMCK_Matrices_mult(int m, int n, int k, double *a, int *desc_a, double *b, int *desc_b, double *c, int *desc_c) {





}

void MMCK_Abort(const char *error_string) {
    printf("%s\n", error_string);
    MPI_Abort(program_info.global_comm, -1);
    MMCK_Finalize();
    exit(-1);
}