#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// o motor do heap: sift-down (afundar)
// restaura a propriedade do max-heap para a sub-arvore enraizada em indice_raiz
// assume que as sub-arvores esq e dir ja sao max-heaps validos
void max_heapify(vector<int>& A, int tamanho_heap, int indice_raiz) {
    int maior_absoluto = indice_raiz;
    int filho_esq = 2 * indice_raiz + 1;
    int filho_dir = 2 * indice_raiz + 2;

    if (filho_esq < tamanho_heap && A[filho_esq] > A[maior_absoluto])
        maior_absoluto = filho_esq;
    else if (filho_dir < tamanho_heap && A[filho_dir] > maior_absoluto)
        maior_absoluto = filho_dir;

    //se a raiz violou a propriedade do heap (alguem embaixo eh menor)
    else if (maior_absoluto != indice_raiz) {
        std::swap(A[indice_raiz], A[maior_absoluto]);
        // a mutacao afeta a estrutura abaixo. a recursao persegue o elemento 
        // que acabou de ser rebaixado para garantir que ele afunde ate o fundo correto
        max_heapify(A, tamanho_heap, maior_absoluto);
    }
}

void heapsort(vector<int>& A) {
    int n = A.size();

    // construcao do universo (build-max-heap) em Theta(N)
    // os nos folhas (indices de n/2 ate n-1) ja sao heaps triviais de tamanho 1
    // comecamos do ultimo no pai e subimos ate a raiz absoluta (0)
    for (int i = n / 2 - 1; i >= 0; i--) max_heapify(A, n, i);

    // extracao destrutiva em Theta(nlogn)
    for (int i = n - 1; i > 0; i--) {
        // a raiz A[0] eh garantidamente o maior elemento restante
        // movemos ele para o final do array (sua posicao final e ordenada)
        std::swap(A[0], A[i]);

        // o tamanho do "reino do heap" encolhe em 1. o elemento ordenado no fim esta isolado
        // o elem que colocamos na raiz(que veio do fim) destroi a propriedade do heap
        // invocamos max_heapify na raiz para afundá-lo e coroar o proximo maior elem
        max_heapify(A, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> A = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    
    cout << "Array Caotico Original: ";
    for (int x : A) cout << x << " "; cout << "\n";

    heapsort(A);

    cout << "Array Ordenado (HeapSort): ";
    for (int x : A) cout << x << " "; cout << "\n";

    return 0;
}