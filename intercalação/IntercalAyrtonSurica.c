#include "intercala.h"

Tipo intercala(Tipo *vet, int a, int m, int b){
    if (b-a==1){
        if (vet[a]<=vet[b]){
            return 0;
        } else {
            Tipo aux = vet[a];
            vet[a]=vet[b];
            vet[b]=aux;
            return 0;
        }
    } else if (b-a==0){
        return 0;
    } else {
        int posiInic=a;//pega a posi��o inicial de onde o vetor dever� ser ordenado
        int posiMed=m+1;//pega a divis�o do vetor (o m)
        int posic=0;//a posi��o para os vetores tempor�rios
        Tipo *vet_temp;// Tipo est� definido como um inteiro e isso aqui cria um ponteiro inteiro
        int tamanho_vet_temp = b - a + 1;
        vet_temp= (int *)malloc(tamanho_vet_temp * sizeof(*vet));//para alocar mem�ria para o ponteiro

        while (posiInic<=m && posiMed<=b){
            if (vet[posiInic]<vet[posiMed]){
                vet_temp[posic]=vet[posiInic];
                posiInic++;
                posic++;
            } else {
                vet_temp[posic]=vet[posiMed];
                posiMed++;
                posic++;
            }
        }
        while (posiMed<=b){
            vet_temp[posic]=vet[posiMed];
            posiMed++;
            posic++;
        }
        while (posiInic<=m){
            vet_temp[posic]=vet[posiInic];
            posiInic++;
            posic++;
        }
        for (int i=0;i < tamanho_vet_temp;i++){
            vet[a+i]= vet_temp[i];
        }
        free(vet_temp);
        return 0;
    }
}
