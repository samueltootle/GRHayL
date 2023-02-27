// NRPy+ basic definitions, automatically generated from outC_NRPy_basic_defines_h_dict within outputC,
//    and populated within NRPy+ modules. DO NOT EDIT THIS FILE BY HAND.

// construct_NRPy_basic_defines_h(...,enable_SIMD=True) was called so we #include SIMD intrinsics:
#include "SIMD/SIMD_intrinsics.h"


//********************************************
// Basic definitions for module outputC:

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h" // "string.h Needed for strncmp, etc.
#include "stdint.h" // "stdint.h" Needed for Windows GCC 6.x compatibility, and for int8_t


#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502884L
#endif
#ifndef M_SQRT1_2
#define M_SQRT1_2 0.707106781186547524400844362104849039L
#endif

#ifndef MIN
#define MIN(A, B) ( ((A) < (B)) ? (A) : (B) )
#endif
#ifndef MAX
#define MAX(A, B) ( ((A) > (B)) ? (A) : (B) )
#endif

#ifdef __cplusplus
#define restrict __restrict__
#endif
#define REAL double
//********************************************


//********************************************
// Basic definitions for module NRPy_param_funcs:
typedef struct __paramstruct__ {
  REAL Cart_CoM_offsetx;  // grid::Cart_CoM_offsetx
  REAL Cart_CoM_offsety;  // grid::Cart_CoM_offsety
  REAL Cart_CoM_offsetz;  // grid::Cart_CoM_offsetz
  REAL Cart_originx;  // grid::Cart_originx
  REAL Cart_originy;  // grid::Cart_originy
  REAL Cart_originz;  // grid::Cart_originz
  REAL GAMMA_SPEED_LIMIT;  // GRMHD_equations_new_version::GAMMA_SPEED_LIMIT
  REAL RHOMAX;  // reference_metric::RHOMAX
  REAL TINYDOUBLE;  // Min_Max_and_Piecewise_Expressions::TINYDOUBLE
  REAL ZMAX;  // reference_metric::ZMAX
  REAL ZMIN;  // reference_metric::ZMIN
  REAL dxx0;  // grid::dxx0
  REAL dxx1;  // grid::dxx1
  REAL dxx2;  // grid::dxx2
  REAL f0_of_xx0;  // reference_metric::f0_of_xx0
  REAL f0_of_xx0__D0;  // reference_metric::f0_of_xx0__D0
  REAL f0_of_xx0__DD00;  // reference_metric::f0_of_xx0__DD00
  REAL f0_of_xx0__DDD000;  // reference_metric::f0_of_xx0__DDD000
  REAL f1_of_xx1;  // reference_metric::f1_of_xx1
  REAL f1_of_xx1__D1;  // reference_metric::f1_of_xx1__D1
  REAL f1_of_xx1__DD11;  // reference_metric::f1_of_xx1__DD11
  REAL f1_of_xx1__DDD111;  // reference_metric::f1_of_xx1__DDD111
  REAL f2_of_xx0_xx1;  // reference_metric::f2_of_xx0_xx1
  REAL f2_of_xx0_xx1__D0;  // reference_metric::f2_of_xx0_xx1__D0
  REAL f2_of_xx0_xx1__D1;  // reference_metric::f2_of_xx0_xx1__D1
  REAL f2_of_xx0_xx1__DD00;  // reference_metric::f2_of_xx0_xx1__DD00
  REAL f2_of_xx0_xx1__DD11;  // reference_metric::f2_of_xx0_xx1__DD11
  REAL f2_of_xx1;  // reference_metric::f2_of_xx1
  REAL f2_of_xx1__D1;  // reference_metric::f2_of_xx1__D1
  REAL f2_of_xx1__DD11;  // reference_metric::f2_of_xx1__DD11
  REAL f2_of_xx1__DDD111;  // reference_metric::f2_of_xx1__DDD111
  REAL f3_of_xx0;  // reference_metric::f3_of_xx0
  REAL f3_of_xx0__D0;  // reference_metric::f3_of_xx0__D0
  REAL f3_of_xx0__DD00;  // reference_metric::f3_of_xx0__DD00
  REAL f4_of_xx2;  // reference_metric::f4_of_xx2
  REAL f4_of_xx2__D2;  // reference_metric::f4_of_xx2__D2
  REAL f4_of_xx2__DD22;  // reference_metric::f4_of_xx2__DD22
  REAL invdx0;  // grid::invdx0
  REAL invdx1;  // grid::invdx1
  REAL invdx2;  // grid::invdx2
  REAL sqrt4pi;  // __main__::sqrt4pi
  REAL xmax;  // reference_metric::xmax
  REAL xmin;  // reference_metric::xmin
  REAL xx0;  // grid::xx0
  REAL xx1;  // grid::xx1
  REAL xx2;  // grid::xx2
  REAL xxmax0;  // grid::xxmax0
  REAL xxmax1;  // grid::xxmax1
  REAL xxmax2;  // grid::xxmax2
  REAL xxmin0;  // grid::xxmin0
  REAL xxmin1;  // grid::xxmin1
  REAL xxmin2;  // grid::xxmin2
  REAL ymax;  // reference_metric::ymax
  REAL ymin;  // reference_metric::ymin
  REAL zmax;  // reference_metric::zmax
  REAL zmin;  // reference_metric::zmin
  char CoordSystemName[100];  // reference_metric::CoordSystemName[100]
  int Nxx0;  // grid::Nxx0
  int Nxx1;  // grid::Nxx1
  int Nxx2;  // grid::Nxx2
  int Nxx_plus_2NGHOSTS0;  // grid::Nxx_plus_2NGHOSTS0
  int Nxx_plus_2NGHOSTS1;  // grid::Nxx_plus_2NGHOSTS1
  int Nxx_plus_2NGHOSTS2;  // grid::Nxx_plus_2NGHOSTS2
  int outer_bc_type;  // CurviBoundaryConditions.CurviBoundaryConditions::outer_bc_type
} paramstruct;
//********************************************


//********************************************
// Basic definitions for module finite_difference:

// Set the number of ghost zones
// Note that upwinding in e.g., BSSN requires that NGHOSTS = FD_CENTDERIVS_ORDER/2 + 1 <- Notice the +1.
#define NGHOSTS 1
//********************************************


//********************************************
// Basic definitions for module reference_metric:
//********************************************


//********************************************
// Basic definitions for module CurviBoundaryConditions:

// NRPy+ Curvilinear Boundary Conditions: Core data structures
// Documented in: Tutorial-Start_to_Finish-Curvilinear_BCs.ipynb

#define EXTRAPOLATION_OUTER_BCS 0  // used to identify/specify params.outer_bc_type
#define RADIATION_OUTER_BCS     1  // used to identify/specify params.outer_bc_type

typedef struct __innerpt_bc_struct__ {
  int dstpt;  // dstpt is the 3D grid index IDX3S(i0,i1,i2) of the inner boundary point (i0,i1,i2)
  int srcpt;  // srcpt is the 3D grid index (a la IDX3S) to which the inner boundary point maps
  int8_t parity[10];  // parity[10] is a calculation of dot products for the 10 independent parity types
} innerpt_bc_struct;

typedef struct __outerpt_bc_struct__ {
  short i0,i1,i2;  // the outer boundary point grid index (i0,i1,i2), on the 3D grid
  int8_t FACEX0,FACEX1,FACEX2;  // 1-byte integers that store
  //                               FACEX0,FACEX1,FACEX2 = +1, 0, 0 if on the i0=i0min face,
  //                               FACEX0,FACEX1,FACEX2 = -1, 0, 0 if on the i0=i0max face,
  //                               FACEX0,FACEX1,FACEX2 =  0,+1, 0 if on the i1=i2min face,
  //                               FACEX0,FACEX1,FACEX2 =  0,-1, 0 if on the i1=i1max face,
  //                               FACEX0,FACEX1,FACEX2 =  0, 0,+1 if on the i2=i2min face, or
  //                               FACEX0,FACEX1,FACEX2 =  0, 0,-1 if on the i2=i2max face,
} outerpt_bc_struct;

typedef struct __bc_info_struct__ {
  int num_inner_boundary_points;  // stores total number of inner boundary points
  int num_pure_outer_boundary_points[NGHOSTS][3];  // stores number of outer boundary points on each
  //                                                  ghostzone level and direction (update min and
  //                                                  max faces simultaneously on multiple cores)
  int bc_loop_bounds[NGHOSTS][6][6];  // stores outer boundary loop bounds. Unused after bcstruct_set_up()
} bc_info_struct;

typedef struct __bc_struct__ {
  innerpt_bc_struct *restrict inner_bc_array;  // information needed for updating each inner boundary point
  outerpt_bc_struct *restrict pure_outer_bc_array[NGHOSTS*3]; // information needed for updating each outer
  //                                                             boundary point
  bc_info_struct bc_info;  // stores number of inner and outer boundary points, needed for setting loop
  //                          bounds and parallelizing over as many boundary points as possible.
} bc_struct;

/* PARITY TYPES FOR ALL GRIDFUNCTIONS.
 * SEE "Tutorial-Start_to_Finish-Curvilinear_BCs.ipynb" FOR DEFINITIONS. */
static const int8_t evol_gf_parity[9] = { 1, 2, 3, 1, 2, 3, 0, 0, 0 };
static const int8_t auxevol_gf_parity[44] = { 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 0, 0, 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 1, 2, 3 };
//********************************************


//********************************************
// Basic definitions for module MoL:
typedef struct __MoL_gridfunctions_struct__ {
  REAL *restrict y_n_gfs;
  REAL *restrict y_nplus1_running_total_gfs;
  REAL *restrict k_odd_gfs;
  REAL *restrict k_even_gfs;
  REAL *restrict auxevol_gfs;
  REAL *restrict diagnostic_output_gfs;
  REAL *restrict diagnostic_output_gfs2;
} MoL_gridfunctions_struct;
#define LOOP_ALL_GFS_GPS(ii) _Pragma("omp parallel for") \
  for(int (ii)=0;(ii)<Nxx_plus_2NGHOSTS0*Nxx_plus_2NGHOSTS1*Nxx_plus_2NGHOSTS2*NUM_EVOL_GFS;(ii)++)
//********************************************


//********************************************
// Basic definitions for module grid:
// EVOLVED VARIABLES:
#define NUM_EVOL_GFS 9
#define AD0GF	0
#define AD1GF	1
#define AD2GF	2
#define STILDED0GF	3
#define STILDED1GF	4
#define STILDED2GF	5
#define PSI6PHIGF	6
#define RHO_STARGF	7
#define TAU_TILDEGF	8


// AUXILIARY VARIABLES:
#define NUM_AUX_GFS 0


// AUXEVOL VARIABLES:
#define NUM_AUXEVOL_GFS 44
#define BU0GF	0
#define BU1GF	1
#define BU2GF	2
#define BSTAGGERU0GF	3
#define BSTAGGERU1GF	4
#define BSTAGGERU2GF	5
#define KDD00GF	6
#define KDD01GF	7
#define KDD02GF	8
#define KDD11GF	9
#define KDD12GF	10
#define KDD22GF	11
#define PGF	12
#define STILDE_FLUX_HLLD0GF	13
#define STILDE_FLUX_HLLD1GF	14
#define STILDE_FLUX_HLLD2GF	15
#define ALPHAGF	16
#define ALPHA_FACEGF	17
#define BETAU0GF	18
#define BETAU1GF	19
#define BETAU2GF	20
#define BETA_FACEU0GF	21
#define BETA_FACEU1GF	22
#define BETA_FACEU2GF	23
#define GAMMADD00GF	24
#define GAMMADD01GF	25
#define GAMMADD02GF	26
#define GAMMADD11GF	27
#define GAMMADD12GF	28
#define GAMMADD22GF	29
#define GAMMA_FACEDD00GF	30
#define GAMMA_FACEDD01GF	31
#define GAMMA_FACEDD02GF	32
#define GAMMA_FACEDD11GF	33
#define GAMMA_FACEDD12GF	34
#define GAMMA_FACEDD22GF	35
#define HGF	36
#define RHO_STAR_FLUX_HLLGF	37
#define RHOBGF	38
#define TAU_TILDE_FLUX_HLLGF	39
#define U4UTGF	40
#define VU0GF	41
#define VU1GF	42
#define VU2GF	43


// SET gridfunctions_f_infinity[i] = value of gridfunction i in the limit r->infinity:
static const REAL gridfunctions_f_infinity[NUM_EVOL_GFS] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };


// SET gridfunctions_wavespeed[i] = gridfunction i's characteristic wave speed:
static const REAL gridfunctions_wavespeed[NUM_EVOL_GFS] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

// Declare the IDX4S(gf,i,j,k) macro, which enables us to store 4-dimensions of
//   data in a 1D array. In this case, consecutive values of "i"
//   (all other indices held to a fixed value) are consecutive in memory, where
//   consecutive values of "j" (fixing all other indices) are separated by
//   Nxx_plus_2NGHOSTS0 elements in memory. Similarly, consecutive values of
//   "k" are separated by Nxx_plus_2NGHOSTS0*Nxx_plus_2NGHOSTS1 in memory, etc.
#define IDX4S(g,i,j,k)                                                  \
  ( (i) + Nxx_plus_2NGHOSTS0 * ( (j) + Nxx_plus_2NGHOSTS1 * ( (k) + Nxx_plus_2NGHOSTS2 * (g) ) ) )
#define IDX4ptS(g,idx) ( (idx) + (Nxx_plus_2NGHOSTS0*Nxx_plus_2NGHOSTS1*Nxx_plus_2NGHOSTS2) * (g) )
#define IDX3S(i,j,k) ( (i) + Nxx_plus_2NGHOSTS0 * ( (j) + Nxx_plus_2NGHOSTS1 * ( (k) ) ) )
#define LOOP_REGION(i0min,i0max, i1min,i1max, i2min,i2max)              \
  for(int i2=i2min;i2<i2max;i2++) for(int i1=i1min;i1<i1max;i1++) for(int i0=i0min;i0<i0max;i0++)
#define LOOP_OMP(__OMP_PRAGMA__, i0,i0min,i0max, i1,i1min,i1max, i2,i2min,i2max) _Pragma(__OMP_PRAGMA__) \
    for(int (i2)=(i2min);(i2)<(i2max);(i2)++) for(int (i1)=(i1min);(i1)<(i1max);(i1)++) for(int (i0)=(i0min);(i0)<(i0max);(i0)++)
#define LOOP_NOOMP(i0,i0min,i0max, i1,i1min,i1max, i2,i2min,i2max)      \
  for(int (i2)=(i2min);(i2)<(i2max);(i2)++) for(int (i1)=(i1min);(i1)<(i1max);(i1)++) for(int (i0)=(i0min);(i0)<(i0max);(i0)++)
#define LOOP_BREAKOUT(i0,i1,i2, i0max,i1max,i2max) i0=(i0max); i1=(i1max); i2=(i2max); break;
#define IS_IN_GRID_INTERIOR(i0i1i2, Nxx_plus_2NGHOSTS0,Nxx_plus_2NGHOSTS1,Nxx_plus_2NGHOSTS2, NG) \
  ( i0i1i2[0] >= (NG) && i0i1i2[0] < (Nxx_plus_2NGHOSTS0)-(NG) &&       \
    i0i1i2[1] >= (NG) && i0i1i2[1] < (Nxx_plus_2NGHOSTS1)-(NG) &&       \
    i0i1i2[2] >= (NG) && i0i1i2[2] < (Nxx_plus_2NGHOSTS2)-(NG) )

typedef struct __griddata__ {
  // griddata_struct stores data needed on each grid
  REAL *restrict xx[3];  // <- registered by NRPy+ module "grid"
  MoL_gridfunctions_struct gridfuncs;  // <- registered by NRPy+ module "MoLtimestepping.MoL"
  bc_struct bcstruct;  // <- registered by NRPy+ module "CurviBoundaryConditions.CurviBoundaryConditions"
  paramstruct params;  // <- registered by NRPy+ module "NRPy_param_funcs"
} griddata_struct;
//********************************************