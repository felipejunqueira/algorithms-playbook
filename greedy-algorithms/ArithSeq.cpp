#include <iostream>
using namespace std;
#define int long long

int seq(int a, int b, int c) {
    if (2 * b == c + a) return 0;
    int count = 0;
    if (2 * b > c + a) {
        count += 2 * b - (c + a);
    }
    else if (2 * b < c + a) {
        int dif = (c + a) - 2 * b; 
        count += dif / 2;          
        if (dif % 2 != 0) count += 2;
    }
    return count;
}

signed main() {
    int a, b, c; cin >> a >> b >> c;
    cout << seq(a, b, c) << endl;

    return 0;
}