void resetString(char *string){
    for(int i = 0; i < 30; i++){
        string[i] = 0;
    }    
}

char mais2minus(char ch){
    if(ch >= 65 && ch <= 90){
        ch = ch + 32;
    }
    return ch;
}