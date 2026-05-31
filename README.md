# Algorithms & Data Structures Playbook 📚

Repositório unificado de estudos, implementações e resoluções de problemas envolvendo **Algoritmos e Estruturas de Dados**. Este repositório reúne projetos práticos, códigos de disciplinas da faculdade (UFABC) e implementações pessoais de algoritmos clássicos em diversas linguagens (C, C++, Rust e Python).

---

## 📁 Estrutura do Repositório

O repositório é organizado de forma modular para facilitar a navegação por área de estudo e técnica utilizada:

### 1. [Estruturas de Dados (AED 2)](./data-structures-aed2)
* **Linguagem:** C
* **Conteúdo:** Implementações clássicas de Estruturas de Dados da disciplina de Algoritmos e Estruturas de Dados II.
  * Tabelas Hash robustas com diferentes políticas de colisão (`HashList.c`, `HashVet.c`, `HashString.c`).
  * Projetos práticos e listas (`PA1/`, `PA2/`, `PA3/`, `PA4/`).

### 2. [Teoria dos Grafos & Matemática Discreta](./graph-theory)
* **Linguagem:** C e Python
* **Conteúdo:** Algoritmos clássicos para estudo de grafos e coloração de vértices.
  * Heurísticas de coloração: `WelshPowell.c`, `FirstFit.c`, `RecursiveLargestFirst.c`.
  * Ordenação de graus: `IncidenceDegreeOrdering.c`, `LargestDegreeOrdering.c`.
  * Geradores de grafos, clusterização e cálculos de métricas em grafos (`cluster.c`, `gerador.c`, `park.c`).

### 3. [Algoritmos Gulosos (Greedy)](./greedy-algorithms)
* **Linguagem:** C++
* **Conteúdo:** Soluções utilizando a estratégia Gulosa para otimização.
  * `katana.cpp`: Solução ótima para o clássico "Katana Thrower" (AtCoder ABC 085-D).
  * `ArithSeq.cpp`: Resolução envolvendo sequências aritméticas.

### 4. [Programação Dinâmica (DP)](./dynamic-programming)
* **Linguagem:** C++
* **Conteúdo:** Resolução de problemas otimizados através de subproblemas sobrepostos e memorização.
  * `LIS.cpp`: Algoritmo para encontrar a Subsequência Crescente Máxima (Longest Increasing Subsequence).

### 5. [Entendendo Algoritmos (Grokking Algorithms)](./grokking-algorithms)
* **Linguagem:** Python e C
* **Conteúdo:** Códigos de estudo baseados no livro *"Grokking Algorithms"* (Entendendo Algoritmos) de Aditya Bhargava.
  * Implementação de busca binária, ordenação por seleção, recursão, quicksort, grafos e algoritmos gulosos simples.

### 6. [Implementações em Rust](./rust-implementations)
* **Linguagem:** Rust e C++
* **Conteúdo:** Estudos práticos de algoritmos clássicos implementados na linguagem Rust (`rust/`) e comparações com C++ (`cpp/`), com foco em algoritmos de ordenação e estruturas eficientes.

---

## 🛠️ Como Executar os Códigos

### C / C++
A maioria das pastas contém um arquivo `Makefile`. Para compilar qualquer arquivo manualmente:
```bash
gcc -O3 nome_do_arquivo.c -o executavel
# ou para C++
g++ -O3 nome_do_arquivo.cpp -o executavel
```

### Python
Certifique-se de ter o Python 3 instalado e execute:
```bash
python3 nome_do_arquivo.py
```

### Rust
Navegue até a pasta correspondente e execute utilizando o `cargo`:
```bash
cargo run
```
