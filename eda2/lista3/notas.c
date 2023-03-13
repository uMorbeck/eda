#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[1010];
    int qntdAlunos;
    int notaFreq = 0, maiorRep = 0;
    scanf(" %d", &qntdAlunos);

    for (int i = 0; i < qntdAlunos; i++) {
        int nota;
        scanf(" %d", &nota);

        if (++v[nota] > maiorRep) {
            maiorRep = v[nota];
            notaFreq = nota;
        } else if (v[nota] == maiorRep && notaFreq < nota) {
            notaFreq = nota;
        }
    }
    
    printf("%d\n", notaFreq);

    return 0;
}