/*
Code: newton_raphson.h
Programer: Sachin Krishnan T V (sachin@physics.iitm.ac.in)
Date: 10 Mar 2014
Comment: Finds root of an equation using Newton-Raphson method

Arguments:-
1) initial guess (double)
2) tolerance (double)
3) the function (double *(double, void *))
4) parameters to the function (void *)

*/

#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include "derivative.h"

double newton_raphson(double x0, double tolerance, double (*my_func)(double, void *), void *params);

#endif
