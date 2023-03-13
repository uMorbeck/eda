#include <stdio.h>
#include <stdlib.h>

int resultado[800008], vetor[100001];

int intercala(int *a, int tamA, int *b, int tamB);

int main() {
    int tam;
    int x = 0;

    for(int i = 0; i < 8; i++){
        tam = 0;
        scanf("%d", &tam);
        for(int j = 0; j < tam; j++){
            scanf("%d", &vetor[j]);
        }
        intercala(resultado, x, vetor, tam);
        x += tam;
    }

    printf("%d", resultado[0]);
    for(int i = 1; i < x; ++i){
        printf(" %d", resultado[i]);
    }
    printf("\n");

    return 0;
}

int intercala(int *a, int tamA, int *b, int tamB)
{
    int *temp = (int *) malloc((tamA + tamB) * sizeof(int));
    int i, j, k = 0;

    for (i = 0, j = 0; i < tamA && j < tamB; k++) {
        if (a[i] <= b[j]) {
            temp[k] = a[i++];
        } else {
            temp[k] = b[j++];
        }
    }

    while (i < tamA) {
        temp[k++] = a[i++];
    }
    while (j < tamB) {
        temp[k++] = b[j++];
    }

    for (k = 0, i = 0; i < (tamA + tamB); i++, k++){
        a[i] = temp[k];
    }

    free(temp);
}
