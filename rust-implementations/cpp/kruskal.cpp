#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DSU canonica (achatada)
struct DSU {
    vector<int> pai, tamanho;
    DSU(int n) {
        pai.resize(n); tamanho.assign(n, 1);
        for (int i = 0; i < n; i++) pai[i] = i;
    }
    int encontrar_raiz(int u) {
        if (pai[u] == u) return u;
        return pai[u] = encontrar_raiz(pai[u]);
    }
    bool unir(int u, int v) {
        int r_u = encontrar_raiz(u), r_v = encontrar_raiz(v);
        if (r_u == r_v) return false;
        if (tamanho[r_u] < tamanho[r_v]) swap(r_u, r_v);
        pai[r_v] =  r_u;
        tamanho[r_u] += tamanho[r_v];
        return true;
    }
};

// estrutura da aresta isolada para otimizacao de cache
struct Aresta {
    int u, v;
    long long peso;
    // Operador de comparacao para o std::sort (ganancia)
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_vertices = 4; // vertices 0..3
    vector<Aresta> arestas = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    // o gargalo: ordenacao das arestas
    sort(arestas.begin(), arestas.end());

    DSU dsu(num_vertices);
    long long custo_total_mst = 0;
    int arestas_na_mst = 0;

    // ganancia aliada a DSU
    for (const auto& aresta : arestas) {
        // se a uniao for bem sucedida, nao ha ciclos
        if (dsu.unir(aresta.u, aresta.v)) {
            custo_total_mst += aresta.peso;
            arestas_na_mst++;
            cout << "Aresta adicionada: (" << aresta.u << ", " << aresta.v << ") | peso: " << aresta.peso << "\n";

            //otimizacao de parada precoce: uma arvore de V vertices tem exatamente V-1 arestas
            if (arestas_na_mst == num_vertices - 1) break;
        }
    }

    if (arestas_na_mst != num_vertices - 1) 
        cout << "grafo desconectado. impossivel formar mst abrangente\n";
    else   
        cout << "custo total da mst: " << custo_total_mst << "\n";
    
    return 0;
}