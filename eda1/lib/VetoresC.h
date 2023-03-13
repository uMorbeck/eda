#ifndef VetoresC
#include <stdio.h>
#include <stdlib.h>

int *CriaVetInt(int i){
    int *ptr;

    ptr = (int*) malloc(i*sizeof(int));

    return ptr;
}

float *CriaVetFloat(int i){
    float *ptr;

    ptr = (float*) malloc(i*sizeof(float));

    return ptr;
}

#endif