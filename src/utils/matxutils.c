
#include "matxutils.h"
#include "../../mmck.h"
#include <stdlib.h>

void MMCK_Desc_init(int *desc, int m, int n, int mb, int nb, int irsrc, int icsrc, int ictxt, int lld, int *info) {
/*
desc( dtype_ ) = block_cyclic_2d
desc( m_ )  = max( 0, m )
desc( n_ )  = max( 0, n )
desc( mb_ ) = max( 1, mb )
desc( nb_ ) = max( 1, nb )
desc( rsrc_ ) = max( 0, min( irsrc, nprow-1 ) )
desc( csrc_ ) = max( 0, min( icsrc, npcol-1 ) )
desc( ctxt_ ) = ictxt
desc( lld_ )  = max( lld, max( 1, numroc( desc( m_ ), desc( mb_ ),
                                          $                              myrow, desc( rsrc_ ), nprow ) ) )
*/
    *info = -1;
    desc[DTYPE_] = BLOCK_CYCLIC_2D;
    desc[M_] = max(0, m);
    desc[N_] = max(0, n);
    desc[MB_] = max(1, mb);
    desc[MB_] = max(1, nb);
    desc[RSRC_] = max(0, min(irsrc, program_info.processes_per_dim[DIM_ROWS]));
    desc[CSRC_] = max(0, min(irsrc, program_info.processes_per_dim[DIM_COLS]));
    desc[CTXT_] = UNUSED_SCALAPACK_PARAM;
    desc[LLD_] = UNUSED_SCALAPACK_PARAM;
    *info = 0;
}