#include <iostream>
#include <vector>
using namespace std;

// dsu distancia relativa
struct DSU_Parity {
    vector<int> pai;
    vector<int> tamanho;
    vector<int> peso; // 0 = mesma paridade que o pai, 1 oposto

    DSU_Parity(int n) {
        pai.resize(n);
        tamanho.assign(n, 1);
        peso.assign(n, 0);
        for (int i = 0; i < n; i++) pai[i] = i;
    }

    // retorna um pair: {raiz, paridade_de_u_ate_raiz}
    pair<int, int> encontrar_raiz(int u) {
        if (pai[u] == u) return {u, 0};

        // chamada recursiva, resolve o pai primeiro
        pair<int, int> res_pai = encontrar_raiz(pai[u]);
        int raiz_suprema = res_pai.first;
        int paridade_pai_raiz = res_pai.second;

        // atualiza a paridade atual somando a distancia do pai ate a raiz
        peso[u] = (peso[u] + paridade_pai_raiz) % 2;
        pai[u] = raiz_suprema; // compressao de caminho

        return {pai[u], peso[u]};
    }
    
    // relacao: 0 se u e v sao amigos, 1 se inimigos
    // retorna false se a uniao contradiz uma relacao ja existente
    bool unir(int u, int v, int relacao) {
        pair<int, int> res_u = encontrar_raiz(u);
        pair<int, int> res_v = encontrar_raiz(v);

        int raiz_u = res_u.first;
        int raiz_v = res_v.first;
        int paridade_u = res_u.second;
        int paridade_v = res_v.second;

        if (raiz_u == raiz_v) {
            // se ja estao no mesmo componente, verificamos se a matematica bate
            // a diferenca relativa entre eles deve ser congruente à 'relacao'
            int relacao_existente = (paridade_u - paridade_v % 2 + 2) % 2;
            return relacao_existente == relacao;
        }

        // union by size (mantendo as arvores rasas)
        if (tamanho[raiz_u] < tamanho[raiz_v]) {
            swap(raiz_u, raiz_v);
            swap(paridade_u, paridade_v);
        }

        pai[raiz_v] = raiz_u;
        tamanho[raiz_u] += tamanho[raiz_v];

        // a equacao mestre de transicao:
        // queremos que (peso[v] + peso[raiz_v_velha_ate_nova_raiz]) % 2 == (peso[u] + relacao) % 2
        // logo, isolamos o peso que devemos atribuir à aresta entre as raizes:
        peso[raiz_v] = (paridade_u + relacao - paridade_v + 2) % 2;

        return true; 
    }
};

int main() {
    // fast i/o pra nao tomar time limit exceeded
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 5; // entidades de 0..4
    DSU_Parity dsu(n);

    // teste se 0 e 1 sao inimigos (relacao 1)
    dsu.unir(0, 1, 1);

    // teste se 1 e 2 inimigos
    dsu.unir(1, 2, 1);

    // checagem se o inimigo do meu inimigo eh meu amigo
    // ou seja, 0 e 2 devem ter relacao 0 (mesmo grupo/amigos)
    pair<int, int> inf_0 = dsu.encontrar_raiz(0);
    pair<int, int> inf_2 = dsu.encontrar_raiz(2);

    int relacao_inferida = (inf_0.second - inf_2.second % 2 + 2) % 2;

    cout << "relacao inferida entre 0 e 2: " << (relacao_inferida == 0 ? "amigos" : "inimigos") << "\n";

    // teste 3: tentar forcar que 0 e 2 sejam inimigos deve gerar uma contradicao
    bool sucesso = dsu.unir(0, 2, 1);
    cout << "foi possivel forcar 0 e 2 como inimigos? " << (sucesso ? "sim" : "nao (contradicao detectada)") << "\n";

    return 0;
}

