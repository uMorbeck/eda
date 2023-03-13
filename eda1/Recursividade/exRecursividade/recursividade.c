#include <stdio.h>

// Recursividade é quando uma função chama ela mesma e possui uma condição de parada
// Muito necessário a condição de parada, para não haver uma loop infinita

int fatorial(int n);

int main(){
    int f;
    int v;

    printf("infome o valor ao qual o fatorial será aplicado: ");
    scanf("%d", &v);

    f = fatorial(v);

    printf("valor fatorial de %d, é igual a %d\n", v, f);

    return 0;
}

int fatorial(int n){
    if(n == 0){
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}