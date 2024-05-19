#include "ListaCircular.h"

typedef struct node {
    Tipo e;
    struct node * next;
    struct node * previous;
} Node;

int count;
Node * current;

funcaoDeForaQueImprime fun;
Logic fezGravacao;
char nomeArquivo[] = {"listacirc.bin"};

void grava(char *nomedoarquivo){
    if (count <=0) {
        remove(nomedoarquivo);
        return;
    }
    FILE *fp;
    fp = fopen(nomedoarquivo, "wb");
    Node *cur = current;
    cur = cur->next;
    while (cur != current){
        Tipo m = cur->e;
        fwrite(&m, sizeof(Tipo), 1, fp);
        cur = cur->next;
    }
    Tipo m = current->e;
    fwrite(&m, sizeof(Tipo), 1, fp);
    fclose(fp);
}


void recupera(char *nomedoarquivo){
    FILE *fp;
    fp = fopen(nomedoarquivo, "rb");
    if (fp == NULL) return;
    while (!feof(fp)){
        Tipo m;
        int itensLidos = fread(&m, sizeof(Tipo), 1, fp);
        if (itensLidos != 1)
            break;
        lcInsert(m);
    }
    fclose(fp);
}

Logic lcDestroy(){
    grava(nomeArquivo);
    fezGravacao = TRUE;
    while (lcIsEmpty() == FALSE){
        Tipo e;
        lcDelete(&e);
    }
}

Logic lcIsFull(){ // saber se está cheio
    return FALSE;
}

Logic lcIsEmpty(){ // saber se está vazio
    if (count <= 0)
        return TRUE;
    return FALSE;
}

Logic lcNext(){ // muda o corrente para o proximo
    if (lcIsEmpty)
        return FALSE;
    current = current -> next;
    return TRUE;
}

Logic lcPrevious(){ // muda o corrente para o anterior
    if (lcIsEmpty)
        return FALSE;
    current = current -> previous;
    return TRUE;
}

Logic lcCurrent(Tipo *e){ // retorna o elemento corrente da lista circular
    if (count<=0)
        return FALSE;
    *e = current -> e;
    return TRUE;
}

Logic lcInsert(Tipo e){ // remove elemento corrente, retornando-o
    if (count <= 0){
        current = (Node*) malloc(sizeof(Node));
        current -> e = e;
        current -> next = current;
        current -> previous = current;
        count++;
        return TRUE;
    }
    Node * aux = (Node*) malloc(sizeof(Node));
    Node * anterior = current;
    Node * proximo = current-> next;
    aux -> e = e;
    aux -> next = proximo;
    aux -> previous = anterior;
    anterior -> next = aux;
    proximo -> previous = aux;
    current = aux;
    count++;
    return TRUE;

}

Logic lcDelete(Tipo *e){// remove elemento corrente, retornando-o opcionalmente, o corrente passa a ser o proximo
     if (count<=0)
        return FALSE;
     *e = current -> e;
     if (count==1){
        free(current);
        current=NULL;
        count = 0;
        return TRUE;
     }
     Node * proximo = current -> next;
     Node * anterior = current -> previous;
     free(current);
     anterior -> next = proximo;
     proximo -> previous = anterior;
     current = proximo;
     count--;
     return TRUE;
}

Logic lcCount(int *total){ //retorna o total de elementos da lista circular
     *total = count;
     return TRUE;
}


Logic lcPrint(){
    Node *p1;
    p1 = current;

    printf("(%i)current->", count);
    if (current == NULL){
        printf("NULL");
        return TRUE;
    }
    while (p1 != NULL){
        printf("[");
        Tipo aux = p1->e;
        fun(aux);
        printf("]->");
        p1 = p1->next;
        if (p1 == current || p1 == NULL){
            break;
        }
    }
    printf("current\n");
    return TRUE;
}

Logic lcCreate(funcaoDeForaQueImprime f){ // inicializacoes
    current = NULL;
    count = 0;
    fun = f;
    fezGravacao = FALSE;
    recupera(nomeArquivo);
    return TRUE;
}
