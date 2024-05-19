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

Logico queueCreate();// cria��o ou constru��o
Logico queueDestroy();// destrui��o
Logico queueIsFull();// para saber se est�  cheia
Logico queueIsEmpty();// se est�  vazia
Logico queueIn(Tipo e); // colocar na fila
Logico queueOut(Tipo *e); //retirar da fila
Logico queueCount(int *total);

#endif // FILA_H_INCLUDED
