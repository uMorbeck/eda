#include <stdio.h>

main(){
    
    FILE *fp, *cpy;
    char ch;

    fp = fopen("miojo.txt", "r");
    cpy = fopen("miojo-de-carne.bin", "w");

    while (1){
        ch = fgetc(fp);

        if(ch == EOF){
            break;
        }    

        fputc(ch, cpy);
    }

    fputs("O de carne é o melhor >:(", cpy);

    fclose(fp);
    fclose(cpy);
    printf("Arquivo criado com sucesso (o de carne e melhor msm)\n");
}