# Algorithms & Data Structures Playbook 📚

Repositório unificado de estudos, implementações e resoluções de problemas envolvendo **Algoritmos e Estruturas de Dados**. Este repositório reúne projetos práticos, códigos de disciplinas da faculdade (UFABC) e implementações pessoais de algoritmos clássicos em diversas linguagens (**C**, **C++**, **Rust** e **Python**).

---

## 🧭 Visão Geral dos Módulos

| # | Módulo | Diretório | Linguagens | Principais Algoritmos / Estruturas |
| :-: | :--- | :--- | :-: | :--- |
| 1 | **Estruturas de Dados (AED 2)** | [`data-structures-aed2/`](./data-structures-aed2) | C | Tabelas Hash (Encadeamento e Endereçamento Aberto), Árvores AVL/B, Listas |
| 2 | **Teoria dos Grafos & Discreta** | [`graph-theory/`](./graph-theory) | C, Python | Coloração de Vértices (DSatur, Welsh-Powell, RLF, First-Fit), 1-WL Isomorfismo |
| 3 | **Algoritmos Gulosos (Greedy)** | [`greedy-algorithms/`](./greedy-algorithms) | C++ | Resolução ótima de problemas de maratona (Katana Thrower, Sequências Aritméticas) |
| 4 | **Programação Dinâmica (DP)** | [`dynamic-programming/`](./dynamic-programming) | C++ | LIS (Longest Increasing Subsequence), Subproblemas sobrepostos e memorização |
| 5 | **Entendendo Algoritmos** | [`grokking-algorithms/`](./grokking-algorithms) | Python, C, Java | Busca Binária, Quicksort, BFS, Grafos, Guloso (Set Cover), Dicionários |
| 6 | **Implementações em Rust e C++** | [`rust-implementations/`](./rust-implementations) | Rust, C++ | Ordenação em Rust (`Cargo`), 25+ algoritmos avançados em C++ (LCA, DSU, Kruskal) |

---

## 📊 Tabela de Complexidade Assintótica dos Algoritmos

Abaixo está o quadro de referência com as complexidades de tempo e espaço dos principais algoritmos catalogados no repositório:

### Algoritmos de Ordenação

| Algoritmo | Melhor Caso | Caso Médio | Pior Caso | Espaço Auxiliar | Estável? | Módulos |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Quicksort (Hoare)** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | Não | `rust-implementations/cpp/`, `grokking-algorithms/` |
| **Quicksort Estável** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(n)$ | Sim | `rust-implementations/cpp/` |
| **Quicksort Log Space** | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ | Não | `rust-implementations/cpp/` |
| **Merge Sort (Top-down / Bottom-up)** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Sim | `rust-implementations/cpp/` |
| **Heap Sort (Min Heap)** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(1)$ | Não | `rust-implementations/cpp/` |
| **Counting Sort Estável** | $O(n + k)$ | $O(n + k)$ | $O(n + k)$ | $O(n + k)$ | Sim | `rust-implementations/cpp/` |
| **Radix Sort (LSD)** | $O(d \cdot (n + k))$ | $O(d \cdot (n + k))$ | $O(d \cdot (n + k))$ | $O(n + k)$ | Sim | `rust-implementations/cpp/` |
| **Binary Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Sim | `rust-implementations/cpp/` |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Sim | `rust-implementations/rust/`, `cpp/` |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Não | `rust-implementations/rust/`, `cpp/` |
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Sim | `rust-implementations/rust/` |

### Busca, Grafos e Estruturas Avançadas

| Algoritmo / Estrutura | Operação / Consulta | Complexidade de Tempo | Espaço Auxiliar | Observação |
| :--- | :--- | :---: | :---: | :--- |
| **Binary Search (Clássico)** | Busca em vetor ordenado | $O(\log n)$ | $O(1)$ | Posição ou ausência (`std::optional`) |
| **Binary Search (Branchless)** | Busca sem branches | $O(\log n)$ | $O(1)$ | Amigável a preditores de salto de CPU |
| **Meta Binary Search (Bits)** | Salto por potências de 2 | $O(\log n)$ | $O(1)$ | Avalia exatamente $\lfloor \log_2 n \rfloor$ passos |
| **DSU (Disjoint Set Union)** | `find` / `union` | $O(\alpha(n))$ | $O(n)$ | Quase linear via compressão de caminho e rank |
| **DSU com Paridade** | Relação de amizade/inimizade | $O(\alpha(n))$ | $O(n)$ | Detecção de contradições em bipartição |
| **Binary Lifting LCA** | Menor Ancestral Comum | $O(n \log n)$ prep / $O(\log n)$ query | $O(n \log n)$ | Suporta consulta minimax de aresta máxima |
| **Kruskal (com DSU)** | Árvore Geradora Mínima (MST) | $O(E \log E)$ | $O(V + E)$ | Encontra árvore geradora ou floresta mínima |
| **Kadane (Soma Máxima)** | Subarray de soma contígua máxima | $O(n)$ | $O(1)$ | Retorna soma e índices $[i, j]$ ótimos |
| **Prefix Sum com Hash Map** | Contagem de subarrays com soma $S$ | $O(n)$ | $O(n)$ | Consulta em tempo médio constante $O(1)$ |
| **Inversion Counting** | Contagem de inversões | $O(n \log n)$ | $O(n)$ | Implementado sobre divisão e conquista (Merge) |
| **Longest Increasing Subsequence** | LIS (Programação Dinâmica) | $O(n^2)$ | $O(n)$ | Versão clássica com vetor `DP` de memorização |

---

## 📁 Estrutura Detalhada do Repositório

### 1. [Estruturas de Dados (AED 2)](./data-structures-aed2)
* **Linguagem:** C
* **Conteúdo:** Implementações clássicas de Estruturas de Dados da disciplina de Algoritmos e Estruturas de Dados II da UFABC.
  * Tabelas Hash robustas com diferentes políticas de colisão (`HashList.c`, `HashVet.c`, `HashString.c`, `HashStruct.c`, `HashQ1.c`).
  * Projetos práticos e listas de exercícios (`PA1/`, `PA2/`, `PA3/`, `PA4/`).

### 2. [Teoria dos Grafos & Matemática Discreta](./graph-theory)
* **Linguagem:** C e Python
* **Conteúdo:** Algoritmos clássicos para estudo de grafos, métricas e coloração de vértices.
  * Heurísticas de coloração: `WelshPowell.c` / `.py`, `FirstFit.c` / `.py`, `RecursiveLargestFirst.c`, `DegreeofSaturation.c` (DSatur).
  * Ordenação de graus: `IncidenceDegreeOrdering.c`, `LargestDegreeOrdering.c` / `.py`.
  * Isomorfismo e refinamento: `colorRefinament.c` / `ColorRefinement.py` (1-WL).
  * Geradores de grafos, clusterização e cálculos de métricas (`cluster.c`, `gerador.c`, `park.c`).

### 3. [Algoritmos Gulosos (Greedy)](./greedy-algorithms)
* **Linguagem:** C++
* **Conteúdo:** Soluções utilizando a estratégia Gulosa para otimização.
  * `katana.cpp`: Solução ótima para o clássico "Katana Thrower" (AtCoder ABC 085-D).
  * `ArithSeq.cpp`: Resolução envolvendo sequências aritméticas mínimas.

### 4. [Programação Dinâmica (DP)](./dynamic-programming)
* **Linguagem:** C++
* **Conteúdo:** Resolução de problemas otimizados através de subproblemas sobrepostos e memorização.
  * `LIS.cpp`: Algoritmo para encontrar a Subsequência Crescente Máxima (Longest Increasing Subsequence).

### 5. [Entendendo Algoritmos (Grokking Algorithms)](./grokking-algorithms)
* **Linguagem:** Python, C e Java
* **Conteúdo:** Códigos de estudo práticos baseados no livro *"Grokking Algorithms"* de Aditya Bhargava.
  * Implementação de busca binária, ordenação por seleção, recursão, quicksort, busca em largura (BFS), tabelas hash e algoritmos gulosos de aproximação (cobertura de conjuntos).

### 6. [Implementações em Rust & C++](./rust-implementations)
* **Linguagem:** Rust e C++
* **Conteúdo:**
  * [`rust/`](./rust-implementations/rust): Algoritmos de ordenação (`bubble`, `insertion`, `selection`) organizados como crate Cargo com múltiplos binários.
  * [`cpp/`](./rust-implementations/cpp): Biblioteca extensa de mais de 25 algoritmos em C++ moderno (C++20) com implementações otimizadas de ordenação, estruturas de dados de união e busca, árvores e grafos.

---

## 🛠️ Como Executar os Códigos

### C / C++
Para compilar qualquer arquivo manualmente com otimização máxima (`-O3`):
```bash
# Compilar código em C
gcc -O3 -Wall -Wextra caminho/para/arquivo.c -o executavel

# Compilar código em C++ (recomenda-se C++20 para os arquivos em rust-implementations/cpp)
g++ -std=c++20 -O3 -Wall -Wextra caminho/para/arquivo.cpp -o executavel

# Executar
./executavel
```

> [!NOTE]
> A pasta `grokking-algorithms/` inclui um `Makefile` com atalhos de execução:
> ```bash
> cd grokking-algorithms
> make c   # Compila e roda o binário C
> make p   # Executa o script Python cobra.py
> ```

### Python
Certifique-se de ter o Python 3.8+ instalado e execute:
```bash
python3 nome_do_arquivo.py
```

### Rust
Navegue até a pasta `rust-implementations/rust/` e execute especificando o binário desejado através da flag `--bin`:
```bash
cd rust-implementations/rust

# Executar Bubble Sort
cargo run --bin bubble

# Executar Insertion Sort
cargo run --bin insertion

# Executar Selection Sort
cargo run --bin selection

# Executar Hello World
cargo run --bin Hello
```

