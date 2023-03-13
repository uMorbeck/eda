#include <stdio.h>

typedef struct prof {
    int posx, posy;
} prof;

typedef struct resultado {
    int x, y, passo, tipo;
    char prof;
} resultado;

resultado result;

void verifica(prof *PA, prof *PB, int passo, int n, int m) {
    if(PA->posx > n || PA->posy > m || PA->posx == 0 || PA->posy == 0){
       result.prof = 'a';
       result.x = PA->posx;
       result.y = PA->posy;
       result.passo = passo;
       result.tipo = -1;
    } else if(PB->posx > n || PB->posy > m || PB->posx == 0 || PB->posy == 0){
       result.prof = 'b';
       result.x = PB->posx;
       result.y = PB->posy;
       result.passo = passo;
       result.tipo = -1;
    } else if(PA->posx == PB->posx && PA->posy == PB->posy){
        result.x = PA->posx;
        result.y = PB->posy;
        result.passo = passo;
        result.tipo = 1;
    } else {
        result.tipo = 0;
    }


}

void mudaPosicao(prof *prof, int passo) {
    switch (passo) {
    case 1:
        prof->posy++;
        break;
    case 2:
        prof->posy--;
        break;
    case 3:
        prof->posx++;
        break;
    case 4:
        prof->posx--;
        break;
    }
}

int main() {
    int n, m, passos, contaPassos = 1;
    int passoA, passoB;
    prof PA, PB;

    result.tipo = 0;

    scanf("%d %d", &n, &m);
    scanf("%d", &passos);

    PA.posx = PA.posy = 1;
    PB.posx = n;
    PB.posy = m;

    while (contaPassos <= passos) {
        scanf("%d %d", &passoA, &passoB);
        mudaPosicao(&PA, passoA);
        mudaPosicao(&PB, passoB);
        if(result.tipo == 0){
            verifica(&PA, &PB, contaPassos, n, m);
        }
        contaPassos++;
    }

    if(result.tipo == 0) {
        printf("Nao se encontraram\n");
    } else if(result.tipo == 1) {
        printf("Encontraram-se na posicao (%d,%d) no passo %d\n", result.x, result.y, result.passo);
    } else if(result.tipo == -1) {
        if(result.prof == 'a') {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", result.x, result.y, result.passo);
        } else if(result.prof == 'b'){
            printf("PB saiu na posicao (%d,%d) no passo %d\n", result.x, result.y, result.passo);
        }
    }

    return 0;
}