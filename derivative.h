/*
Code: derivtive.h
Programer: Sachin Krishnan T V (sachin@physics.iitm.ac.in)
Date: 10 Mar 2014
Comment: Calculates derivative of a user defined function at a point using central difference method

Arguments are -
1) The point at which derivative is to be calculated (double)
2) infinitesimal h (double)
3) the function (double *(double, void *))
4) parameters to function (void *)

*/


#ifndef DERIVATIVE_H
#define DERIVATIVE_H

/* Function Prototypes */
double derivative(double, double, double (*my_func)(double, void *), void *);
/***********************/

#endif
