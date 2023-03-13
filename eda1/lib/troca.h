#ifndef Troca_h

void troca(int *a1, int *a2){
    int aux;

    aux = *a2;
    *a2 = *a1;
    *a1 = aux;

};

#endif

