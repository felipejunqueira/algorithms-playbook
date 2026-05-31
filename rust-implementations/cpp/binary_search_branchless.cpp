#include <iostream>
#include <vector>
#include <optional>
#include <bit> // para std::bit_ceil

std::optional<int> branchless_binary_search(const std::vector<int>& arr, int target) {
    int n = arr.size();
    if (n == 0) return std::nullopt;

    int base = 0;

    // std::bit_ceil encontra a menor potencia de 2 maior ou igual a 'n'
    int step = std::bit_ceil(static_cast<unsigned int>(n)) / 2;

    while (step > 0) {
        int next_pos = base + step;
        base = (next_pos < n && arr[next_pos] <= target) ? next_pos : base;
        step /= 2;
    }

    if (base < n && arr[base] == target) return base;

    if (arr[0] == target) return 0;

    return std::nullopt;
}

int main() {
    std::vector<int> data = {3, 9, 10, 27, 38, 43, 82, 105, 200, 315};
    int target = 82;

    if (auto result = branchless_binary_search(data, target)) 
        std::cout << target << " encontrado no indice " << *result << "\n";
    else 
        std::cout << "nao encontrado\n";

    return 0;
}