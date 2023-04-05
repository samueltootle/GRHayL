#include "flux_source.h"
/*
 * Add source term for 0-component of Stilde and tau_tilde
 */
void calculate_source_terms_dirn0(const primitive_quantities *restrict prims, struct eos_parameters const *restrict eos, const metric_quantities *restrict metric, const metric_derivatives *restrict metric_derivs, conservative_quantities *restrict cons) {

{

double h, cs2;

eos->compute_h_and_cs2(eos, prims, &h, &cs2);
const double u4U0 = prims->u0;
const double u4U1 = prims->vx*u4U0;
const double u4U2 = prims->vy*u4U0;
const double u4U3 = prims->vz*u4U0;
const double BU0 = prims->Bx;
const double BU1 = prims->By;
const double BU2 = prims->Bz;
const double P = prims->press;
const double rhob = prims->rho;
const double alpha = metric->lapse;
const double betaU0 = metric->betax;
const double betaU1 = metric->betay;
const double betaU2 = metric->betaz;
const double gammaDD00 = metric->adm_gxx;
const double gammaDD01 = metric->adm_gxy;
const double gammaDD02 = metric->adm_gxz;
const double gammaDD11 = metric->adm_gyy;
const double gammaDD12 = metric->adm_gyz;
const double gammaDD22 = metric->adm_gzz;
const double alpha_dD0 = metric_derivs->lapse[0];
const double betaU_dD00 = metric_derivs->betax[0];
const double betaU_dD10 = metric_derivs->betay[0];
const double betaU_dD20 = metric_derivs->betaz[0];
const double gammaDD_dD000 = metric_derivs->adm_gxx[0];
const double gammaDD_dD010 = metric_derivs->adm_gxy[0];
const double gammaDD_dD020 = metric_derivs->adm_gxz[0];
const double gammaDD_dD110 = metric_derivs->adm_gyy[0];
const double gammaDD_dD120 = metric_derivs->adm_gyz[0];
const double gammaDD_dD220 = metric_derivs->adm_gzz[0];
  const double _Integer_2 = 2.0;
  const double _Rational_1_2 = 1.0/2.0;
  const double tmp_0 = betaU0*gammaDD_dD000 + betaU1*gammaDD_dD010 + betaU2*gammaDD_dD020 + betaU_dD00*gammaDD00 + betaU_dD10*gammaDD01 + betaU_dD20*gammaDD02;
  const double tmp_1 = betaU0*gammaDD00 + betaU1*gammaDD01 + betaU2*gammaDD02;
  const double tmp_2 = betaU0*gammaDD01 + betaU1*gammaDD11 + betaU2*gammaDD12;
  const double tmp_3 = betaU0*gammaDD02 + betaU1*gammaDD12 + betaU2*gammaDD22;
  const double tmp_4 = BU0*(gammaDD00*u4U1 + gammaDD01*u4U2 + gammaDD02*u4U3 + tmp_1*u4U0) + BU1*(gammaDD01*u4U1 + gammaDD11*u4U2 + gammaDD12*u4U3 + tmp_2*u4U0) + BU2*(gammaDD02*u4U1 + gammaDD12*u4U2 + gammaDD22*u4U3 + tmp_3*u4U0);
  const double tmp_5 = BU0 + tmp_4*u4U1;
  const double tmp_7 = (1.0/((alpha)*(alpha)));
  const double tmp_8 = tmp_7/((SQRT_4_PI)*(SQRT_4_PI));
  const double tmp_9 = tmp_4*tmp_8/u4U0;
  const double tmp_12 = tmp_8/((u4U0)*(u4U0));
  const double tmp_13 = tmp_12*((tmp_5)*(tmp_5));
  const double tmp_14 = BU1 + tmp_4*u4U2;
  const double tmp_15 = tmp_12*((tmp_14)*(tmp_14));
  const double tmp_16 = BU2 + tmp_4*u4U3;
  const double tmp_17 = tmp_12*((tmp_16)*(tmp_16));
  const double tmp_18 = ((tmp_4)*(tmp_4))*tmp_8;
  const double tmp_19 = gammaDD00*tmp_13 + gammaDD11*tmp_15 + gammaDD22*tmp_17 + tmp_18*(-((alpha)*(alpha)) + betaU0*tmp_1 + betaU1*tmp_2 + betaU2*tmp_3);
  const double tmp_21 = tmp_12*tmp_14*tmp_5;
  const double tmp_22 = tmp_12*tmp_16*tmp_5;
  const double tmp_23 = tmp_12*tmp_14*tmp_16;
  const double tmp_26 = gammaDD01*tmp_21 + gammaDD02*tmp_22 + gammaDD12*tmp_23 + tmp_1*tmp_5*tmp_9 + tmp_14*tmp_2*tmp_9 + tmp_16*tmp_3*tmp_9;
  const double tmp_27 = P + _Rational_1_2*tmp_19 + tmp_26;
  const double tmp_28 = tmp_27*tmp_7;
  const double tmp_29 = _Integer_2*tmp_26 + h*rhob + tmp_19;
  const double tmp_30 = tmp_29*u4U1;
  const double tmp_31 = betaU0*tmp_28 + tmp_30*u4U0 - tmp_5*tmp_9;
  const double tmp_35 = _Integer_2*gammaDD01*gammaDD02*gammaDD12 + gammaDD00*gammaDD11*gammaDD22 - gammaDD00*((gammaDD12)*(gammaDD12)) - ((gammaDD01)*(gammaDD01))*gammaDD22 - ((gammaDD02)*(gammaDD02))*gammaDD11;
  const double tmp_36 = sqrt(tmp_35);
  const double tmp_37 = alpha*tmp_36;
  const double tmp_38 = betaU0*gammaDD_dD010 + betaU1*gammaDD_dD110 + betaU2*gammaDD_dD120 + betaU_dD00*gammaDD01 + betaU_dD10*gammaDD11 + betaU_dD20*gammaDD12;
  const double tmp_40 = betaU0*gammaDD_dD020 + betaU1*gammaDD_dD120 + betaU2*gammaDD_dD220 + betaU_dD00*gammaDD02 + betaU_dD10*gammaDD12 + betaU_dD20*gammaDD22;
  const double tmp_42 = (1.0/(tmp_35));
  const double tmp_43 = -tmp_18 - tmp_28 + tmp_29*((u4U0)*(u4U0));
  cons->S_x = _Rational_1_2*(gammaDD_dD000*tmp_37*(-tmp_13 + tmp_27*(-((betaU0)*(betaU0))*tmp_7 + tmp_42*(gammaDD11*gammaDD22 - ((gammaDD12)*(gammaDD12)))) + tmp_29*((u4U1)*(u4U1))) + gammaDD_dD110*tmp_37*(-tmp_15 + tmp_27*(-((betaU1)*(betaU1))*tmp_7 + tmp_42*(gammaDD00*gammaDD22 - ((gammaDD02)*(gammaDD02)))) + tmp_29*((u4U2)*(u4U2))) + gammaDD_dD220*tmp_37*(-tmp_17 + tmp_27*(-((betaU2)*(betaU2))*tmp_7 + tmp_42*(gammaDD00*gammaDD11 - ((gammaDD01)*(gammaDD01)))) + tmp_29*((u4U3)*(u4U3))) + tmp_37*tmp_43*(-_Integer_2*alpha*alpha_dD0 + betaU0*tmp_0 + betaU1*tmp_38 + betaU2*tmp_40 + betaU_dD00*tmp_1 + betaU_dD10*tmp_2 + betaU_dD20*tmp_3)) + gammaDD_dD010*tmp_37*(-tmp_21 + tmp_27*(-betaU0*betaU1*tmp_7 + tmp_42*(-gammaDD01*gammaDD22 + gammaDD02*gammaDD12)) + tmp_30*u4U2) + gammaDD_dD020*tmp_37*(-tmp_22 + tmp_27*(-betaU0*betaU2*tmp_7 + tmp_42*(gammaDD01*gammaDD12 - gammaDD02*gammaDD11)) + tmp_30*u4U3) + gammaDD_dD120*tmp_37*(-tmp_23 + tmp_27*(-betaU1*betaU2*tmp_7 + tmp_42*(-gammaDD00*gammaDD12 + gammaDD01*gammaDD02)) + tmp_29*u4U2*u4U3) + tmp_0*tmp_31*tmp_37 + tmp_37*tmp_38*(betaU1*tmp_28 - tmp_14*tmp_9 + tmp_29*u4U0*u4U2) + tmp_37*tmp_40*(betaU2*tmp_28 - tmp_16*tmp_9 + tmp_29*u4U0*u4U3);
  cons->tau = alpha*alpha_dD0*tmp_36*(-betaU0*tmp_43 - tmp_31);
}
}
