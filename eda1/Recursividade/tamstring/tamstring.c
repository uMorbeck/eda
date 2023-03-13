#include <stdio.h>

int tamstring(char *string, int i);

int main() {
    // Se botar assentos, vai tudo pro saco
    char str[50] = "You know that's your blood that I bleed";
    int tam;

    tam = tamstring(str, 0);

    printf("a string '%s' tem %d caracteres\n", str, tam);

    return 0;
}

int tamstring(char *string, int i){
    
    if(string[i] >= 32 && string[i] <= 126){
        i++;
        return 1+tamstring(string, i);
    }
}