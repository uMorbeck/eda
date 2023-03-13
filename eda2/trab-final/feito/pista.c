#include <stdio.h>

typedef struct pista {
    int id;
    int valor;
    int prox;
} pista;

int main() {

    int qntd = 1;
    scanf("%d", &qntd);

    pista lista[qntd];

    scanf("%d %d %d", &lista[0].id, &lista[0].valor, &lista[0].prox);

    for(int i = 1; i < qntd; i++){
        scanf("%d %d %d", &lista[i].id, &lista[i].valor, &lista[i].prox);
    }

    printf("%d\n", lista[0].valor);
    int proxPista = lista[0].prox; 

    while(proxPista != -1){
        for(int i = 1; i < qntd; i++){
            if(proxPista == lista[i].id){
                printf("%d\n", lista[i].valor);
                proxPista = lista[i].prox;
                break;
            }
        }
    }

    return 0;
}