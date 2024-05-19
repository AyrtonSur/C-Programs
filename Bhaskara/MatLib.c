#include "MatLib.h"

Raizes * Bhaskara(double a, double b, double c){
    double raiz1=0.0, raiz2=0.0;
    Raizes * resultado;
    resultado = (Raizes *) malloc(sizeof(Raizes));//memória alocada
    (*resultado).status = NOT_2ND_DEGREE;
    (*resultado).raiz1=raiz1;
    (*resultado).raiz2=raiz2;
    if (a == 0.0) return resultado;
    double delta=b*b-4.0*a*c;
    if (delta< 0.0) {
        (*resultado).status = NO_ROOTS;
        return resultado;
    }
    double sqrtDelta = sqrt(delta);
    raiz1=(-b+sqrtDelta)/2*a;
    raiz2=(-b-sqrtDelta)/2*a;
    (*resultado).raiz1=raiz1;
    (*resultado).raiz2=raiz2;
    if (delta==0) {
        (*resultado).status= ONE_ROOT;
    } else {
        (*resultado).status= TWO_ROOTS;
    }
    return resultado;
}
