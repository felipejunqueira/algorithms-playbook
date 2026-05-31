#include <stdio.h>
#include <stdlib.h>

void quicksort(int* array, int ini, int fim){
    if (ini >= fim) return; //caso base

    int pivo = array[ini]; 
    int i = ini + 1; //caminhando pelos indices!
    int j = fim;
    int temp;

    //particiona o vetor
    while (i <= j){
        while (i <= fim && array[i] <= pivo) i++; //procura elemento maior que o pivo
        while (j > ini && array[j] > pivo) j--; //procura elemento menor que o pivo
        if (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    //coloca o pivo no lugar certo
    array[ini] = array[j];
    array[j] = pivo;

    //chamada recursiva para as duas metades
    quicksort(array, ini, j - 1);
    quicksort(array, j + 1, fim);
}


int main(){
    int array[] = {10, 5, 2, 3};
    int tam = sizeof(array) / sizeof(array[0]); //calcula o tam do vetor, o tam total(16 bytes) / tam do individual (4 bytes). 1 inteiro = 4 bytes = 8 bits

    quicksort(array, 0, tam - 1); //caminhamos pelos indices

    //imprime o vetor ordenado
    printf("[");
    for (int i = 0; i < tam; i++){
        printf("%d", array[i]);
        if (i < tam - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}

/* qsort padrao do C
int comparar(const void* a, const void* b) {
    return(*(int*)a - *(int*)b); 
}

int main(){
    int array[] = {10, 5, 2, 3};
    int tam = sizeof(array) / sizeof(array[0]);

    //usa qsort para ordenar o array
    qsort(array, tam, sizeof(int), comparar);

    //imprime o vetor ordenado
    for(int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

*/