#include "con2prim.h"
#include <stdio.h>

/* Function    : guess_primitives()
 * Description : This function computes initial guesses for the primitives
 *               for use in the Con2Prim solver.
 *
 * Inputs      : eos            - an initialized eos_parameters struct
 *                                with data for the EOS of the simulation
 *             : metric         - an initialized metric_quantities struct
 *                                with data for the gridpoint of interest
 *             : cons           - an initialized conservative_quantities
 *                                struct with data for the gridpoint of
 *                                interest
 *
 * Outputs     : prims_guess    - primitive_quantities struct filled with
 *                                an initial primitives guess for the
 *                                Con2Prim solver
 */

void guess_primitives( const eos_parameters *restrict eos,
                       const metric_quantities *restrict metric,
                       const primitive_quantities *restrict prims,
                       const conservative_quantities *restrict cons,
                       primitive_quantities *restrict prims_guess ) {

  //Use atmosphere as initial guess:
  prims_guess->rho = cons->rho/metric->psi6;
  eos->hybrid_compute_P_cold(eos, prims_guess->rho, &prims_guess->press);
  prims_guess->Y_e = cons->Y_e/cons->rho;
  prims_guess->temperature = eos->T_atm;
}
