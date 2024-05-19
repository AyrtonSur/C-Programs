#include "sets.h"

typedef struct node{
    Tipo e;
    struct node * next;
} Node;

#define MAX_SETS ('Z'-'A'+1)

Node* vetSets[MAX_SETS];
funcaoDeForaQueCompara compara;
funcaoDeForaQueImprime impri;



Logic setsCreate(funcaoDeForaQueCompara c, funcaoDeForaQueImprime i){
    compara = c;
    impri = i;
    for (int n = 0; n < MAX_SETS; n++){
        vetSets[n] = NULL;
    }
    return TRUE;
}

int mapa(char c1){
    if (c1 > 'A' || c1 < 'Z')
        return (int)(c1 - 'A');
    return -1;
}

Logic setsPrint(char letra){
    int ix = mapa(letra);
    if (ix < 0) return FALSE;
    Node * p1;
    p1 = vetSets[ix];

    printf("set(%c)->", letra);
    while (p1 != NULL){
        printf("[");
        Tipo aux = p1 -> e;
        impri(aux);
        printf("]->");
        p1 = p1 -> next;
    }
    printf("NULL\n");
    return TRUE;
}

Logic freeSet(char c1){
    int iaux = mapa(c1);
    if (iaux < 0) return FALSE;
    Node * pInicio = vetSets[iaux];
    while (pInicio != NULL){
        Node * aux = pInicio;
        pInicio = pInicio -> next;
        free(aux);
    }
    vetSets[iaux] = NULL;
    return TRUE;

}

Logic setsAddElement(char c1, Tipo e){
    int iaux = mapa(c1);
    if (iaux < 0)
        return FALSE;
    Node * pInicio = vetSets[iaux];
    if (pInicio == NULL){
        Node * aux = (Node*) malloc(sizeof(Node));
        aux -> e = e;
        aux -> next = NULL;
        vetSets[iaux] = aux;
        return TRUE;
    }
    Node * pAnterior = NULL;

    while (pInicio!= NULL){
        Result r = compara(e, pInicio -> e);
        if (r == LT){
            if (pAnterior == NULL){
                Node * aux = (Node*) malloc(sizeof(Node));
                aux -> e = e;
                aux -> next = vetSets[iaux];
                vetSets[iaux] = aux;
                return TRUE;
            }
            Node * aux = (Node*) malloc(sizeof(Node));
            aux -> e = e;
            aux -> next = pInicio;
            pAnterior -> next = aux;
            return TRUE;

        } else if (r == EQUAL) {
            return TRUE;
        } else {
        }
        pAnterior = pInicio;
        pInicio = pInicio -> next;
    }
    Node * aux = (Node*) malloc(sizeof(Node));
    aux -> e = e;
    aux -> next = NULL;
    pAnterior -> next = aux;
    return TRUE;
}

Logic setsRemoveElement(char c1, Tipo e){
    int iaux = mapa(c1);
    if (iaux < 0)
        return FALSE;
    Node * pInicio = vetSets[iaux];
    if (pInicio == NULL)
        return FALSE;
    Node * pAnterior = NULL;
    while (pInicio != NULL){
        Result r = compara(e, pInicio ->e);
        if (r == EQUAL){
            if (pAnterior == NULL){
                Node * aux = pInicio;
                pInicio = pInicio -> next;
                vetSets[iaux] = pInicio;
                free(aux);
                return TRUE;
            }
            Node * aux = pInicio;
            pInicio = pInicio -> next;
            pAnterior -> next = pInicio;
            free(aux);
            return TRUE;
        }
        pAnterior = pInicio;
        pInicio = pInicio -> next;
    }
    return FALSE;
}

Logic setsBelongsTo(char c1, Tipo e){
    int iaux = mapa(c1);
    if (iaux < 0) return FALSE;
    Node *pInicio = vetSets[iaux];
    if (pInicio == NULL) return FALSE;
    while (pInicio != NULL){
        Result r = compara(e, pInicio -> e);
        if (r == EQUAL)
            return TRUE;
        pInicio = pInicio -> next;
    }
    return FALSE;
}

Logic setsUnion(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1 < 0 || ix2 < 0 || ix3 < 0)
        return FALSE;
    Node * pInicio1 = vetSets[ix1];
    Node * pInicio2 = vetSets[ix2];
    freeSet(c3);
    while (pInicio1 != NULL && pInicio2 != NULL){
        Result r = compara(pInicio1 -> e, pInicio2 -> e);
        if (r == EQUAL){
            setsAddElement(c3, pInicio1 -> e);
            pInicio1 = pInicio1 -> next;
            pInicio2 = pInicio2 -> next;
        } else if (r == LT) {
            setsAddElement(c3, pInicio1 -> e);
            pInicio1 = pInicio1 -> next;
        } else {
            setsAddElement(c3, pInicio2 -> e);
            pInicio2 = pInicio2 -> next;
        }
    }
    while (pInicio1 != NULL){
        setsAddElement(c3, pInicio1 -> e);
        pInicio1 = pInicio1 -> next;
    }
    while (pInicio2 != NULL){
        setsAddElement(c3, pInicio2 -> e);
        pInicio2 = pInicio2 -> next;
    }
    return TRUE;
}

Logic setsIntersection(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1 < 0 || ix2 < 0 || ix3 < 0)
        return FALSE;
    Node * pInicio1 = vetSets[ix1];
    Node * pInicio2 = vetSets[ix2];
    freeSet(c3);
    while (pInicio1 != NULL && pInicio2 != NULL){
        Result r = compara(pInicio1 -> e, pInicio2 -> e);
        if (r == EQUAL){
            setsAddElement(c3, pInicio1 -> e);
            pInicio1 = pInicio1 -> next;
            pInicio2 = pInicio2 -> next;
        } else if (r == LT){
            pInicio1 = pInicio1 -> next;
        } else {
            pInicio2 = pInicio2 -> next;
        }
    }
    return TRUE;
}

Logic setsNumberOfElements(char c1, int *total){
    int ix = mapa(c1);
    if (ix < 0) return FALSE;
    int tot = 0;
    Node * pInicio = vetSets[ix];
    while (pInicio != NULL){
        tot++;
        pInicio = pInicio -> next;
    }
    *total = tot;
    return TRUE;
}

Logic setsIsIn(char c1, char c2, Logic *result){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    if (ix1 < 0 || ix2 < 0) return FALSE;
    int total1;
    int total2;
    setsNumberOfElements(c1, &total1);
    setsNumberOfElements(c2, &total2);
    if (total1 > total2){
        *result = FALSE;
        return FALSE;
    }
    Node * p1 = vetSets[ix1];
    Node * p2 = vetSets[ix2];
    while (p2 != NULL && p1 != NULL){
        Result r = compara(p1 -> e, p2 -> e);
        if (r == EQUAL){
            p2 = p2 -> next;
            p1 = p1 -> next;
        } else if (r == LT){
            break;
        } else {
            p2 = p2 -> next;
        }
    }
    if (p1 == NULL){
        *result = TRUE;
        return TRUE;
    }
    *result = FALSE;
    return FALSE;
}

Logic setsDestroy(){
    char ch = 'A';
    while (ch <= 'Z'){
        freeSet(ch);
        ch++;
    }
    return TRUE;
}
