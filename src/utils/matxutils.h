
#ifndef MMCK_MATXUTILS_H
#define MMCK_MATXUTILS_H

// matrix descriptor fields (ScaLAPACK - compliant)
// from PBTools.h, rows 10 - 31, see https://netlib.org/scalapack/explore-html/da/d28/_p_btools_8h_source.html#l00010
/*
*  This file includes PBLAS tools definitions. All PBLAS routines include
*  this file.
*
* ----------------------------------------------------------------------
*  #define macro constants
*  ---------------------------------------------------------------------
*
*  Descriptor entries for type 1
*/
#define    BLOCK_CYCLIC_2D     1

#define    DTYPE_             0                   /* Descriptor Type */
#define    CTXT_              1                     /* BLACS context */
#define    M_                 2             /* Global Number of Rows */
#define    N_                 3          /* Global Number of Columns */
#define    MB_                4                 /* Row Blocking Size */
#define    NB_                5              /* Column Blocking Size */
#define    RSRC_              6            /* Starting Processor Row */
#define    CSRC_              7         /* Starting Processor Column */
#define    LLD_               8           /* Local Leading Dimension */
#define    DLEN_              9                 /* Descriptor Length */

#define UNUSED_SCALAPACK_PARAM  0

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

void MMCK_Desc_init(int *desc, int m, int n, int mb, int nb, int irsrc, int icsrc, int ictxt, int lld, int *info);


#endif //MMCK_MATXUTILS_H
