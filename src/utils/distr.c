#include <mpi.h>
#include "distr.h"
#include "../../mmck.h"

void distribute(double* input, double *output){
/*
    MPI_Datatype distrtype;

    // TODO in ciclo?
    // original matrix dimensions
    int gsize_array[DIMS_CARDTY]={3,3};

    // distribution mode array
    int distrib_array[DIMS_CARDTY]={MPI_DISTRIBUTE_CYCLIC, MPI_DISTRIBUTE_CYCLIC};

    // block dimensions
    int darg_array[DIMS_CARDTY]={};

    // process grid per dimension
    int psize_array[DIMS_CARDTY]={};

    MPI_Type_create_darray(program_info.size, process_info.rank, DIMS_CARDTY,
                           gsize_array, distrib_array,
                           darg_array, psize_array,
                           MPI_ORDER_C,
                           MPI_DOUBLE, &distrtype);
    MPI_Type_commit(&distrtype);

    MPI_Scatter(input, sendcount, MPI_DOUBLE,
                output, recvcount, distrtype,
                ROOT_RANK, comm);

    MPI_Type_free(&distrtype);
    */
}