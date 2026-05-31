#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int> A, int n) {
    if (n == 0) return 0;
    vector<int> DP(n, 0); 
    DP[0] = 1;
    for (int i = 1; i < n; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && DP[j] + 1 > DP[i])
                DP[i] = DP[j] + 1;
        }
    }
    return *max_element(DP.begin(), DP.end());
}

int main() {
    int n; cin >> n;
    if (n == 0) return 0;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) 
        cin >> A[i];
    cout << LIS(A, n) << endl;

    return 0;
}