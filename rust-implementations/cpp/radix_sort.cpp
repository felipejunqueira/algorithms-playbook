#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void counting_sort_por_digito(vector<int>& dados, int exp) {
    int n = dados.size();
    vector<int> saida(n);

    // base decimal, maior digito eh 9, pequeno
    int base = 10;
    vector<int> contagem(base, 0);

    for (int i = 0; i < n; i++) {
        int digito_isolado = (dados[i] / exp) % base; // extrai exatamente o digito alvo
        contagem[digito_isolado]++;
    }  

    // prefix sum
    for (int i = 1; i < base; i++) contagem[i] += contagem[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digito_isolado = (dados[i] / exp) % base;
        int posicao_correta = contagem[digito_isolado] - 1;

        saida[posicao_correta] = dados[i];
        contagem[digito_isolado]--;
    }

    for (int i = 0; i < n; i++) dados[i] = saida[i];
}

// orquestrador interdimensional
void radix_sort(vector<int>& dados) {
    if (dados.empty()) return;

    // encontra o maior elemento para saber quantos digitos teremos que processar
    int max_val = *max_element(dados.begin(), dados.end());

    // mulitplica por 10 ate superar max_val
    for (int exp = 1; max_val / exp > 0; exp *= 10) 
        counting_sort_por_digito(dados, exp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // O array monstruoso que destruiu o Counting Sort puro agora não é nada.
    vector<int> A = {170, 45, 75, 90, 802, 24, 2, 66, 1000000000};
    
    cout << "Array Original: ";
    for (int x : A) cout << x << " "; cout << "\n";

    radix_sort(A);

    cout << "Array Ordenado (Radix Sort): ";
    for (int x : A) cout << x << " "; cout << "\n";

    return 0;
}