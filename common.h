
#ifndef COMMON_H
#define COMMON_H
//--------------------------------------------------
double bessel_J ( double x, int l );
double bessel_j ( double x, int l );
double bessel_N ( double x, int l );
double bessel_n ( double x, int l );

double delta_epsilon ( double epsilon, double V_0, double k, int l );
int double_fac_odd ( int num );

double potential_V ( double r, double a, double V_0 );
//--------------------------------------------------
#endif