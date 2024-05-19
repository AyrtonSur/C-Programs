#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef MATLIB_H_INCLUDED
#define MATLIB_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define TWO_ROOTS 2
#define ONE_ROOT 1
#define NO_ROOTS 0
#define NOT_2ND_DEGREE -1

typedef int STATUS; //define que a palavra STATUS é um int
typedef struct raizes{
    STATUS status;
    double raiz1;
    double raiz2;
} Raizes;

Raizes * Bhaskara(double a, double b, double c);

#endif // MATLIB_H_INCLUDED
