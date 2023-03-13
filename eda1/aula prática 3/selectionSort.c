int contador = 0;

int smallerIndex(int vet[], int tam, int ini){
    int min = ini, j;
    for(j=ini+1; j<tam; j++){
        contador++;
        if(vet[min] > vet[j])
            min = j;
    }

    return min;
}

selectionSort(int vet[], int tam){
    int i, min, aux;
    for(i=0; i<tam; i++){
//Acha posicao do menor elemento a partir de i:
        contador++;
        min = smallerIndex(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
    
}