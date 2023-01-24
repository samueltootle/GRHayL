// Thorn      : GRHayL
// File       : unit_test_con2prim.c
// Author(s)  : Leo Werneck & Samuel Cupp
// Description: In this file we provide an extensive unit test of
//              the Con2Prim gem.
#include "unit_tests.h"

#define check_file_was_successfully_open(fp, filename) \
  if( fp == NULL ) { \
    fprintf(stderr, "(GRHayL) ERROR: Could not open file %s. Terminating.\n", filename); \
    exit(1); \
  }

// Tolerance limit for numerical values
const double relative_tolerance = 1.0e-15;

inline void perturb_data(double *restrict rand_val, primitive_quantities *restrict prims, conservative_quantities *restrict cons) {
  prims->rho   *= rand_val[0];
  prims->press *= rand_val[1];
  prims->vx    *= rand_val[2];
  prims->vy    *= rand_val[3];
  prims->vz    *= rand_val[4];
  prims->Bx    *= rand_val[5];
  prims->By    *= rand_val[6];
  prims->Bz    *= rand_val[7];
  cons->rho    *= rand_val[8];
  cons->S_x    *= rand_val[9];
  cons->S_y    *= rand_val[10];
  cons->S_z    *= rand_val[11];
  cons->tau    *= rand_val[12];
}

int main(int argc, char **argv) {

  // These variables set up the tested range of values
  // and number of sampling points.
  int npoints = 256; //Number of sampling points in density and temperature
  double test_rho_min = 1e-12; //Minimum input density
  double test_rho_max = 1e-3; //Maximum input density
  // double test_T_min = 1e-2; //Minimum input temperature
  // double test_T_max = 1e+2; //Maximum input temperature

  // Count number of routines tested
  int num_routines_tested = 1;
  int con2prim_test_keys[num_routines_tested];
  char con2prim_test_names[num_routines_tested][50];

  con2prim_test_keys[0] = Noble2D;
  sprintf(con2prim_test_names[0],"%s","Noble2D");

  double poison = 1e200;
  // This section sets up the initial parameters that would normally
  // be provided by the simulation.
  int backup_routine[3] = {None,None,None};
  bool calc_prims_guess = true;
  double Psi6threshold = 1e100; //Taken from magnetizedTOV.par
  int update_Tmunu = 1; //IGM default

  int eos_type = 0; // Hybrid=0, Tabulated=1;
  int neos = 1;
  double W_max = 10.0; //IGM default
  double rho_b_max = 1e300; //IGM default
  double gamma_th = 2.0; //Taken from magnetizedTOV.par
  double rho_tab[1] = {0.0};
  double gamma_tab[1] = {2.0};
  double k_tab = 1.0;

  // Here, we initialize the structs that are (usually) static during
  // a simulation.
  GRHayL_parameters params;
  initialize_GRHayL(None, backup_routine, false /*evolve entropy*/, false /*evolve temperature*/, calc_prims_guess, Psi6threshold, update_Tmunu, 1 /*Cupp Fix*/, &params);

  eos_parameters eos;
  initialize_general_eos(eos_type, W_max,
             test_rho_min, test_rho_min, rho_b_max,
             &eos);

  initialize_hybrid_functions(&eos);

  initialize_hybrid_eos(neos, rho_tab,
             gamma_tab, k_tab, gamma_th,
             &eos);

  con2prim_diagnostics diagnostics;
  initialize_diagnostics(&diagnostics);

  // We will be performing the tabulated EOS test in the following way:
  //
  //      Y_e      = 0.1
  //       W       = 2
  // log10(Pmag/P) = -5
  //
  // rho will vary between rho_min and rho_max (uniformly in log space)
  //  T  will vary between  T_min  and  T_max  (uniformly in log space)

  // Compute the density step size
  const double lrmin        = log(test_rho_min);
  const double lrmax        = log(test_rho_max);
  const double dlr          = (lrmax - lrmin)/(npoints-1);

  // Compute the temperature step size
  //const double ltmin        = log(test_T_min);
  //const double ltmax        = log(test_T_max);
  //const double dlt          = (ltmax - ltmin)/(npoints-1);

  // tau is given by (see :
  //
  // tau := hW^{2} + B^{2} - P - 0.5*( (B.v)^{2} + (B/W)^{2} )
  // Absolutely minimum allowed tau

  char filename[100];
  // Now perform one test for each of the selected routines
  // TODO: unlike main loop, this loop can be parallelized because each routine uses a different file
  for(int which_routine=0;which_routine<num_routines_tested;which_routine++) {
    params.main_routine = con2prim_test_keys[which_routine];

    int failures = 0;
    for(int rand=0;rand<2;rand++) {

      double rand_val[13];
      char suffix[10] = "norm";
      if(rand==1) {
        srand(1000000);
        sprintf(suffix, "rand");
        for(int i=0;i<13;i++) rand_val[i] = 1.0 + randf(-1,1)*1.0e-14;
      }

      printf("Beginning %s test for routine %s\n", suffix, con2prim_test_names[which_routine]);

      FILE* infiles[7];

      sprintf(filename,"C2P_%.30s_%.4s_limit_v_and_output_u0.bin",con2prim_test_names[which_routine], suffix);
      infiles[0] = fopen(filename,"rb");
      check_file_was_successfully_open(infiles[0], filename);

      sprintf(filename,"C2P_%.30s_%.4s_apply_inequality_fixes.bin",con2prim_test_names[which_routine], suffix);
      infiles[1] = fopen(filename,"rb");
      check_file_was_successfully_open(infiles[1], filename);

      sprintf(filename,"C2P_%.30s_%.4s_Hybrid_Multi_Method.bin",con2prim_test_names[which_routine], suffix);
      infiles[2] = fopen(filename,"rb");
      check_file_was_successfully_open(infiles[2], filename);

      sprintf(filename,"C2P_%.30s_%.4s_font_fix.bin",con2prim_test_names[which_routine], suffix);
      infiles[3] = fopen(filename,"rb");
      check_file_was_successfully_open(infiles[3], filename);

      sprintf(filename,"C2P_%.30s_%.4s_enforce_primitive_limits_and_output_u0.bin",con2prim_test_names[which_routine], suffix);
      infiles[4] = fopen(filename,"rb");
      check_file_was_successfully_open(infiles[4], filename);

      sprintf(filename,"C2P_%.30s_%.4s_compute_conservs.bin",con2prim_test_names[which_routine], suffix);
      infiles[5] = fopen(filename,"rb");
      check_file_was_successfully_open(infiles[5], filename);

      sprintf(filename,"C2P_%.30s_%.4s_compute_Tmunu.bin",con2prim_test_names[which_routine], suffix);
      infiles[6] = fopen(filename,"rb");
      check_file_was_successfully_open(infiles[6], filename);

      srand(0);

      // Can't parallelize because it could change the behavior of reading from the files
      for(int i=0;i<npoints;i++) { // Density loop
        double xrho  = exp(lrmin + dlr*i);
        double P_cold = 0.0;
        eos.hybrid_compute_P_cold(&eos, xrho, &P_cold);

        // Compute the pressure step size
        const double lpmin        = log(1.0e-30);//-P_cold);
        const double lpmax        = log(10.0*P_cold);
        const double dlp          = (lpmax - lpmin)/(npoints-1);
        for(int j=0;j<npoints;j++) { // Pressure loop
          // Start by setting the prims (rho,Ye,T,P,eps)
          //double xtemp = exp(ltmin + dlt*j);
          //double xye   = Ye_test;
          double xpress  = exp(lpmin + dlp*j);
          //WVU_EOS_P_and_eps_from_rho_Ye_T( xrho,xye,xtemp, &xpress,&xeps );

          // Define the various GRHayL structs for the unit tests
          metric_quantities metric;
          primitive_quantities prims, prims_orig, prims_guess;
          conservative_quantities cons, cons_orig, cons_undens;
          stress_energy Tmunu, Tmunu_orig;

          // Leo says: Initialize cons_orig to silence warning; remove later.
          cons_orig.rho = 1e300;
          cons_orig.S_x = 1e300;
          cons_orig.S_y = 1e300;
          cons_orig.S_z = 1e300;

          // Generate random data to serve as the 'true' primitive values
          initial_random_data(xrho, xpress, &metric, &prims);

          double u0 = poison;
          int test_fail;
          prims_orig = prims;
          limit_v_and_output_u0(&eos, &metric, &prims, &u0, &diagnostics);
          test_fail = validate_primitives(relative_tolerance, eos.eos_type, 1, params.evolve_entropy, &prims_orig, &prims, infiles[0]);
          if(test_fail) {
            printf("Test unit_test_con2prim has failed with error code %d after function limit_v_and_output_u0.\n"
                   "Please check file Unit_Tests/validate_primitives.c for information on the possible exit codes.\n", test_fail);
            exit(1);
          }

          // Compute conservatives based on these primitives
          compute_conservs_and_Tmunu(&params, &eos, &metric, &prims, u0, &cons, &Tmunu);

          //This is meant to simulate some round-off error that deviates from the "true" values that we just computed.
          if(rand) perturb_data(rand_val, &prims, &cons);

          int check = 0;
          if(cons.rho > 0.0) {

            //This applies the inequality (or "Faber") fixes on the conservatives
            if(eos.eos_type == 0) { //Hybrid-only
              cons_orig = cons;
              apply_inequality_fixes(&params, &eos, &metric, &prims, &cons, &diagnostics);
              test_fail = validate_conservatives(relative_tolerance, params.evolve_entropy, &cons_orig, &cons, infiles[1]);
              if(test_fail) {
                printf("Test unit_test_con2prim has failed with error code %d after function apply_inequality_fixes.\n"
                       "Please check file Unit_Tests/validate_conservatives.c for information on the possible exit codes.\n", test_fail);
                exit(1);
              }
            }

            // The Con2Prim routines require the undensitized variables, but IGM evolves the densitized variables.
            undensitize_conservatives(&metric, &cons, &cons_undens);

            /************* Conservative-to-primitive recovery ************/
            prims_orig = prims;
            check = Hybrid_Multi_Method(&params, &eos, &metric, &cons_undens, &prims, &prims_guess, &diagnostics);
            test_fail = validate_primitives(relative_tolerance, eos.eos_type, 0, params.evolve_entropy, &prims_orig, &prims_guess, infiles[2]);
            if(test_fail) {
              printf("Test unit_test_con2prim has failed with error code %d after function Hybrid_Multi_Method.\n"
                     "Please check file Unit_Tests/validate_primitives.c for information on the possible exit codes.\n", test_fail);
              exit(1);
            }

            if(check!=0) {
              check = font_fix(&eos, &metric, &cons, &prims, &prims_guess, &diagnostics);
              test_fail = validate_primitives(relative_tolerance, eos.eos_type, 0, params.evolve_entropy, &prims_orig, &prims_guess, infiles[3]);
            } else { //The else is so that Font Fix is tested even when the primary routine succeeds.
              primitive_quantities prims_tmp;
              check = font_fix(&eos, &metric, &cons, &prims, &prims_tmp, &diagnostics);
              test_fail = validate_primitives(relative_tolerance, eos.eos_type, 0, params.evolve_entropy, &prims_orig, &prims_tmp, infiles[3]);
            }
            if(test_fail) {
              printf("Test unit_test_con2prim has failed with error code %d after function font_fix.\n"
                     "Please check file Unit_Tests/validate_primitives.c for information on the possible exit codes.\n", test_fail);
              exit(1);
            }

            /*************************************************************/

            if(check==0) {
              prims = prims_guess;
            } else {
              printf("Con2Prim and Font fix failed!");
            }
          } else {
            diagnostics.failure_checker+=1;
            reset_prims_to_atmosphere(&params, &eos, &metric, &prims, &diagnostics);
            //TODO: Validate reset? (rhob press v)
            printf("Negative rho_* triggering atmospheric reset.\n");
          } // if rho_star > 0

          //--------------------------------------------------
          //---------- Primitive recovery completed ----------
          //--------------------------------------------------
          // Enforce limits on primitive variables and recompute conservatives.
          prims_orig = prims;
          enforce_primitive_limits_and_output_u0(&params, &eos, &metric, &prims, &u0, &diagnostics);
          validate_primitives(relative_tolerance, eos.eos_type, 0, params.evolve_entropy, &prims_orig, &prims, infiles[4]);
            if(test_fail) {
              printf("Test unit_test_con2prim has failed with error code %d after function enforce_primitive_limits_and_output_u0.\n"
                     "Please check file Unit_Tests/validate_primitives.c for information on the possible exit codes.\n", test_fail);
              exit(1);
            }

          cons_orig = cons;
          Tmunu_orig = Tmunu;
          compute_conservs_and_Tmunu(&params, &eos, &metric, &prims, u0, &cons, &Tmunu);
          test_fail = validate_conservatives(relative_tolerance, params.evolve_entropy, &cons_orig, &cons, infiles[5]);
          if(test_fail) {
            printf("Test unit_test_con2prim has failed with error code %d after function compute_conservs_and_Tmunu.\n"
                   "Please check file Unit_Tests/validate_conservatives.c for information on the possible exit codes.\n", test_fail);
            exit(1);
          }
          test_fail = validate_stress_energy(relative_tolerance, &Tmunu_orig, &Tmunu, infiles[6]);
          if(test_fail) {
            printf("Test unit_test_con2prim has failed with error code %d after function compute_conservs_and_Tmunu.\n"
                   "Please check file Unit_Tests/validate_stress_energy.c for information on the possible exit codes.\n", test_fail);
            exit(1);
          }

          if( check != 0 )
            failures++;
        } // Pressure loop
      } // Density loop
      for(int k = 0; k < (sizeof(infiles)/sizeof(infiles[0])); k++) fclose(infiles[k]);
    } // perturbation loop

    int ntotal = npoints*npoints;

    printf("Completed test for routine %s\n",con2prim_test_names[which_routine]);
    printf("Final report:\n");
    printf("    Number of recovery attempts: %d\n",ntotal);
    printf("    Number of failed recoveries: %d\n",failures);
    printf("    Recovery failure rate      : %.2lf%%\n",((double)failures)/((double)ntotal)*100.0);
  }
  return 0;
}
