#include <stdio.h>

void selectionsort(int n, int v[])
{
    for (int i = 0; i < n - 1; ++i){
        int min = i;
        for (int j = i + 1; j < n; ++j){
            if (v[j] < v[min]){
                min = j;
            }
        }
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

void main(){
    int valor[1001];
    int i;

    for(i = 0; scanf("%d", &valor[i]) != EOF; i++);

    selectionsort(i, valor);

    for (int k = 0; k < i; k++){
        printf("%d", valor[k]);
        if (k != i-1){
            printf(" ");
        } else {
            printf("\n");
        }
    }
}