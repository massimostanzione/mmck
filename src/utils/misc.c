#include <mpi.h>
#include "../../mmck.h"

void MMCK_Free_all(){
    MPI_Comm_free(&program_info.global_comm);
    //MPI_Comm_free(&program_info.topology_comm);
}