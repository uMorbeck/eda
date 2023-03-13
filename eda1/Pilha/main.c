#include <stdio.h>

typedef struct no{
    char caracter;
    struct no *proximo;
} No;

// Função identifica_formacao
// Assinatura: int identifica_formacao(char x[]);
// Retorno:
//   0 - Caso a expressão de entrada está bem formada
//   1 - Caso a expressão de entrada não esteja bem formada

int identifica_formacao(char x[]){
    No *pilha, *novoNo;
    
    pilha = (No*) malloc(sizeof(No));
    pilha->proximo = NULL;
    
}

int main(){
    char exp[50];

    printf("\tDigite um expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n", exp, identifica_formacao(exp));
}