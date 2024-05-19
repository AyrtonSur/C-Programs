#include "intercala.h"
int main()
{
    Tipo vetor[]= {210, 17, 12, 5, 20, 30, 100, 19, 46, 37, 50, 10, 15, 5};
    int tamanho= sizeof(vetor)/sizeof(Tipo), a=0;
    Tipo *resultado;
    //intercala(vetor, a, m, b);
    MergeSort(vetor, a, tamanho-1);
    for (int i=0; i < tamanho;i++){
        printf("%i, ", vetor[i]);
    }
    return 0;
}
