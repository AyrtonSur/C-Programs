#include "intercala.h"

void MergeSort(Tipo *vet, int a, int b){
    if (a<b){
        int m = a + (b-a)/2;
        MergeSort(vet, a, m);
        MergeSort(vet, m+1, b);
        intercala(vet, a, m,b);
    }
}
