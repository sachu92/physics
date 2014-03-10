/*
Code: newton_raphson.c
Programer: Sachin Krishnan T V (sachin@physics.iitm.ac.in)
Date: 10 Mar 2014
Comment: Finds root of an equation using Newton-Raphson method
*/
#include <stdio.h>
#include <math.h>
#include "newton_raphson.h"
#include "derivative.h"

#define SMALL_H 1e-4 /* infinitesimal h for calculating derivative */

double newton_raphson(double x0, double tolerance, double (*my_func)(double, void *), void *params)
{
  double difference;
  double x1;
  double de;

  do
  {
    de = derivative(x0, SMALL_H, &(*my_func), params);
    x1 = x0 - (*(my_func))(x0,params) / de;
    printf("NR: d= %e, x1 = %e\n",de, x1);  
    difference = fabs(x1-x0);
    x0=x1;
  }while(difference>tolerance);
  return x1;
}
