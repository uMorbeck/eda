#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
#define less(a, b) (a.value == b.value ? a.key > b.key : a.value > b.value)
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)

typedef struct Item{
    int key, value;
} Item;

int particiona(Item *v, int e, int d) {
    Item pivot = v[d];
    int j = e;
    for (int k = e; k < d; k++){
        if (less(v[k], pivot)) {
            swap(v[k], v[j]);
            j++;
        }
    }

    swap(v[j], v[d]);
    
    return j;
}

void quicksort(Item *v, int e, int d) {
    if (d <= e)
        return;

    cmpswap(v[(e + d) / 2], v[d]);
    cmpswap(v[e], v[(e + d) / 2]);
    cmpswap(v[d], v[(e + d) / 2]);

    int m = particiona(v, e, d);
    quicksort(v, e, m - 1);
    quicksort(v, m + 1, d);
}

Item ps[91], ss[901], dfs[9001], des[90001];
int pn = 0, sn = 0, dfn = 0, den = 0;

int main() {
    long long s, f, e;
    scanf(" %lld %lld %lld", &s, &f, &e);

    long long valid = 0, invalid = 0, totalp = 0;
    for (int x, l; scanf("%d%n", &x, &l) == 1;) {
        if (x < 0) {
            invalid++;
            continue;
        }

        switch (l) {
            case 3:
                ps[x - 10].key = x;
                ps[x - 10].value++;
                totalp++;
                break;
            case 4:
                ss[x - 100].key = x;
                ss[x - 100].value++;
                break;
            case 5:
                dfs[x - 1000].key = x;
                dfs[x - 1000].value++;
                break;
            default:
                des[x - 10000].key = x;
                des[x - 10000].value++;
        }

        valid++;
    }

    for (int i = 0; i < 91; i++) {
        if (ps[i].value){
            ps[pn++] = ps[i];
        }
    }
    for (int i = 0; i < 901; i++) {
        if (ss[i].value) {
            ss[sn++] = ss[i];
        }
    }
    for (int i = 0; i < 9001; i++) {
        if (dfs[i].value) {
            dfs[dfn++] = dfs[i];
        }
    }
    for (int i = 0; i < 90001; i++) {
        if (des[i].value) {
            des[den++] = des[i];
        }
    }
    printf("%lld %lld\n", valid, invalid);

    quicksort(ps, 0, pn - 1);
    quicksort(ss, 0, sn - 1);
    quicksort(dfs, 0, dfn - 1);
    quicksort(des, 0, den - 1);

    if ((double)ps[0].value / totalp >= .51) {
        printf("%d\n", ps[0].key);
    } else {
        printf("Segundo turno\n");
    }

    for (int i = 0; i < s; i++) {
        printf("%d%c", ss[i].key, " \n"[i == s - 1]);
    }
    for (int i = 0; i < f; i++){
        printf("%d%c", dfs[i].key, " \n"[i == f - 1]);
    }
    for (int i = 0; i < e; i++){
        printf("%d%c", des[i].key, " \n"[i == e - 1]);
    }
    return 0;
}