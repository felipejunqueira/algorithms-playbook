// Detectar o numero de inversoes de qualquer permutacao de n elementos em tempo
// justo nlogn

#include <iostream>
#include <vector>

using namespace std;

// funcao merge transmutada para contar e aniquilar inversoes
long long merge_e_conta(vector<int>& A, vector<int>& aux, int L, int mid, int R) {
    int i = L, j = mid + 1, k = L;
    long long contagem_inversoes = 0;

    // fase de intercalacao
    while (i <= mid && j <= R) {
        if (A[i] <= A[j]) aux[k++] = A[i++];
        else {
            // inversao cruzada. contagem_inversoes eh o numero de 
            // elementos nao processados na metade esquerda
            aux[k++] = A[j++];
            contagem_inversoes += (mid - i + 1);
        }
    }

    while (i <= mid) aux[k++] = A[i++];
    while (j <= R) aux[k++] = A[j++];
    for (i = L; i <= R; i++) A[i] = aux[i];

    return contagem_inversoes;
}

// a divisao e conquista recursiva
long long merge_sort_contador(vector<int>& A, vector<int>& aux, int L, int R) {
    long long inversoes = 0;
    if (L < R) {
        int mid = L + (R - L) / 2;

        // inversoes internas à esquerda
        inversoes += merge_sort_contador(A, aux, L, mid);
        
        // inversoes internas à direita
        inversoes += merge_sort_contador(A, aux, mid + 1, R);
        
        // inversoes cruzadas
        inversoes += merge_e_conta(A, aux, L, mid, R);
    }
    
    return inversoes;
}

long long contar_inversoes(vector<int>& A) {
    vector<int> aux(A.size());
    return merge_sort_contador(A, aux, 0, A.size() - 1);
}

int main() {
    vector<int> A = {2, 4, 1, 3, 5};

    cout << "Array Original: ";
    for (int x : A) cout << x << " ";
    cout << "\n";

    long long total = contar_inversoes(A);

    cout << "Numero de Inversoes da Permutacao: " << total << "\n";

    return 0;
}