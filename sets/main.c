#include "sets.h"
// TAD de conjuntos

// tratamento do que é diferente
// em Windows ou Linux
#ifdef WIN32
unsigned char pegaLetra(){
    return getchar();// = getchar();// no Linux
}

unsigned char ENTRA=13;

void limpaTela(){
    system("cls");// "clear" // no Linux
}

#elif LINUX
unsigned char pegaLetra(){
    return getchar();// no Linux
}

unsigned char ENTRA=10;

void limpaTela(){
    system("clear");// "clear" // no Linux
}

#endif // WIN32

// observe que a função aqui, no mundo da aplicacao
// sabe quem é Tipo e pode fazer a comparacao desejada
// Ex: comparacao de nomes de alunos, de números, de precos de mercadorias etc
Result compareTo(Tipo a, Tipo b){
    if (a > b) return GT;
    if (a == b) return EQUAL;
    return LT;
}

void imprime(Tipo t){
    printf("%i", t); // essa função sabe quem é Tipo, no caso, um inteiro
}


char conjuntoCorrente = 'A';
char conjuntosExibidos[]= {'A', 'B', 'C', 'D'};
void defineOrdemExibicaoConjuntos(){
    int tamanho = sizeof(conjuntosExibidos)/sizeof(char);
    int ix = -1;
    for (int i=0;i<tamanho;i++){
        if (conjuntoCorrente == conjuntosExibidos[i]){
            ix = i;
            break;
        }
    }
    if (ix==-1){
        for (int i=tamanho-1;i>0;i--){
            // cai de prioridade na lista
            conjuntosExibidos[i]=conjuntosExibidos[i-1];
        }
    } else {
        for (int i=ix;i>=0;i--){
            // cai de prioridade na lista
            conjuntosExibidos[i]=conjuntosExibidos[i-1];
        }
    }
    conjuntosExibidos[0]=conjuntoCorrente;
}


void menu(){
    limpaTela();

    defineOrdemExibicaoConjuntos();
    printf("Menu (m)\n");
    printf("Type int numbers followed by enter to add to current set\n");
    printf("Operations: \n");
    printf("e: end\n");
    printf("u: %c union %c -> %c\n", conjuntosExibidos[0], conjuntosExibidos[1], conjuntosExibidos[2]);
    printf("define first (current) set: A..Z \n");
    printf("current set: %c\n", conjuntoCorrente);
    printf("\nSets:\n");
    int tamanho = sizeof(conjuntosExibidos)/sizeof(char);
    for (int i=0;i<tamanho;i++){
        int total=0;
        setsNumberOfElements(conjuntosExibidos[i], &total);
        printf("total %d ", total);
        setsPrint(conjuntosExibidos[i]); // imprimir o conjunto
    }
    printf("\n\n");
}

void conjuntos(){
    char ch;
    char strNumero[100];
    int algarismo=0;
    int aux;
    int result;
    setsCreate(compareTo, imprime);
    menu();
    while (TRUE){
        char cA=conjuntosExibidos[0], cB=conjuntosExibidos[1], cC=conjuntosExibidos[2];
        ch = pegaLetra();
        if (ch == 'e'){
            break;
        } else if (((ch >= '0') && (ch <= '9')) || (ch == '.')){
            strNumero[algarismo++] = ch;
        } else if (ch  == 'm'){
            menu();
        } else if (ch == ','){
            strNumero[algarismo] = '\0';// terminador de string
            Tipo num = atoi(strNumero);
            //printf("\n%i\n",num);
            if (num != 0)
                setsAddElement(conjuntoCorrente, num);
            algarismo = 0;
            menu();
        } else if (ch == 'u'){
            // TODO operacoes
            setsUnion(cA, cB, cC);
            menu();
        } else if (ch == 'i'){// operacao intersecao
            setsIntersection(cA, cB, cC);
            menu();
        } else if (ch >= 'A' && ch <= 'Z'){
            conjuntoCorrente = ch;
            menu();
        } else if (ch == 'r'){
            scanf("%i", &aux);
            setsRemoveElement(cA, aux);
            menu();
        } else if (ch == 'c'){
            setsIsIn(cA, cB, &result);
            if (result == TRUE){
                menu();
                printf("TRUE\n");
            } else {
                menu();
                printf("FALSE\n");
            }
        } else if (ch == 'k'){
            scanf("%i", &aux);
            if (setsBelongsTo(cA, aux)){
                menu();
                printf("TRUE\n");
            } else {
                menu();
                printf("FALSE\n");
            }
        }
    }
    setsDestroy();
}

int main(){
    conjuntos();
}


