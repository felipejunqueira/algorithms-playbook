#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int u, v, peso;
    bool operator<(const Aresta& outra) const {return peso < outra.peso; }
};

struct DSU {
    vector<int> pai;
    DSU(int n) {
        pai.resize(n);
        for (int i = 0; i < n; i++) pai[i] = i;
    }
    int find(int i) {
        if (pai[i] == i) return i;
        return pai[i] = find(pai[i]);
    }
    void unir(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) pai[root_i] = root_j;
    }
};

// problema: qual o menor gargalo maximo entre origem e destino?
int resolver_minimax(int n, vector<Aresta>& arestas, int origem, int destino) {
    // ordenacao (kruskal) -  queremos as mais leves primeiro
    sort(arestas.begin(), arestas.end());

    DSU dsu(n);

    for (const auto& e : arestas) {
        dsu.unir(e.u, e.v);

        // no momento que se conectao, a aresta atual eh o gargalo otimo
        if (dsu.find(origem) == dsu.find(destino)) return e.peso;
    }
    return -1; // desconectados
}

int main() {
    int n = 5;
    vector<Aresta> arestas = {
        {0, 1, 10}, {1, 2, 5}, {2, 3, 20}, {3, 4, 15}, {0, 4, 30}, {1, 3, 12}
    };

    int gargalo = resolver_minimax(n, arestas, 0, 3);
    cout << "gargalo minimo entre 0 e 3 eh: " << gargalo << endl;
    // o caminho 0-1-3 tem arestas {10, 12}. o gargalo eh 12
    // qualquer outro caminho (0-1-2-3) teria a aresta 20

    return 0;  
}