// Recebe um vetor de inteiros A[1..n] e um inteiro x, e em tempo justo nlogn, determina
// se existem indices 1 <= i < j <= n tais que A[i] + A[j] = x

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possui_dois_soma(vector<int> A, int x) {
    int n = A.size();
    if (n < 2) return false;

    // poderia ser o mergesort aqui
    // em C++, std::sort usa IntroSort, com pior caso theta(nlogn)
    std::sort(A.begin(), A.end());

    int L = 0;
    int R = n - 1;

    // roda no maximo n-1 vezes
    while (L < R) {
        long long soma_atual = (long long)A[L] + A[R]; // prevenir overflow
        if (soma_atual == x) return true;
        else if (soma_atual < x) L++;
        else R--;
    }
    return false;
}

int main() {
    vector<int> A = {8, 2, 5, 3, 9, 1, 6};
    int x = 500000;

    bool encontrou = possui_dois_soma(A, x);

    cout << (encontrou ? "existe o par" : "nao existe o par") << "\n";

    return 0;
}