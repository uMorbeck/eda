#include <stdio.h>
#include <string.h>
#include "tratarString.c"

#define TRUE 1
#define FALSE 0

int isDuplicado(FILE* arquivo, char *palavra){
    int boolean = FALSE;
    char duplicado[30];

    do {
        resetString(duplicado);
        fscanf(arquivo, "%s", duplicado);
        char ch = fgetc(arquivo);

        if(strcmp(palavra, duplicado) == 0){
            boolean = TRUE;
        }

        if(ch == EOF){
            break;
        }
    } while(TRUE);

    return boolean;
}