#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void counting_sort_estavel(vector<int>& dados) {
    if (dados.empty()) return;

    // encontrar o limite do universo (K) para alocar memoria exata
    int max_val = *max_element(dados.begin(), dados.end());

    vector<int> contagem(max_val + 1, 0); // +1 pq eh zero indexado

    for (int x : dados) contagem[x]++;

    // transmutacao matematica (prefix sum) em Theta(K)
    // contagem passa a armazenar o numero exato de elementos que sao <= i
    for (int i = 1; i <= max_val; ++i) contagem[i] += contagem[i - 1];

    // preenchimento estrito e estavel
    vector<int> saida(dados.size());

    // iteracao reversa. estabilidade. ler de tras p frente
    for (int i = dados.size() - 1; i >= 0; --i) {
        int valor_atual = dados[i];

        // a contagem diz a posicao (1-based), entao subtraimos 1 para o 0-based
        int posicao_correta = contagem[valor_atual] - 1;

        saida[posicao_correta] = valor_atual;

        // decrementamos a contagem para que, se houver outro elemento igual no passado
        // ele seja colocado uma posicao antes (esquerda) deste
        contagem[valor_atual]--;
    }
    // sincronizacao final com a RAM
    dados = saida;
}

int main() {
    vector<int> A = {4, 2, 2, 8, 3, 3, 1, 4, 8};
    
    cout << "Array Original: ";
    for (int x : A) cout << x << " "; cout << "\n";

    counting_sort_estavel(A);

    cout << "Array Ordenado (Counting Sort Estável): ";
    for (int x : A) cout << x << " "; cout << "\n";

    return 0;
}