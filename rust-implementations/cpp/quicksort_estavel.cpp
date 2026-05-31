// quicksort estavel com tuplas e mais espaço

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// aumento estrutural, historia carregada
// antes era int de 4 bytes, agr struct de 8 bytes
struct Elemento {
    int valor;
    int indice_original;
};

// novo oraculo de comparacao (regra de desempate léxico)
bool estritamente_menor(const Elemento& a, const Elemento& b) {
    if (a.valor != b.valor) return a.valor < b.valor;
    return a.indice_original < b.indice_original; 
}

bool estritamente_maior(const Elemento& a, const Elemento& b) {
    if (a.valor != b.valor) return a.valor > b.valor;
    return a.indice_original > b.indice_original;
}

int particionar_estavel(vector<Elemento>& A, int inicio, int fim) {
    int meio = inicio + (fim - inicio) / 2; // std::midpoint(inicio, fim) C++20
    Elemento pivo = A[meio];

    int i = inicio - 1;
    int j = fim + 1;
    while (true) {
        do { i++; } while(estritamente_menor(A[i], pivo));
        do { j--; } while(estritamente_maior(A[j], pivo));
        if (i >= j) return j;
        std::swap(A[i], A[j]);
    }   
}

void quicksort_estavel(vector<Elemento>& A, int inicio, int fim) {
    if (inicio < fim) {
        int indice_divisor = particionar_estavel(A, inicio, fim);
        quicksort_estavel(A, inicio, indice_divisor);
        quicksort_estavel(A, indice_divisor + 1, fim);
    }
}

int main() {
    vector<int> dados_brutos = {9, 4, 5, 8, 1, 8, 6, 7, 2, 4};
    int n = dados_brutos.size();

    // transmutacao porque nao mudamos o algoritmo em si, apenas a estrutura dele
    vector<Elemento> dados_aumentados(n);
    for (int i = 0; i < n; ++i) 
        dados_aumentados[i] = {dados_brutos[i], i};

    quicksort_estavel(dados_aumentados, 0, n - 1);

    cout << "array original: ";
    for (int x : dados_brutos) cout << x << " ";
    cout << "\n";

    cout << "Array Ordenado Estavelmente (Valor [Indice Original]):\n";
    for (const auto& el : dados_aumentados) 
        cout << el.valor << " [" << el.indice_original << "]   ";
    cout << "\n";

    return 0;
}