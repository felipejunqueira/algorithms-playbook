#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

long long kadane_com_anistia(const vector<int>& dados) {
    int n = dados.size();
    if (n == 0) return 0;
    else if (n == 1) return dados[0]; // nao ha o que deletar sem esvaziar (assumo sub-array n vazio)

    vector<long long> L(n);
    vector<long long> R(n);

    // o passado da esq p direita
    L[0] = dados[0];
    long long max_sem_delecao = L[0];
    for (int i = 1; i < n; ++i) {
        L[i] = max((long long)dados[i], L[i-1] + dados[i]);
        max_sem_delecao = max(max_sem_delecao, L[i]);
    }

    // o futuro da dir p esq
    R[n-1] = dados[n-1];
    for (int i = n - 2; i >= 0; --i) {
        R[i] = max((long long)dados[i], R[i+1] + dados[i]);
    }

    // o colapso
    long long max_com_delecao = numeric_limits<long long>::min();

    // iteramos de 1 ate n-2 pq nao faz sentido deletar as bordas com
    // a intencao de unir passado e futuro (se deletar a borda eh apenas kadane normal)
    for (int i = 1; i < n - 1; ++i) {
        // unindo o melhor passado (ate i-1) com o melhor futuro (desde i+1)
        long long soma_ponte = L[i-1] + R[i+1];
        max_com_delecao = max(max_com_delecao, soma_ponte);
    }

    return max(max_sem_delecao, max_com_delecao);
} 

int main() {
    // kadane normal daria o elemento 3
    // com delecao, apagamos o -2 e colapsamos {1} com {0, 3} -> soma 4
    vector<int> dados = {1, -2, 0, 3};

    cout << "soma maxima com ate 1 delecao: " << kadane_com_anistia(dados) << "\n";

    return 0;
}