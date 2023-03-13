#define TRUE 1
#define FALSE 0

int isPalavra(char *string){
    int letras = 0;
    int boolean = FALSE;
    int n = FALSE;

    for(int i = 0; i < 30; i++){
        if(string[i] != 0){
            letras++;
        }
        
        if(string[i] == 0){
            break;
        }
        
        if(string[i] < 97 || string[i] > 122){
            letras--;
            n = TRUE;
            if (string[i] == 44){
                n = FALSE;
            } 
        }
    }

    if(letras > 3 || letras == 3 && n == TRUE){
        boolean = TRUE;
    }

    return boolean;
}