// mergesort iterativo

#include <iostream>
#include <vector>
#include <algorithm> // para std::min

void merge(std::vector<int>& arr, std::vector<int>& buffer, int left, int mid, int right) {
    for (int i = left; i <= right; i++) buffer[i] = arr[i];

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (buffer[i] <= buffer[j]) arr[k++] = buffer[i++];
        else arr[k++] = buffer[j++];
    }

    while (i <= mid) arr[k++] = buffer[i++];
}

void bottom_up_merge_sort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    std::vector<int> buffer(n);

    for (int w = 1; w < n; w = 2 * w) {
        for (int i = 0; i < n; i += 2 * w) {
            int left = i;

            // o std::min garante que nao daremos segfault se o array 
            // nao for uma potencia de dois
            int mid = std::min(i + w - 1, n - 1);
            int right = std::min(i + 2 * w - 1, n - 1);

            if (mid < right) merge(arr, buffer, left, mid, right);
        }
    }
}

int main() {
    std::vector<int> data = {38, 27, 43, 68, 12, 10, 54};

    bottom_up_merge_sort(data);

    for (int val : data) std::cout << val << " ";

    std::cout << "\n";

    return 0;
}