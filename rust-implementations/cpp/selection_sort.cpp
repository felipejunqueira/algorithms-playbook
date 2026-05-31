#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& dados) {
    int n = dados.size();
    // 'i' eh a posicao atual que estamos tentando preencher com o valor correto
    for (int i = 0; i < n-1; ++i) {
        int idx_smallest = i;
        // varrer buscando alguem menor
        for (int j = i + 1; j < n; ++j) 
            if (dados[j] < dados[idx_smallest]) idx_smallest = j;
        
        // se o menor elemento que encontramos nao for o que estava na posicao i
        // fazemos a troca manual
        if (idx_smallest != i) swap(dados[i], dados[idx_smallest]);
    }
}

int main() {
    vector<int> stream_de_dados = {64, 25, 12, 22, 11};

    cout << "Array Original: ";
    for (int x : stream_de_dados) cout << x << " ";
    cout << "\n";

    selection_sort(stream_de_dados);

    cout << "Array Ordenado (Selection): ";
    for (int x : stream_de_dados) cout << x << " ";
    cout << "\n";

    return 0;
}