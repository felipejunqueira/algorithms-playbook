#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// representacao da aresta para a lista de adjacencia
struct ArestaArvore {
    int destino;
    int peso;
};

// o motor de roteamento (LCA com binary lifting)
struct BinaryLiftingLCA {
    int n, LOG;
    vector<vector<ArestaArvore>> adj; // um array de ponteiros para arrays dispersos
    vector<int> profundidade;
    vector<vector<int>> ancestral;
    vector<vector<int>> max_aresta;

    BinaryLiftingLCA(int vertices) : n(vertices) {
        // K = floor(log2(N)) + 1
        LOG = log2(n) + 1;
        adj.resize(n);
        profundidade.resize(n, 0);

        // inicializa com sentineas (-1 pra ancestral, 0 pra peso)
        ancestral.assign(n, vector<int>(LOG, -1));
        max_aresta.assign(n, vector<int>(LOG, 0));
    }

    void adicionar_aresta(int u, int v, int peso) {
        adj[u].push_back({v, peso});
        adj[v].push_back({u, peso});
    }

    // 1. travessia base (preenchimento do nivel j=0)
    void dfs(int u, int pai_imediato, int peso_pai, int prof) {
        profundidade[u] = prof;
        ancestral[u][0] = pai_imediato;
        max_aresta[u][0] = peso_pai;

        for (const auto& vizinho : adj[u]) {
            if (vizinho.destino != pai_imediato) {
                dfs(vizinho.destino, u, vizinho.peso, prof + 1);
            }
        }
    }
    
    // 2. construcao da DP
    void construir_dp(int raiz = 0) {
        dfs(raiz, -1, 0, 0);

        // precisamos que TODO o nivel j-1 esteja calculado antes de calcular o nivel j
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                int avo = ancestral[i][j-1];
                if (avo != -1) {
                    ancestral[i][j] = ancestral[avo][j-1];
                    max_aresta[i][j] = max(max_aresta[i][j-1], max_aresta[avo][j-1]);
                }
            }
        }
    }

    // consulta em O(log V)
    int consultar_gargalo_minimax(int u, int v) {
        int gargalo = 0;
         
        // 'u' sempre deve ser o nó mais profundo
        if (profundidade[u] < profundidade[v]) swap(u, v);

        // A: igualar as profundidades
        for (int j = LOG - 1; j >= 0; --j) {
            if (profundidade[u] - (1 << j) >= profundidade[v]) {
                gargalo = max(gargalo, max_aresta[u][j]);
                u = ancestral[u][j];
            }
        }

        // se 'v' era o ancestral direto de 'u', terminamos
        if (u == v) return gargalo;

        // B: subir ambos simutaneamente ate pouco antes do LCA
        for (int j = LOG - 1; j >= 0; --j) {
            // se os ancestrais sao diferentes, nao chegamos no LCA
            // o salto eh seguro e nao causa overshoot
            if (ancestral[u][j] != ancestral[v][j]) {
                gargalo = max({gargalo, max_aresta[u][j], max_aresta[v][j]});
                u = ancestral[u][j];
                v = ancestral[v][j];
            }
        }
         
        // C: o ultimo degrau
        // u e v estao exatamente 1 nivel abaixo do LCA. O LCA eh ancestral[u][0]
        gargalo = max({gargalo, max_aresta[u][0], max_aresta[v][0]});

        return gargalo;
    }
};

int main() {
    int n = 5;
    BinaryLiftingLCA arvore(n);

    // conectando as arestas que assumimos ja pertencerem à MST
    arvore.adicionar_aresta(0, 1, 10);
    arvore.adicionar_aresta(1, 2, 5);
    arvore.adicionar_aresta(1, 3, 12);
    arvore.adicionar_aresta(0, 4, 30);

    // pre-processamento O(V log V)
    arvore.construir_dp(0);

    // consulta O(log V) do gargalo entre 2 e 3
    // caminho visual: 2 -> 1 -> 3. Arestas: 5 e 12. Gargalo: 12
    cout << "Gargalo Minimax entre 2 e 3: " << arvore.consultar_gargalo_minimax(2, 3) << "\n";
    return 0;
}

