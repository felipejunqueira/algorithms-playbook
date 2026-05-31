#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // historico de variacoes: a resposta esperada eh o sub array [4, -1, 2, 1] com soma 6
    vector<int> dados = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = dados.size();

    // inicializacao: a menor representacao possivel do tipo no hardware
    // iniciar com 0 eh um erro letal se o array contiver apenas numeros negativos
    long long soma_maxima_global = numeric_limits<long long>::min();
    long long soma_atual_janela = 0;

    int inicio_global = 0, fim_global = 0;
    int inicio_temporario = 0;

    for (int i = 0; i < n; ++i) {
        soma_atual_janela += dados[i];

        // atualizacao do max global e travamento dos indices
        if (soma_atual_janela > soma_maxima_global) {
            soma_maxima_global = soma_atual_janela;
            inicio_global = inicio_temporario;
            fim_global = i;
        }

        // invariante de kadane: se a janela atual ficou negativa, ela eh peso morto
        // cortamos a janela e preparamos o proximo elemento como o novo inicio potencial
        if (soma_atual_janela < 0) {
            soma_atual_janela = 0;
            inicio_temporario = i + 1;
        }
    }

    cout << "Soma Maxima Encontrada: " << soma_maxima_global << "\n";
    cout << "Intervalo Otimo: Indice [" << inicio_global << "] ate [" << fim_global << "]\n";
    cout << "Sub-array: { ";
    for (int i = inicio_global; i <= fim_global; ++i) {
        cout << dados[i] << (i == fim_global ? " " : ", ");
    }
    cout << "}\n";

    return 0;
}