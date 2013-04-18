
#include "common.h"
#include <math.h>
//===============================================================

double bessel_J ( double x, int l ) { return x*bessel_j(x,l); };

//===============================================================

double bessel_j ( double x, int l ) {
	if ( l == 0) {
		if ( x == 0 ) return 1;
		else return (sin(x)/x);
	}
	else if ( l == 1) {
		if (x == 0) return 0;
		return (sin(x)/(x*x)-cos(x)/x);
	}
	else {
		if (x == 0 ) return 0;
		return (2*l + 1)*bessel_j(x,l-1)/x - bessel_j(x,l-2);
	}
};

//===============================================================
//===============================================================

double bessel_N ( double x, int l ) { return x*bessel_n(x,l); };

//===============================================================

double bessel_n ( double x, int l ) {
	if ( l == 0) {
		if ( x == 0 ) return 0;
		else return (-cos(x)/x);
	}
	else if ( l == 1) {
		if (x == 0) return 0;
		return (-cos(x)/(x*x) - sin(x)/x);
	}
	else {
		if (x == 0 ) return 0;
		return (2*l + 1)*bessel_n(x,l-1)/x - bessel_n(x,l-2);
	}
};

//===============================================================

double delta_epsilon ( double epsilon, double V_0, double k, int l ) {
	return (-V_0 * pow(k*epsilon,2*l+1) * epsilon * epsilon)/
				( (2*l+3) * pow( double_fac_odd(l) ,2 ) );
};

//===============================================================

int double_fac_odd ( int num ) {
	int res = 1;
	
	for ( int i = 0; i <= num; i++ ) 
		res *= 2*i+1;
	
	return res;
};

//===============================================================

double potential_V ( double r, double a, double V_0 ) {
	if( r > a ) return 0;
	else {
		return -V_0;
	}
};

//===============================================================
