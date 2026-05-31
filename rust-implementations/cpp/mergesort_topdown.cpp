#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, std::vector<int>& buffer, int left, int mid, int right) {
    for (int i = left; i <= right; i++) buffer[i] = arr[i];

    int i = left;
    int j = mid + 1;
    int k = left; // para a posicao final em 'arr'

    while (i <= mid && j <= right) {
        if (buffer[i] <= buffer[j]) { // '<=' garante a estabilidade
            arr[k++] = buffer[i];  
            i++;
        } 
        else {
            arr[k++] = buffer[j];
            j++;
        }
    }

    while (i <= mid) arr[k++] = buffer[i++];
}

void merge_sort_impl(std::vector<int>& arr, std::vector<int>& buffer, int left, int right) {
    if (left >= right) return;

    // Desse modo evita integer overflow
    int mid = left + (right - left) / 2;

    merge_sort_impl(arr, buffer, left, mid);
    merge_sort_impl(arr, buffer, mid + 1, right);
    merge(arr, buffer, left, mid, right);
}

void merge_sort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<int> buffer(arr.size()); // O(n) espaço

    merge_sort_impl(arr, buffer, 0, arr.size() -1);
}

int main() {
    std::vector<int> data = {38, 27, 43, 3, 9, 82, 10};

    merge_sort(data);

    for(int val : data) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}