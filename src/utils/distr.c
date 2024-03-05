#include <mpi.h>
#include <stdio.h>
#include "distr.h"
#include "../../mmck.h"

int distribute_cols_count(int cols_no) {
    int base_cols = cols_no / program_info.size;
    int spare_cols = cols_no % program_info.size;
    return process_info.rank < spare_cols ? ++base_cols : base_cols;
}

void distribute(double *input, double *output) {

    MPI_Datatype distrtype;

    // TODO in ciclo?
    // original matrix dimensions
    int gsize_array[DIMS_CARDTY] = {3, 3};

    // distribution mode array
    int distrib_array[DIMS_CARDTY] = {MPI_DISTRIBUTE_CYCLIC, MPI_DISTRIBUTE_CYCLIC};

    // block dimensions
    int darg_array[DIMS_CARDTY] = {3, 1};

    // process grid per dimension
    int psize_array[DIMS_CARDTY] = {3, 1};

    MPI_Type_create_darray(program_info.size, process_info.rank, DIMS_CARDTY,
                           gsize_array, distrib_array,
                           darg_array, psize_array,
                           MPI_ORDER_C,
                           MPI_DOUBLE, &distrtype);
    MPI_Type_commit(&distrtype);

    MPI_Scatter(input, 3, MPI_DOUBLE,
                output, 3, distrtype,
                ROOT_RANK, program_info.global_comm);

    MPI_Type_free(&distrtype);

}
