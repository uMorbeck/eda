#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char str[101];
    struct celula *prox;
} celula;

char cmd[9];
char str[101];

void insere_inicio(celula *pilha, char *str) {

    if(pilha->prox == NULL){
        celula *novo = malloc(sizeof(celula));
        novo->prox = NULL;
        pilha->prox = novo;
        strcpy(novo->str, str);
    } else {
        celula *novo = malloc(sizeof(celula));
        pilha->prox = novo;
        novo->prox = pilha->prox;
        strcpy(novo->str, str);
    }
}

char *remove_inicio(celula *pilha){
    if(pilha->prox != NULL){
        celula *aux;
        strcpy(str, pilha->prox->str);
        aux = pilha->prox;
        pilha->prox = aux->prox;
        free(aux);
        return str;
    } else {
        return "NULL";
    }
}

int main() {
    celula *pilha = (celula*) malloc(sizeof(celula));
    pilha->prox = NULL;


    while(scanf("%s", cmd) != EOF){
        if(strcmp(cmd, "inserir") == 0){
            scanf(" %100[^\n]", str);
            insere_inicio(pilha, str);
        } else if(strcmp(cmd, "desfazer") == 0){
            printf("%s\n", remove_inicio(pilha));
        }
    }

    while(strcmp(remove_inicio(pilha), "NULL") != 0);

    free(pilha);

    return 0;
}