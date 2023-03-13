#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtndNumeros;
    int numeroProibido;
    int *hashTable;
    int valor;

    scanf("%d", &qtndNumeros);

    hashTable = (int *) calloc(140001, sizeof(int));

    for (int i = 0; i < qtndNumeros; i++){
        scanf("%d ", &numeroProibido);
        hashTable[numeroProibido]++;
    }

    int *res = (int *) malloc(140001 * sizeof(int));
    int n = 0;

    while(scanf("%d", &valor) != EOF){
        if(hashTable[valor] != 0){
            res[n++] = 1;
        } else {
            res[n++] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        if(res[i] == 1){
            printf("sim\n");
        } else if(res[i] == 0){
            printf("nao\n");
        }
    }

    free(hashTable);
    free(res);

    return 0;
}
