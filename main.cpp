#include <iostream>

using namespace std;
#include "diffequations.h"
using namespace alglib;

void ode_function_1_diff(const real_1d_array &y, double x, real_1d_array &dy, void *ptr)
{
    // this callback calculates f(y[],x)=-y[0]
    dy[0] = 1;
}


int main()
{
    int N, l;
    double h, V_0, a, r_max;
    cout << "Введите количество шагов N: ";
    cin >> N;
    cout << endl;

    cout << "Введите V_0: ";
    cin >> V_0;
    cout << endl;

    cout << "Введите a: ";
    cin >> a;
    cout << endl;

    r_max = 2*a;

    cout << "Введите l: ";
    cin >> l;
    cout << endl;


    real_1d_array y = "[0]";
    real_1d_array x;
    x.setlength(N);
    h = r_max/double(N);

    for ( int i = 0; i < N; i++){
        x[i] = i*h;
    }
    double eps = 0.00001;
    odesolverstate s;
    ae_int_t m = N;
    real_1d_array xtbl;
    real_2d_array ytbl;
    odesolverreport rep;
    odesolverrkck(y, x, eps, h, s);
    alglib::odesolversolve(s, ode_function_1_diff);
    odesolverresults(s, m, xtbl, ytbl, rep);
    printf("%d\n", int(m));
   printf("%s\n", xtbl.tostring(2).c_str());
   printf("%s\n", ytbl.tostring(2).c_str());
    return 0;
}

