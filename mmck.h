
#ifndef MMCK_MMCK_H
#define MMCK_MMCK_H

#include <mpi.h>
#include "src/generator/generator.h"

#define DIMS_CARDTY 2
#define DIM_ROWS    0
#define DIM_COLS    1

#define MATRIX_INIT_DATA  0

/*
 * Mantain some MPI-specific variables into a single place, instead of having them scattered into the code.
 * Could be useful or not depending on what the code needs to do.
 */
typedef struct MMCK_MPI_Program_Info_t {
    int size;
    MPI_Comm global_comm;
    MPI_Comm topology_comm;
    int processes_per_dim[DIMS_CARDTY];
} MMCK_MPI_Program_Info;
MMCK_MPI_Program_Info program_info;

typedef struct MMCK_MPI_Process_Info_t {
    int rank;
    int coord_x;
    int coord_y;
} MMCK_MPI_Process_Info;
MMCK_MPI_Process_Info process_info;

/*
 * assuming root id is zero
 */
#define ROOT_RANK     0

/*
 * assuming a "process_info" struct variable is declared and named like that
 */
#define RANK(r)     if (process_info.rank == r)
#define ROOT        RANK(ROOT_RANK)
#define NON_ROOT    if (process_info.rank  > ROOT_RANK)
#define RANK_ECHO   ROOT        printf("[ROOT   ] ");                       \
                    NON_ROOT    printf("[proc. %d] ", process_info.rank);
#define RANK_SORT   ROOT    for(int _rank=0;_rank<program_info.size;_rank++) if(process_info.rank==_rank)


#define INPUT_FILE_METADATA_CARDTY  2
#define REORDER_DEFAULT             0


void MMCK_Init(MPI_Comm comm);
void generate(int rows, int cols, double *output);

void MMCK_Matrices_mult(int m, int n, int k, double *a, int *desc_a, double *b, int *desc_b, double *c, int *desc_c);

//FIXME non qui
void *allocate_mem(unsigned long count);

void MMCK_Finalize();

void MMCK_Abort(const char *error_string);

#endif //MMCK_MMCK_H
