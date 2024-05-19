#include "Fila.h"
/*
#define MAX 4
Tipo vetoraux[MAX];
int count;
int primeiro;
int ultimo;

Logico queueCreate(){
    count = 0;
    primeiro = ultimo = -1;
}
Logico queueDestroy(){
    count = 0;
    primeiro = ultimo = -1;
}
Logico queueIsFull(){
    if (count>=MAX)
        return TRUE;
    return FALSE;
}
Logico queueIsEmpty(){
    if (count>0)
        return FALSE;
    return TRUE;
}
Logico queueIn(Tipo e){
    if (queueIsFull())
        return FALSE;
    if (queueIsEmpty()){
        primeiro = ultimo = 0;
        count = 1;
        vetoraux[ultimo] = e;
        return TRUE;
    }
    ultimo = (ultimo+1)%MAX;
    count++;
    vetoraux[ultimo] = e;
    return TRUE;
}
Logico queueOut(Tipo *e){
    if (queueIsEmpty())
        return FALSE;
    *e = vetoraux[primeiro];
    primeiro = (primeiro+1)%MAX;
    count--;
    return TRUE;
}
Logico queueCount(int *total){
    *total = count;
    return TRUE;
}
//*/
//*
typedef struct node{
    Tipo e;
    struct node * next;
} Node;

int count;

Node * primeiro;
Node * ultimo;

Logico queueCreate(){
    count=0;
    primeiro = ultimo = NULL;
    return TRUE;
}
Logico queueDestroy(){
    while (primeiro!=NULL){
        Node * aux = primeiro;
        primeiro = primeiro -> next;
        free(aux);
    }
    count = 0;
    primeiro = ultimo = NULL;
    return TRUE;
}
Logico queueIsFull(){
    return FALSE;
}
Logico queueIsEmpty(){
    if (count<=0)
        return TRUE;
    return FALSE;
}
Logico queueIn(Tipo e){
    if (count<=0){
        Node * aux = (Node*) malloc(sizeof(Node));
        aux -> e = e;
        aux -> next = NULL;
        primeiro = ultimo = aux;
        count = 1;
        return TRUE;
    }
    Node * aux = (Node*) malloc(sizeof(Node));
    aux -> e = e;
    aux -> next = NULL;
    ultimo -> next = aux;
    ultimo = aux;
    count++;
    return TRUE;
}
Logico queueOut(Tipo *e){
    if (count<=0)
        return FALSE;
    *e = primeiro -> e;
    Node * aux = primeiro;
    primeiro = primeiro -> next;
    free(aux);
    count--;
    return TRUE;

}
Logico queueCount(int *total){
    *total = count;
    return TRUE;
}
//*/

