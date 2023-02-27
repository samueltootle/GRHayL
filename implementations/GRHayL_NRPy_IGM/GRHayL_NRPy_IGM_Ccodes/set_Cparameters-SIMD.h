const int Nxx0 = params->Nxx0;  // grid::Nxx0
const int Nxx1 = params->Nxx1;  // grid::Nxx1
const int Nxx2 = params->Nxx2;  // grid::Nxx2
const int Nxx_plus_2NGHOSTS0 = params->Nxx_plus_2NGHOSTS0;  // grid::Nxx_plus_2NGHOSTS0
const int Nxx_plus_2NGHOSTS1 = params->Nxx_plus_2NGHOSTS1;  // grid::Nxx_plus_2NGHOSTS1
const int Nxx_plus_2NGHOSTS2 = params->Nxx_plus_2NGHOSTS2;  // grid::Nxx_plus_2NGHOSTS2
const REAL            NOSIMDdxx0 = params->dxx0;  // grid::dxx0
const REAL_SIMD_ARRAY dxx0 = ConstSIMD(NOSIMDdxx0);  // grid::dxx0
const REAL            NOSIMDdxx1 = params->dxx1;  // grid::dxx1
const REAL_SIMD_ARRAY dxx1 = ConstSIMD(NOSIMDdxx1);  // grid::dxx1
const REAL            NOSIMDdxx2 = params->dxx2;  // grid::dxx2
const REAL_SIMD_ARRAY dxx2 = ConstSIMD(NOSIMDdxx2);  // grid::dxx2
const REAL            NOSIMDxxmin0 = params->xxmin0;  // grid::xxmin0
const REAL_SIMD_ARRAY xxmin0 = ConstSIMD(NOSIMDxxmin0);  // grid::xxmin0
const REAL            NOSIMDxxmin1 = params->xxmin1;  // grid::xxmin1
const REAL_SIMD_ARRAY xxmin1 = ConstSIMD(NOSIMDxxmin1);  // grid::xxmin1
const REAL            NOSIMDxxmin2 = params->xxmin2;  // grid::xxmin2
const REAL_SIMD_ARRAY xxmin2 = ConstSIMD(NOSIMDxxmin2);  // grid::xxmin2
const REAL            NOSIMDxxmax0 = params->xxmax0;  // grid::xxmax0
const REAL_SIMD_ARRAY xxmax0 = ConstSIMD(NOSIMDxxmax0);  // grid::xxmax0
const REAL            NOSIMDxxmax1 = params->xxmax1;  // grid::xxmax1
const REAL_SIMD_ARRAY xxmax1 = ConstSIMD(NOSIMDxxmax1);  // grid::xxmax1
const REAL            NOSIMDxxmax2 = params->xxmax2;  // grid::xxmax2
const REAL_SIMD_ARRAY xxmax2 = ConstSIMD(NOSIMDxxmax2);  // grid::xxmax2
const REAL            NOSIMDinvdx0 = params->invdx0;  // grid::invdx0
const REAL_SIMD_ARRAY invdx0 = ConstSIMD(NOSIMDinvdx0);  // grid::invdx0
const REAL            NOSIMDinvdx1 = params->invdx1;  // grid::invdx1
const REAL_SIMD_ARRAY invdx1 = ConstSIMD(NOSIMDinvdx1);  // grid::invdx1
const REAL            NOSIMDinvdx2 = params->invdx2;  // grid::invdx2
const REAL_SIMD_ARRAY invdx2 = ConstSIMD(NOSIMDinvdx2);  // grid::invdx2
const REAL            NOSIMDCart_originx = params->Cart_originx;  // grid::Cart_originx
const REAL_SIMD_ARRAY Cart_originx = ConstSIMD(NOSIMDCart_originx);  // grid::Cart_originx
const REAL            NOSIMDCart_originy = params->Cart_originy;  // grid::Cart_originy
const REAL_SIMD_ARRAY Cart_originy = ConstSIMD(NOSIMDCart_originy);  // grid::Cart_originy
const REAL            NOSIMDCart_originz = params->Cart_originz;  // grid::Cart_originz
const REAL_SIMD_ARRAY Cart_originz = ConstSIMD(NOSIMDCart_originz);  // grid::Cart_originz
const REAL            NOSIMDCart_CoM_offsetx = params->Cart_CoM_offsetx;  // grid::Cart_CoM_offsetx
const REAL_SIMD_ARRAY Cart_CoM_offsetx = ConstSIMD(NOSIMDCart_CoM_offsetx);  // grid::Cart_CoM_offsetx
const REAL            NOSIMDCart_CoM_offsety = params->Cart_CoM_offsety;  // grid::Cart_CoM_offsety
const REAL_SIMD_ARRAY Cart_CoM_offsety = ConstSIMD(NOSIMDCart_CoM_offsety);  // grid::Cart_CoM_offsety
const REAL            NOSIMDCart_CoM_offsetz = params->Cart_CoM_offsetz;  // grid::Cart_CoM_offsetz
const REAL_SIMD_ARRAY Cart_CoM_offsetz = ConstSIMD(NOSIMDCart_CoM_offsetz);  // grid::Cart_CoM_offsetz
const REAL            NOSIMDxmin = params->xmin;  // reference_metric::xmin
const REAL_SIMD_ARRAY xmin = ConstSIMD(NOSIMDxmin);  // reference_metric::xmin
const REAL            NOSIMDxmax = params->xmax;  // reference_metric::xmax
const REAL_SIMD_ARRAY xmax = ConstSIMD(NOSIMDxmax);  // reference_metric::xmax
const REAL            NOSIMDymin = params->ymin;  // reference_metric::ymin
const REAL_SIMD_ARRAY ymin = ConstSIMD(NOSIMDymin);  // reference_metric::ymin
const REAL            NOSIMDymax = params->ymax;  // reference_metric::ymax
const REAL_SIMD_ARRAY ymax = ConstSIMD(NOSIMDymax);  // reference_metric::ymax
const REAL            NOSIMDzmin = params->zmin;  // reference_metric::zmin
const REAL_SIMD_ARRAY zmin = ConstSIMD(NOSIMDzmin);  // reference_metric::zmin
const REAL            NOSIMDzmax = params->zmax;  // reference_metric::zmax
const REAL_SIMD_ARRAY zmax = ConstSIMD(NOSIMDzmax);  // reference_metric::zmax
const REAL            NOSIMDTINYDOUBLE = params->TINYDOUBLE;  // Min_Max_and_Piecewise_Expressions::TINYDOUBLE
const REAL_SIMD_ARRAY TINYDOUBLE = ConstSIMD(NOSIMDTINYDOUBLE);  // Min_Max_and_Piecewise_Expressions::TINYDOUBLE
const int outer_bc_type = params->outer_bc_type;  // CurviBoundaryConditions.CurviBoundaryConditions::outer_bc_type
const REAL            NOSIMDsqrt4pi = params->sqrt4pi;  // __main__::sqrt4pi
const REAL_SIMD_ARRAY sqrt4pi = ConstSIMD(NOSIMDsqrt4pi);  // __main__::sqrt4pi
const REAL            NOSIMDGAMMA_SPEED_LIMIT = params->GAMMA_SPEED_LIMIT;  // GRMHD_equations_new_version::GAMMA_SPEED_LIMIT
const REAL_SIMD_ARRAY GAMMA_SPEED_LIMIT = ConstSIMD(NOSIMDGAMMA_SPEED_LIMIT);  // GRMHD_equations_new_version::GAMMA_SPEED_LIMIT
const REAL            NOSIMDRHOMAX = params->RHOMAX;  // reference_metric::RHOMAX
const REAL_SIMD_ARRAY RHOMAX = ConstSIMD(NOSIMDRHOMAX);  // reference_metric::RHOMAX
const REAL            NOSIMDZMIN = params->ZMIN;  // reference_metric::ZMIN
const REAL_SIMD_ARRAY ZMIN = ConstSIMD(NOSIMDZMIN);  // reference_metric::ZMIN
const REAL            NOSIMDZMAX = params->ZMAX;  // reference_metric::ZMAX
const REAL_SIMD_ARRAY ZMAX = ConstSIMD(NOSIMDZMAX);  // reference_metric::ZMAX
