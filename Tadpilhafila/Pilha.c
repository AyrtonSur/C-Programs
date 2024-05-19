#include "Pilha.h"

/*#define MAX 4

int count;
Tipo vetor[MAX];
int last;

Logico stCreate(){
    count = 0;
    last = -1;
}
Logico stDestroy(){
    count = 0;
    last = -1;
}
Logico stIsFull(){
    if (count>=MAX)
        return TRUE;
    return FALSE;

}
Logico stIsEmpty(){
    if (count > 0)
        return FALSE;
    return TRUE;

}
Logico stPush(Tipo e){
    if (stIsFull())
        return FALSE;
    last++;
    vetor[last] = e;
    count++;
    return TRUE;
}
Logico stPop(Tipo *e){
    if (stIsEmpty())
        return FALSE;
    *e = vetor[last];
    last--;
    count++;
    return TRUE;

}
Logico stCount(int *total){
    *total = count;
    return TRUE;
}
//*/

typedef struct node{
    Tipo e;
    struct node * previous;
} Node;

Node *current;
int count;

Logico stCreate(){
    count = 0;
    current = NULL;
    return TRUE;
}
Logico stDestroy(){
    while (current != NULL){
        Node *aux = current;
        current = current -> previous;
        free(aux);
    }
    count=0;
    return TRUE;
}
Logico stIsFull(){
    return FALSE;
}
Logico stIsEmpty(){
    if (count<=0)
        return TRUE;
    return FALSE;
}
Logico stPush(Tipo e){
    if (count<=0){
        count = 1;
        current = (Node*) malloc(sizeof(Node));
        current -> e = e;
        current -> previous = NULL;
        return TRUE;
    }
    Node *aux = (Node*) malloc(sizeof(Node));
    aux -> e = e;
    aux -> previous = current;
    current = aux;
    count++;
    return TRUE;
}
Logico stPop(Tipo *e){
    if (count<=0)
        return FALSE;
    *e = current -> e;
    Node *aux = current;
    current = current -> previous;
    free(aux);
    count--;
    return TRUE;
}
Logico stCount(int *total){
    *total = count;
    return TRUE;
}
