#include "MatLib.h"

int main(){
    printf("Digite os coeficiente a, b e c da equacao: ");
    double a, b ,c; //coeficiente do 2 grau
    double raiz1, raiz2; //raizes que serão calculadas
    int status; //o status da equação(se tem 2 raizes, 1 raiz etc)
    scanf("%lf %lf %lf", &a, &b, &c);
    Raizes * resultado;
    resultado = Bhaskara(a, b ,c);
    raiz1=(*resultado).raiz1;
    raiz2=(*resultado).raiz2;
    status=(*resultado).status;
    if (status==TWO_ROOTS){
        printf("Raiz1: %lf\nRaiz2: %lf\n", raiz1, raiz2);
        //tem 2 raízes real
    } else if (status==ONE_ROOT) {
        printf("Raiz: %lf\n", raiz1);
        //tem 1 raiz real
    } else if (status==NO_ROOTS) {
        printf("Nao tem raizes\n");
        //não tem raiz real
    } else if (status== NOT_2ND_DEGREE){
        printf("Nao e equacao do 2 grau\n");
    } //não é equação do 2 grau
    free(resultado);
    return 0;
}
