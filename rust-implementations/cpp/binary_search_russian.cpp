// meta busca binaria
// binary lifting 
// busca binaria em bits

// **Sempre** avalia /theta{logN} casos, nao termina mais cedo
#include <iostream>
#include <vector>

int meta_binary_search(const std::vector<int>& dados, int alvo) {
    if (dados.empty()) return -1;
    int n = dados.size();
    int msb = 0;

    // calcula a maior potencia de 2 que seja <= n, o mesmo que *= 2
    while ((1 << msb) <= n) msb++;
    msb--;

    int pos_atual = -1;

    // constroi o indice testando bits do msb ao lsb, operacao do salto eh o mesmo que /= 2
    for (int salto = (1 << msb); salto > 0; salto >>= 1) {
        int prox_pos = pos_atual + salto;

        if (prox_pos < n && dados[prox_pos] <= alvo) pos_atual = prox_pos;
    }  
    return pos_atual;
}

int main() {
    std::vector<int>dados = {17, 23, 31, 49, 65, 77};
    int g = meta_binary_search(dados, 66);
    (g >= 0) ? std::cout << "Found: " << g << "\n" : std::cout << "Not found" << "\n";
    return 0;
}