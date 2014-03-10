/*
Code: derivtive.c
Programer: Sachin Krishnan T V (sachin@physics.iitm.ac.in)
Date: 10 Mar 2014
Comment: Calculates derivative of a user defined function at a point using central difference method
*/
#include <stdio.h>
#include "derivative.h"


double derivative(double x0, double h, double (*my_func)(double, void *), void *params)
{
  double ans;
  
  ans = ((*my_func)(x0+h,params) - (*my_func)(x0-h,params))/(2.0*h);	
  printf("DE:%lf, %lf, %lf\n",x0,h,ans);
  return ans;
}
