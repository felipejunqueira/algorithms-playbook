// quicksort otimizado apra nao causar stack overflow. metade menor com recursao
// metade maior iterativamente

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int particionar_hoare(vector<int>& A, int inicio, int fim) {
    int pivo = A[inicio];
    int i = inicio - 1;
    int j = fim + 1;

    while (true) {
        do { i++; } while (A[i] < pivo);
        do { j--; } while (A[j] > pivo);
        if(i >= j) return j;
        std::swap(A[i], A[j]);
    }
}

// espaço O(log N) garantido no pior caso
void quicksort_log_space(vector<int>& A, int inicio_global, int fim_global) {
    // substituir o if da recursao por um laço iterativo p maior metade
    int inicio = inicio_global;
    int fim = fim_global;

    while(inicio < fim) {
        int indice_divisor = particionar_hoare(A, inicio, fim);
        int tamanho_esquerda = indice_divisor - inicio + 1;
        int tamanho_direita = fim - indice_divisor;

        if (tamanho_esquerda < tamanho_direita) {
            // no maximo log2(n) frames na pilha ao longo da execucao
            quicksort_log_space(A, inicio, indice_divisor);
            inicio = indice_divisor + 1;
        }
        else {
            quicksort_log_space(A, indice_divisor + 1, fim);
            // ajustamos o ponteiro de fim para que o laco while processe a esquerda iterativamente
            fim = indice_divisor;
        }
    }
}

int main() {
    vector<int> A = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    quicksort_log_space(A, 0, A.size() - 1);

    cout << "array ordenado: ";
    for (int x : A) cout << x << " ";
    cout << "\n";

    return 0;
}