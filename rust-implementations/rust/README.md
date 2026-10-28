# Sorting Algorithms using Rust 🦀

Coleção de algoritmos clássicos de ordenação implementados em Rust com foco em segurança de memória, traits genéricas (`PartialOrd`, `Copy`) e comparação com implementações tradicionais em C/C++.

---

## 📊 Tabela de Complexidade Assintótica

A tabela a seguir descreve a complexidade de tempo e espaço de cada algoritmo de ordenação contido neste módulo:

| Algoritmo | Melhor Caso (Tempo) | Caso Médio (Tempo) | Pior Caso (Tempo) | Espaço Auxiliar | Estável? | Arquivo Fonte |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Sim | [`bubble.rs`](./src/bin/bubble.rs) |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Sim | [`insertion.rs`](./src/bin/insertion.rs) |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Não | [`selection.rs`](./src/bin/selection.rs) |

> [!NOTE]
> - O **Bubble Sort** otimizado atinge $O(n)$ no melhor caso utilizando uma flag de interrupção antecipada quando nenhuma troca é detectada.
> - O **Selection Sort** em `selection.rs` demonstra a ordenação de `structs` customizadas (`Software`) utilizando derivação automática da trait `PartialOrd`.

---

## 🚀 Como Executar os Binários

Como este projeto utiliza a convenção de múltiplos binários na pasta `src/bin/`, utilize a flag `--bin` indicando o nome do executável:

```bash
# Executar Bubble Sort
cargo run --bin bubble

# Executar Insertion Sort
cargo run --bin insertion

# Executar Selection Sort
cargo run --bin selection

# Executar Hello World
cargo run --bin Hello
```
