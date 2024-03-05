#include <mpi.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../mmck.h"

void MMCK_Finalize() {
    if (program_info.global_comm != NULL) MPI_Comm_free(&program_info.global_comm);
    if (program_info.topology_comm != NULL) MPI_Comm_free(&program_info.topology_comm);
}

//matxutils?
void *allocate_mem(unsigned long count) {
    void *ptr;
    ptr = malloc(count);
    if (ptr == NULL) {
        MMCK_Abort("Error while allocating memory (malloc).");
    }
    memset(ptr, MATRIX_INIT_DATA, count);
    if (ptr == NULL) {
        MMCK_Abort("Error while populating memory (memset).");
    }
    return ptr;
}
