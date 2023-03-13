#include <stdio.h>
#include "selectionSort.c"

int main() {
    
    FILE *dados, *ss;
    int valor[5565];
    char ch;

    dados = fopen("lista-dados.csv", "r");

    for(int i = 0; i < 5565; i++){
        fscanf(dados, "%d", &valor[i]);
        fgetc(dados);
    }
    
    selectionSort(valor, 5565);

    freopen("lista-dados.csv", "r", dados);

    for(int i = 0; i < 5565; i++){
        fscanf(dados, "%d", &valor[i]);
        fgetc(dados);
    }

    //bubblesort

    printf("\nselection sort: %d\n", contador);

    fclose(dados);
    return 0;
}