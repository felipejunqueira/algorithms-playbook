#include <iostream>
#include <numeric>
#include <vector>
#include <utility>

class DSU {
    private:
        std::vector<int> pai;
        std::vector<int> tamanho;
    
    public:
        // Construtor
        explicit DSU(int n) : pai(n), tamanho(n, 1) {
            // Preenche o array pai de 0 ate n-1
            // cada no eh seu proprio lider em t=0
            std::iota(pai.begin(), pai.end(), 0);
        }

        // retorna a raiz da componente que contem 'u', aplicando path compression
        int encontrar_raiz(int u) {
            // condicao de parada: a raiz aponta p si mesma
            if (pai[u] == u) return u;
            // em vez de retornar, religamos o ponteiro na raiz suprema
            // retorno rapido da stack
            return pai[u] = encontrar_raiz(pai[u]);  
        }

        bool unir(int u, int v) {
            int raiz_u = encontrar_raiz(u);
            int raiz_v = encontrar_raiz(v);
            // detectar ciclos
            if (raiz_u == raiz_v) return false;
            // union by size, garantir que raiz_u sera a arvore maior ou igual
            if (tamanho[raiz_u] < tamanho[raiz_v]) std::swap(raiz_u, raiz_v);
            // anexa a menor arvore sob a raiz da maior
            pai[raiz_v] = raiz_u;
            tamanho[raiz_u] += tamanho[raiz_v];
            return true;
        }

        int tamanho_do_conjunto(int u) { return tamanho[encontrar_raiz(u)]; }

        bool conectados(int u, int v) { return encontrar_raiz(u) == encontrar_raiz(v); }
};

int main() {
    DSU dsu(7); // elemetos 0..6

    dsu.unir(0, 1);
    dsu.unir(1, 2);
    dsu.unir(3, 4);

    std::cout << "0 e 2 conectados? "
              << (dsu.conectados(0, 2) ? "sim" : "nao") << '\n';

    std::cout << "0 e 4 conectados? "
              << (dsu.conectados(0, 4) ? "sim" : "nao") << '\n';

    std::cout << "Tamanho do conjunto de 1: "
              << dsu.tamanho_do_conjunto(1) << '\n';

    std::cout << "Tamanho do conjunto de 3: "
              << dsu.tamanho_do_conjunto(3) << '\n';

    dsu.unir(2, 4);

    std::cout << "Depois de unir 2 e 4, 0 e 4 conectados? "
              << (dsu.conectados(0, 4) ? "sim" : "nao") << '\n';

    std::cout << "Tamanho do conjunto de 0: "
              << dsu.tamanho_do_conjunto(0) << '\n';

    return 0;
}