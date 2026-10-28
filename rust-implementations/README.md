# Implementações em Rust e C++ 🦀⚡

Estudo comparativo de estruturas de dados e algoritmos de alto desempenho implementados em **Rust** e **C++ moderno (C++20)**.

---

## 📁 Estrutura do Diretório

```
rust-implementations/
├── rust/                # Implementações em Rust usando Cargo (src/bin/)
│   ├── Cargo.toml
│   ├── README.md        # Documentação detalhada dos algoritmos Rust
│   └── src/bin/         # bubble.rs, insertion.rs, selection.rs, Hello.rs
└── cpp/                 # Biblioteca com 25+ algoritmos avançados em C++
```

---

## 📊 Catálogo de Algoritmos em C++ (`cpp/`)

### 1. Algoritmos de Ordenação e Inversões

| Arquivo | Algoritmo | Complexidade de Tempo | Espaço | Características |
| :--- | :--- | :---: | :---: | :--- |
| [`quicksort.cpp`](./cpp/quicksort.cpp) | Quicksort (Hoare) | $O(n \log n)$ | $O(\log n)$ | Particionamento clássico de Hoare |
| [`quicksort_estavel.cpp`](./cpp/quicksort_estavel.cpp) | Quicksort Estável | $O(n \log n)$ | $O(n)$ | Preserva estabilidade indexando pares `(valor, índice)` |
| [`quicksort_log_space.cpp`](./cpp/quicksort_log_space.cpp) | Quicksort Log Space | $O(n \log n)$ | $O(\log n)$ | Elimina recursão de cauda na partição maior contra stack overflow |
| [`mergesort_topdown.cpp`](./cpp/mergesort_topdown.cpp) | Merge Sort Top-Down | $O(n \log n)$ | $O(n)$ | Divisão recursiva estável |
| [`mergesort_bottomup.cpp`](./cpp/mergesort_bottomup.cpp) | Merge Sort Bottom-Up | $O(n \log n)$ | $O(n)$ | Versão iterativa livre de recursão |
| [`heapsort_min_heap.cpp`](./cpp/heapsort_min_heap.cpp) | Heap Sort (Min-Heap) | $O(n \log n)$ | $O(1)$ | Estrutura implícita em vetor com heapify |
| [`radix_sort.cpp`](./cpp/radix_sort.cpp) | Radix Sort (LSD) | $O(d \cdot (n + k))$ | $O(n + k)$ | Ordenação dígito a dígito estável |
| [`counting_sort_estavel.cpp`](./cpp/counting_sort_estavel.cpp) | Counting Sort Estável | $O(n + k)$ | $O(n + k)$ | Prefixo de contagens e varredura reversa estável |
| [`binary_insertion_sort.cpp`](./cpp/binary_insertion_sort.cpp) | Binary Insertion Sort | $O(n^2)$ | $O(1)$ | Posição via `std::upper_bound` em $O(\log i)$ comparações |
| [`insertion_sort.cpp`](./cpp/insertion_sort.cpp) | Insertion Sort Clássico | $O(n^2)$ | $O(1)$ | Ótimo para vetores quase ordenados |
| [`selection_sort.cpp`](./cpp/selection_sort.cpp) | Selection Sort Clássico | $O(n^2)$ | $O(1)$ | Número mínimo de trocas ($O(n)$) |
| [`L2_count_inversions.cpp`](./cpp/L2_count_inversions.cpp) | Contagem de Inversões | $O(n \log n)$ | $O(n)$ | Contagem de pares invertidos durante o Merge Sort |

### 2. Busca e Álgebra de Bits

| Arquivo | Algoritmo | Complexidade de Tempo | Espaço | Características |
| :--- | :--- | :---: | :---: | :--- |
| [`binary_search.cpp`](./cpp/binary_search.cpp) | Busca Binária | $O(\log n)$ | $O(1)$ | Retorno seguro com `std::optional<int>` |
| [`binary_search_branchless.cpp`](./cpp/binary_search_branchless.cpp) | Busca Binária Branchless | $O(\log n)$ | $O(1)$ | Sem desvios condicionais imprevisíveis |
| [`binary_search_russian.cpp`](./cpp/binary_search_russian.cpp) | Meta Busca Binária | $O(\log n)$ | $O(1)$ | Salto por bits potências de 2 decrescentes |

### 3. Estruturas em Grafos e Árvores

| Arquivo | Algoritmo | Complexidade de Tempo | Espaço | Características |
| :--- | :--- | :---: | :---: | :--- |
| [`DSU.cpp`](./cpp/DSU.cpp) | Disjoint Set Union | $O(\alpha(n))$ | $O(n)$ | Compressão de caminhos e união por rank |
| [`DSU_parity.cpp`](./cpp/DSU_parity.cpp) | DSU com Paridade | $O(\alpha(n))$ | $O(n)$ | Relação amizade/inimizade com verificação de consistência |
| [`binary_lifting_LCA.cpp`](./cpp/binary_lifting_LCA.cpp) | Binary Lifting & LCA | $O(n \log n)$ / $O(\log n)$ | $O(n \log n)$ | Menor Ancestral Comum e consulta de gargalo minimax |
| [`kruskal.cpp`](./cpp/kruskal.cpp) | Kruskal MST | $O(E \log E)$ | $O(V + E)$ | Árvore geradora mínima usando DSU |
| [`kruskal_minimax.cpp`](./cpp/kruskal_minimax.cpp) | Kruskal Minimax | $O(E \log E)$ | $O(V + E)$ | Minimização da maior aresta em caminho |

### 4. Vetores, Subarrays e Prefixos

| Arquivo | Algoritmo | Complexidade de Tempo | Espaço | Características |
| :--- | :--- | :---: | :---: | :--- |
| [`kadane.cpp`](./cpp/kadane.cpp) | Algoritmo de Kadane | $O(n)$ | $O(1)$ | Subarray de soma contígua máxima |
| [`kadane_bidirecional.cpp`](./cpp/kadane_bidirecional.cpp) | Kadane com 1 Deleção | $O(n)$ | $O(n)$ | Subarray de soma máxima permitindo remover 1 elemento |
| [`prefix_sum.cpp`](./cpp/prefix_sum.cpp) | Prefix Sum + Hash Map | $O(n)$ | $O(n)$ | Contagem de subarrays com soma exata $S$ |
| [`L2_find_idx.cpp`](./cpp/L2_find_idx.cpp) | Two Sum / Busca de Pares | $O(n)$ | $O(n)$ | Busca de índices complementares |

---

## 🛠️ Como Executar

Consulte o [`README.md`](./rust/README.md) da pasta `rust/` para execução com Cargo, ou compile os códigos C++ via:

```bash
g++ -std=c++20 -O3 -Wall -Wextra cpp/quicksort.cpp -o quicksort
./quicksort
```
