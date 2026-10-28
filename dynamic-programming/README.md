# Programação Dinâmica (Dynamic Programming) 🧩

Resolução de problemas de otimização combinatória utilizando decomposição em subproblemas sobrepostos e memorização (tabulação ou memoization).

---

## 📊 Problemas e Algoritmos

| Arquivo | Problema | Complexidade de Tempo | Espaço Auxiliar | Resumo da Abordagem |
| :--- | :--- | :---: | :---: | :--- |
| [`LIS.cpp`](./LIS.cpp) | *Longest Increasing Subsequence* (Subsequência Crescente Máxima) | $O(n^2)$ | $O(n)$ | Programação dinâmica clássica com vetor `DP[i]` armazenando o comprimento da maior LIS que termina no índice `i` |

> [!TIP]
> O problema da LIS também admite uma formulação em $O(n \log n)$ combinando Programação Dinâmica com **Busca Binária** (`std::lower_bound`), substituindo o vetor de estados por um vetor de menores caudas viáveis.

---

## 🛠️ Como Compilar e Executar

```bash
g++ -std=c++20 -O3 -Wall -Wextra LIS.cpp -o lis
./lis
```
