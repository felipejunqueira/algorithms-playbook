#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& dados) {
    int n = dados.size();
    // 0 ou 1 elementos ja estao ordenados
    for (int i = 1; i < n; ++i) {
        int atual = dados[i];
        int j = i - 1;
        // elementos maiores que atual para a direita. menores pra esquerda
        // j >= 0 protege contra memory bound
        // dados[j] > atual garante a estabilidade do algoritmo
        while (j >= 0 && dados[j] > atual) {
            dados[j + 1] = dados[j];
            j--;
        }
        // inserimos na posicao correta, quando o laco termina
        dados[j + 1] = atual;
    }
}

int main() {
    vector<int> dados = {9, -3, 5, 2, 6, 8, -6, 1, 3};

    cout << "Array Original: ";
    for (int x : dados) cout << x << " ";
    cout << "\n";

    insertion_sort(dados);

    cout << "Array Ordenado: ";
    for (int x : dados) cout << x << " ";
    cout << "\n";

    return 0;
}