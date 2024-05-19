#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef int Logico;


typedef int Tipo;

Logico stCreate();// cria��o ou constru��o
Logico stDestroy();// destrui��o
Logico stIsFull();// para saber se a pilha est�  cheia
Logico stIsEmpty();// se a pilha est�  vazia
Logico stPush(Tipo e); // colocar coisas na pilha
Logico stPop(Tipo *e); //retirar coisas da pilha
Logico stCount(int *total);


#endif // PILHA_H_INCLUDED
