#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef int Logico;

typedef struct {
    char nomes[80];
    int cpf;
    double notas[4];
} Aluno;

typedef int Tipo;

Logico queueCreate();// criação ou construção
Logico queueDestroy();// destruição
Logico queueIsFull();// para saber se está  cheia
Logico queueIsEmpty();// se está  vazia
Logico queueIn(Tipo e); // colocar na fila
Logico queueOut(Tipo *e); //retirar da fila
Logico queueCount(int *total);

#endif // FILA_H_INCLUDED
