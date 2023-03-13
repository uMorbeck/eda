#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int e, int d, int meio){
    int vetorAux[d - e + 1];
    int i = e;
    int j = meio + 1;
    int k = 0;
    int p;

    while (i <= meio && j <= d){
        if (vetor[i] <= vetor[j]){
            vetorAux[k++] = vetor[i++];
        }else{
            vetorAux[k++] = vetor[j++];
        }
    }

    while (i <= meio){
        vetorAux[k++] = vetor[i++];
    }
    while (j <= d){
        vetorAux[k++] = vetor[j++];
    }

    int v = 0;
    for (p = e; p <= d; ++p){
        vetor[p] = vetorAux[v++];
    }
}

void mergeSort(int *vetor, int e, int d)
{
    if (e >= d)
        return;

    int meio = e + (d - e) / 2;
    mergeSort(vetor, e, meio);
    mergeSort(vetor, meio + 1, d);
    merge(vetor, e, d, meio);
}

int main()
{
    int vetor[100000 + 66], i = 0, k;

    while (scanf("%d", &vetor[i++]) != EOF)
    {
    }

    --i;

    mergeSort(&vetor[0], 0, i - 1);

    printf("%d", vetor[0]);
    for (k = 1; k < i; ++k)
    {
        printf(" %d", vetor[k]);
    }
    printf("\n");
    return 0;
}