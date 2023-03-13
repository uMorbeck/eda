#include <stdio.h>
#include "../../lib/troca.h"

void troca(int *n1, int *n2);

int main(){
    int n1 = 10;
    int n2 = 20;

    troca(&n1, &n2);

    printf("%d %d", n1, n2);

    return 0;
};
