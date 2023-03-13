#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dados {
    int quantidade;
    int posicao;
    char letra;
} Dados;

void mergesort(Dados *v, int e, int d);
void merge(Dados *v, int e, int meio, int d);

int main() {
    char frase[100001];
    int j = 0;
    int z = 0;

    scanf("%s", frase);
    Dados a[strlen(frase)];
    a[z].quantidade = 0;
    
    for (int i = 0; i < strlen(frase); i++) {
        if (frase[j] != frase[i]) {
            j = i;
            z++;
            a[z].quantidade = 0;
        }

        a[z].quantidade++;
        a[z].posicao = j;
        a[z].letra = frase[j];
    }

    mergesort(a, 0, z);

    for (int i = z; i >= 0; i--) {
        printf(" %d %c %d\n", a[i].quantidade, a[i].letra, a[i].posicao);
    }

    return 0;
}

void mergesort(Dados *v, int e, int d) {
    if (e >= d)
        return;
    int meio = (e + d) / 2;
    mergesort(v, e, meio);
    mergesort(v, meio + 1, d);
    merge(v, e, meio, d);
}

void merge(Dados *v, int e, int meio, int d) {
    Dados *temp = malloc(sizeof(Dados) * (d - e + 1));
    int k = 0;
    int i = e;
    int j = meio + 1;
    
    while (i <= meio && j <= d) {
        if (v[i].quantidade < v[j].quantidade) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = v[i++];
    }

    while (j <= d) {
        temp[k++] = v[j++];
    }

    k = 0;

    for (i = e; i <= d; i++) {
        v[i] = temp[k++];
    }

    free(temp);
}