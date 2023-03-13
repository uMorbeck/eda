#include <stdio.h>

int aoooooPotencia(int x,int y);

int main(){
    int x, y, result;

    printf("informe o valor da base: ");
    scanf("%d", &x);

    printf("informe o valor do expoente: ");
    scanf("%d", &y);

    result = aoooooPotencia(x, y);

    printf("\n%d\n", result);

    return 0;
}

int aoooooPotencia(int x,int y){
    if(y == 0){
        return 1;
    } else {
        return x * aoooooPotencia(x, y-1);
    }
}