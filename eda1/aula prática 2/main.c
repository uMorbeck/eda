#include "codigos.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp, *rlt;
    int *array;
    float qtb, qti;
    float mediaqtb, mediaqti = 0;

    fp = fopen("testes3.txt", "r");
    rlt = fopen("esforcocomputacional.txt", "w"); 
    
    do{
        int tamarray;
        fscanf(fp, "%d", &tamarray);

        array = (int*) malloc(tamarray*sizeof(int));

        for(int i = 0; i < tamarray; i++){
            array[i] = rand();
        }

        qtb = bs(tamarray, array);

        mediaqtb = qtb/tamarray;

        fprintf(rlt, "%d,%.2f,%.2f\n", tamarray, mediaqtb, mediaqti);
        free(array);
        
    }while(fgetc(fp) != EOF);

    fclose(fp);
    fclose(rlt);
    return 0;
}