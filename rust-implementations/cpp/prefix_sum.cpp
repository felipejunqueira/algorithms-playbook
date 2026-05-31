#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int contar_subarrays_soma_exata(const vector<int>& dados, long long alvo_S) {
    // tabela hash mapeia {soma de prefixo -> frequencia que apareceu}
    unordered_map<long long, int> historico_prefixos;

    // base case, se sub array valido comecar no 0, a formula resultara em 0
    // por isso hash soma zero antes mesmo de comecar
    historico_prefixos[0] = 1;

    long long soma_acumulada_atual = 0;
    int total_subarrays_encontrados = 0;

    for (int j = 0; j < dados.size(); ++j) {
        // atualiza o hodometro
        soma_acumulada_atual += dados[j];

        long long passado_procurado = soma_acumulada_atual - alvo_S;
    
        if (historico_prefixos.count(passado_procurado)) {
            // se existirem 3 momentos no passado com essa soma, temos 3 novos sub-arrays validos terminnado em 'j'
            total_subarrays_encontrados += historico_prefixos[passado_procurado];
        }

        historico_prefixos[soma_acumulada_atual]++;
    }
    return total_subarrays_encontrados;
}

int main() {
    // quero sub-arrays que somem exatamente S = 7
    // esperado: [3, 4], [7], [7, 2, -3, 1] [1, 4, 2] -> total = 4
    vector<int> stream_de_dados = {3, 4, 7, 2, -3, 1, 4, 2};
    long long S = 7;

    int resultado = contar_subarrays_soma_exata(stream_de_dados, S);

    cout << "Total de sub-arrays com soma exata " << S << ": " << resultado << "\n";

    return 0;
}