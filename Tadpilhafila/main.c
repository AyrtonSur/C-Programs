#include "Fila.h"
#include "Pilha.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
    Tipo notass[5] = {1, 2, 3, 4, 5};
    int total;
    Tipo kekw[2] = {6, 7};
    Tipo aux;


//*
    queueCreate();

    for (int i=0; i<5; i++){
        if (!queueIn(notass[i])){
            printf("Não consegui colocar %i\n", notass[i]);
        }
        queueCount(&total);
        printf("Quantidade de itens na lista é %i\n", total);
    }

    for (int i=0; i<2; i++){
        queueOut(&aux);
        printf("%i ", aux);
    }

    for (int i = 0; i<2; i++)
        queueIn(kekw[i]);

    for (int i = 0; i<4; i++){
        queueOut(&aux);
        printf("numero que está saindo %i\n ", aux);
        queueCount(&total);
        printf("quantidade de itens %i\n", total);
    }



    queueDestroy();

    queueCount(&total);
    printf("%i\n", total);
    if (!queueOut(&aux))
        printf("Vazio");
//*/
/*
    stCreate();

    for (int i=0; i<5; i++){
        if (!stPush(notass[i])){
            printf("Não consegui colocar %i\n", notass[i]);
        }
        stCount(&total);
        printf("Quantidade de itens na lista é %i\n", total);
    }

    for (int i=0; i<2; i++){
        stPop(&aux);
        printf("%i ", aux);
    }

    for (int i = 0; i<2; i++)
        stPush(kekw[i]);

    for (int i = 0; i<4; i++){
        stPop(&aux);
        printf("numero que está saindo %i\n ", aux);
        stCount(&total);
        printf("quantidade de itens %i\n", total);
    }



    stDestroy();
//*/
    return 0;
}
