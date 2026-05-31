#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

typedef struct {
    int wield;
    int thr;
} sword;

int monster(vector<sword> &vec, int N, int H) {
    int max_wield = 0;
    for (int i = 0; i < N; i++) {
        max_wield = max(max_wield, vec[i].wield);
    }
    vector<int> useful_throws;
    for (int i = 0; i < N; i++) {
        if (vec[i].thr > max_wield) {
            useful_throws.push_back(vec[i].thr);
        }
    }

    sort(useful_throws.rbegin(), useful_throws.rend());

    int attacks = 0;

    for (int damage : useful_throws) {
        H -= damage;
        attacks++;
        if (H <= 0) return attacks;
    }

    if (H > 0) {
        int swings = (H + max_wield - 1) / max_wield;
        attacks += swings; 
    }
    return attacks;

}

signed main() {
    int N, H; cin >> N >> H;
    vector<sword> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].wield >> vec[i].thr;
    }

    cout << monster(vec, N, H) << endl;

    return 0;
}