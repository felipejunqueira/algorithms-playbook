#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binary_insertion_sort(vector<int>& dados) {
    int n = dados.size();
    for (int i = 1; i < n; ++i) {
        int atual = dados[i];

        // busca binaria
        // upper_bound retorna iterador p o primeiro elemento que eh estritamente maior que atual
        // isso garante estabilidade do alg. total de \Theta{log i} comparacoes
        auto iterador_pos = std::upper_bound(dados.begin(), dados.begin() + i, atual);
        int pos_destino = std::distance(dados.begin(), iterador_pos);

        // deslocamento bruto (gargalo quadratico)
        // movemos o bloco de memoria de [pos_dest ... i - 1] para [pos_dest + 1 ... i]
        // no hardware, isso compila SIMD rapidamente, mas continua \Theta{N^2}
        for (int j = i; j > pos_destino; --j) dados[j] = dados[j - 1];
        
        dados[pos_destino] = atual;
    }
}

int main() {
    vector<int> dados = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};

    binary_insertion_sort(dados);

    cout << "Array Ordenado (Binary Insertion): ";
    for (int x : dados) cout << x << " ";
    cout << "\n";

    return 0;
}