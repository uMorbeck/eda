#include <stdio.h>

int main(){
    
    char opcao[40];
    float resposta;
    float valor1, valor2;

    printf("Informe o primeiro valor");
    scanf("%f", valor1);
    printf("Informe o segundo valor");
    scanf("%f", valor2);
    printf("Qual operação deseja fazer? (a/s/m/d)");
    scanf("%c", opcao);

    switch (opcao[0]) {
        case 'a':
                resposta = adicao(valor1, valor2);
            break;
        
        case 's':
                resposta = subtracao(valor1, valor2);
            break;
        
        case 'm':
                resposta = multiplicacao(valor1, valor2);
            break;
        
        case 'd':
                resposta = divisao(valor1, valor2);
            break;
        
        default:
            printf("Valor não suportado, use (a/s/m/d)");
            return 0;
            break;
    }

    printf("A resposta é %f", resposta);

};

