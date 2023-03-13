#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p){
    int excluido = NULL;
    celula *aux;

    if(p->prox != NULL){
        excluido = p->prox->dado;
        aux = p->prox;
        p->prox = aux->prox;
        free(aux);
    }

    return excluido;
}

void remove_elemento(celula *le, int x){
    celula *elem;
    celula *aux;
    for(elem = le->prox; elem != NULL; elem = elem->prox){
        if(elem->dado == x){
            aux->prox = elem->prox;
            free(elem);
            break;
        }
        aux = elem;        
    }
}

void remove_todos_elementos (celula *le, int x){
    celula *elem;
    celula *aux;
    for(elem = le->prox; elem != NULL; elem = elem->prox){
        if(elem->dado == x){
            aux->prox = elem->prox;
            free(elem);
            elem = aux;
        }
        aux = elem;        
    }
}