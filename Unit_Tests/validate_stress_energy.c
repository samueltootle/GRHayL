#include "unit_tests.h"

/*
  In the function validate_stress_energy, the components of Tmunu are
  validated individually. In the case of failure, the code errors out
  and lists all the components that failed to be within the error
  bars of the perturbed version of the code.
*/

void validate_stress_energy(
                     const stress_energy *restrict Tmunu,
                     const stress_energy *restrict Tmunu_trusted,
                     const stress_energy *restrict Tmunu_pert) {


  char fail_msg[100] = "Test has failed!\n The stress-energy variable(s) which failed are ";
  int test_fail = 0;
  if( validate(Tmunu_trusted->Ttt, Tmunu->Ttt, Tmunu_pert->Ttt) ) {
    sprintf(fail_msg, "%.90s Ttt", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Ttx, Tmunu->Ttx, Tmunu_pert->Ttx) ) {
    sprintf(fail_msg, "%.90s Ttx", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Tty, Tmunu->Tty, Tmunu_pert->Tty) ) {
    sprintf(fail_msg, "%.90s Tty", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Ttz, Tmunu->Ttz, Tmunu_pert->Ttz) ) {
    sprintf(fail_msg, "%.90s Ttz", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Txx, Tmunu->Txx, Tmunu_pert->Txx) ) {
    sprintf(fail_msg, "%.90s Txx", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Txy, Tmunu->Txy, Tmunu_pert->Txy) ) {
    sprintf(fail_msg, "%.90s Txy", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Txz, Tmunu->Txz, Tmunu_pert->Txz) ) {
    sprintf(fail_msg, "%.90s Txz", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Tyy, Tmunu->Tyy, Tmunu_pert->Tyy) ) {
    sprintf(fail_msg, "%.90s Tyy", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Tyz, Tmunu->Tyz, Tmunu_pert->Tyz) ) {
    sprintf(fail_msg, "%.90s Tyz", fail_msg);
    test_fail = 1;
  }

  if( validate(Tmunu_trusted->Tzz, Tmunu->Tzz, Tmunu_pert->Tzz) ) {
    sprintf(fail_msg, "%.90s Tzz", fail_msg);
    test_fail = 1;
  }

  if(test_fail) {
    grhayl_error("%.100s\n", fail_msg);
  }
  return;
}
