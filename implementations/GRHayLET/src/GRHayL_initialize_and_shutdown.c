#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"

#include "GRHayLET.h"

GRHayL_parameters *grhayl_params;
eos_parameters *grhayl_eos;

int parse_C2P_routine_keyword(const char *restrict routine_name);

void GRHayLET_initialize(CCTK_ARGUMENTS) {

  DECLARE_CCTK_PARAMETERS;

  grhayl_params = (GRHayL_parameters *)malloc(sizeof(GRHayL_parameters));
  grhayl_eos = (eos_parameters *)malloc(sizeof(eos_parameters));

  const int main = parse_C2P_routine_keyword(con2prim_routine);
  int backups[3];
  for(int i=0; i<3; i++)
    backups[i] = parse_C2P_routine_keyword(con2prim_backup_routines[i]);

  initialize_GRHayL(main, backups,
                    evolve_entropy, evolve_temperature,
                    calc_primitive_guess, Psi6threshold,
                    update_Tmunu, Cupp_Fix, Lorenz_damping_factor,
                    grhayl_params);

  if (CCTK_EQUALS(EOS_type, "hybrid")) {
    initialize_hybrid_eos_functions_and_params(W_max,
                                               rho_b_atm, rho_b_atm, rho_b_max,
                                               neos, rho_ppoly_in,
                                               Gamma_ppoly_in, k_ppoly0,
                                               Gamma_th, grhayl_eos);
  } else if (CCTK_EQUALS(EOS_type, "tabulated")) {
    if( CCTK_EQUALS(EOS_tablepath, "") )
      CCTK_ERROR("Parameter EOS_tablepath uninitialized.");

    double Ye_max = 0.65; //TODO: temporary until the parameter is set up
    initialize_tabulated_eos_functions_and_params(EOS_tablepath, W_max,
                                                  rho_b_atm, rho_b_atm, rho_b_max,
                                                  Ye_atm, Ye_atm, Ye_max,
                                                  T_atm, T_atm, T_max,
                                                  grhayl_eos);
  } else if (CCTK_EQUALS(EOS_type, "")) {
    CCTK_VERROR("GRHayLET parameter EOS_type is unset. Please set an EOS type.");
  } else {
    CCTK_VERROR("GRHayLET parameter EOS_type has an unsupported type. Please check"
                " the list of parameter options in the param.ccl.");
  }
}

void GRHayLET_terminate(CCTK_ARGUMENTS) {
  if(grhayl_eos->eos_type == grhayl_eos_tabulated) {
    free(grhayl_eos->table_all);
    free(grhayl_eos->table_logrho);
    free(grhayl_eos->table_logT);
    free(grhayl_eos->table_Ye);
    free(grhayl_eos->table_eps);
  }
  free(grhayl_eos);
  free(grhayl_params);
}

int parse_C2P_routine_keyword(const char *restrict routine_name) {
  if (CCTK_EQUALS(routine_name, "None")) {
    return None;
  } else if (CCTK_EQUALS(routine_name, "Noble2D")) {
    return Noble2D;
  } else if (CCTK_EQUALS(routine_name, "Noble1D")) {
    return Noble1D;
  } else if (CCTK_EQUALS(routine_name, "Noble1D_entropy")) {
    return Noble1D_entropy;
  } else if (CCTK_EQUALS(routine_name, "Noble1D_entropy2")) {
    return Noble1D_entropy2;
  } else if (CCTK_EQUALS(routine_name, "CerdaDuran2D")) {
    return CerdaDuran2D;
  } else if (CCTK_EQUALS(routine_name, "CerdaDuran3D")) {
    return CerdaDuran3D;
  } else if (CCTK_EQUALS(routine_name, "Palenzuela1D")) {
    return Palenzuela1D;
  } else if (CCTK_EQUALS(routine_name, "Palenzuela1D_entropy")) {
    return Palenzuela1D_entropy;
  } else if (CCTK_EQUALS(routine_name, "Newman1D")) {
    return Newman1D;
  }
  return -100;
}
