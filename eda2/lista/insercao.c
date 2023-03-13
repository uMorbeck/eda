#include <stdio.h>
#include <stdlib.h>
#include "imprime.c"

// typedef struct celula {
//     int dado;
//     struct celula *prox;
// } celula;

void insere_inicio(celula *le, int x){
    if(le->prox == NULL){
        celula *nova = malloc(sizeof(celula));
        nova->dado = x;
        nova->prox = NULL;
        le->prox = nova;
    } else {
        celula *nova = malloc(sizeof(celula));
        nova->dado = x;
        nova->prox = le->prox;
        le->prox = nova;
    }
}

void insere_antes(celula *le, int x, int y){
    celula *elem;
    celula *anterior;

    for(elem = le->prox; elem != NULL; elem=elem->prox){
        if(elem->dado == y){
            celula *nova = malloc(sizeof(celula));
            nova->dado = x;
            nova->prox = elem;
            anterior->prox = nova;
            break;
        }
        if(elem->prox == NULL){
            celula *nova = malloc(sizeof(celula));
            nova->dado = x;
            nova->prox = NULL;
            elem->prox = nova;
            break;
        }
        anterior = elem;
    }
}