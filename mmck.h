
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
#define RANK_SORT   ROOT    for(int _rank=0;_rank<session_vars.size;_rank++)


#define INPUT_FILE_METADATA_CARDTY  2
#define REORDER_DEFAULT             0


double *generate(int rows, int cols);

void MMCK_Free_all();

#endif //MMCK_MMCK_H
