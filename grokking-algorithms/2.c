#include <stdio.h>
#include <stdlib.h>

int smallest(int vet[], int n) {
    int small = vet[0];
    int small_idx = 0;
    for (int i = 1; i < n; i++) {
        if (vet[i] < small) {
            small = vet[i];
            small_idx = i;
        }
    }
    return small_idx;
}

int* ordenarSelecao(int vet[], int n) {
    int* aux = (int*)malloc(n * sizeof(int));
    int* novoVet = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) aux[i] = vet[i];

    int aux_n = n;
    for (int i = 0; i < n; i++) {
        int idx = smallest(aux, aux_n);
        novoVet[i] = aux[idx]; //wornking with the copy
        for (int j = idx; j < aux_n - 1; j++) {
            aux[j] = aux[j + 1];
        }
        aux_n--;
    }
    free(aux);
    return novoVet;
}

int main(){
    int vetor[5] = {5, 3, 6, 2, 10};
    int* ordenado = ordenarSelecao(vetor, 5);
    
    printf("[");
    for (int i = 0; i < 5; i++) {
        printf("%d", ordenado[i]);
        if (i < 4) printf (", ");
    }
    printf("]\n");
    free(ordenado);

    return 0;
}
