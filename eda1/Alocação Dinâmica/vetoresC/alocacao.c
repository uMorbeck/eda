#include "../../lib/VetoresC.h"
#include <stdio.h>

int main(){
    int tam;
    int *vet1;

    printf("informe o tamanho do vetor de inteiros: ");
    scanf("%d", &tam);

    vet1 = CriaVetInt(tam);

    for(int i = 0; i < tam; i++){
        printf("informe o valor da %d casa: ", i+1);
        scanf("%d", &vet1[i]);
    }
        printf("\nordem invertida: ");
    for(int i = tam - 1; i >= 0; i--){
        printf("%d ", vet1[i]);
    }
    free(vet1);    

    return 0;
}