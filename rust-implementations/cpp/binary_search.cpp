#include <iostream>
#include <vector>
#include <optional>

std::optional<int> binary_search(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;

        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    // se o loop terminar e left > right, provamos que o alvo nao existe
    return std::nullopt;
}

int main() {
    std::vector<int> data = {3, 9, 10, 27, 38, 43, 82};
    int target = 38;

    if (auto result = binary_search(data, target)) 
        std::cout << "Elemento " << target << " encontrado no indice: " << *result << "\n";
    else
        std::cout << "Elemento não está no conjunto.\n";

    return 0;
}