#include "./lib/isPalavra.c"
#include "./lib/isDuplicado.c"

#define TRUE 1
#define FALSE 0

int main(){
    FILE *arquivo1, *vocabulo;
    char palavra[30], ch;
    fpos_t pos;

    arquivo1 = fopen("AcimaDoSol.txt", "r");
    vocabulo = fopen("AcimaDoSol_Vocabulo.txt", "w+");
    

    do {
        resetString(palavra);

        fscanf(arquivo1, "%s", palavra);

        for(int i = 0; i < 30; i++){
            palavra[i] = mais2minus(palavra[i]);
        }

        ch = fgetc(arquivo1);

        if(isPalavra(palavra) == TRUE){

            fgetpos(vocabulo, &pos);
            rewind(vocabulo);

            if(isDuplicado(vocabulo, palavra) == FALSE){
                fsetpos(vocabulo, &pos);
                fprintf(vocabulo, "%s\n", palavra);
            }
            
        }

        if(ch == EOF){
            break;
        }

    } while(TRUE);
    
    fclose(arquivo1);
    fclose(vocabulo);

    return 0;
}