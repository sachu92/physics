/*
Critical temperature in Maier-Saupe theory

s = -0.5 + 1.5 * z'(m)/z(m)  	=> (1)
s = 2*k*T*m/(3*u)		=> (2)

At Tc there will be exactly one root for (1) - (2)

*/
#include<stdio.h>
#include<math.h>
#include "newton_raphson.h"
#include "gsl/gsl_sf_erf.h"

double z(double, void*);
double ms(double, void*);

int main()
{
  double a = 6.0;
  double x;
  void *params;

  params = &a;

  /*while (a<4.0)
  {*/
    x = newton_raphson(100.0,1.0e-6, &ms ,params);
    printf("a = %f, x= %e\n", a, x);
  /*  a+=0.01;
  }*/
  return 0;
}

double z(double m, void *params)
{
  double ans;
  double sqrtm;
  double pi;

  pi = 4.0 * atan(1.0);
  sqrtm = sqrt(m);
  ans = sqrt(pi) * gsl_sf_erf(sqrtm) / (2.0 * sqrtm);

  return ans;
}

double ms(double m, void *params)
{
  double ans;
  double *a; /* a = u/(kT) */

  a = (double *)params;
  ans = -0.5 + (1.5 * derivative(m,1e-4,&z,NULL)/ z(m,NULL)) - (2.0*m/(3.0*(*a)));

  return ans;
}
