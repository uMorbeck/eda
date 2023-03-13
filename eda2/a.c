#include <stdio.h>

int main() {
    int a = 5, b = 5;
    int *p;
    int *q;
    p = &a;
    q = &b;
    int c = *p + *q;

    printf("%d\n", c);

    return 0;
}