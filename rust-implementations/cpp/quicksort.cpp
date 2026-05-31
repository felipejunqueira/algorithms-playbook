#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

// usando particionamento de Hoare, antes da recursao
int particionar_hoare(vector<int>& A, int inicio, int fim) {
    // nao eh o melhor pivo, serve por enquanto
    int pivo = A[inicio];
    
    int i = inicio - 1;
    int j = fim + 1;

    while (true) {
        do { i++; } while(A[i] < pivo);
        do { j--; } while(A[j] > pivo);
        // se os ponteiros cruzarem, segregacao terminou
        if (i >= j) return j;
        std::swap(A[i], A[j]);
    }
}

void quicksort(vector<int>& A, int inicio, int fim) {
    if (inicio < fim) {
        int indice_divisor = particionar_hoare(A, inicio, fim);

        // o pivo nao fica necessariamente no indice_divisor, a garantia
        // eh apenas que os sub-arrays estao segragados
        quicksort(A, inicio, indice_divisor);

        // agr conquista a direita
        quicksort(A, indice_divisor + 1, fim);
    }
}

int main() {
    vector<int> A = {34, 7, 23, 32, 5, 62, 32, 1, 10};

    cout << "Original: ";
    for (int x : A) cout << x << " ";
    cout << "\n";

    quicksort(A, 0, A.size() - 1);

    cout << "Ordenado: ";
    for (int x : A) cout << x << " ";
    cout << "\n";

    return 0;
}
