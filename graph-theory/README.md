# Teoria dos Grafos & Matemática Discreta 🕸️

Implementações em **C** e **Python** de algoritmos clássicos para estudo de grafos, heurísticas de coloração de vértices e testes de isomorfismo em instâncias padrão de grafos (DIMACS).

---

## 📊 Algoritmos e Heurísticas de Coloração

| Algoritmo | Implementações | Estratégia / Complexidade | Descrição |
| :--- | :--- | :--- | :--- |
| **DSatur (Degree of Saturation)** | [`DegreeofSaturation.c`](./DegreeofSaturation.c) | Heurística $O(V^2)$ ou $O(V \log V + E)$ | Colore primeiro o vértice com maior grau de saturação (cores vizinhas distintas) |
| **RLF (Recursive Largest First)** | [`RecursiveLargestFirst.c`](./RecursiveLargestFirst.c) | Heurística $O(V^3)$ | Constrói conjuntos independentes maximais de vértices para cada cor |
| **Welsh-Powell** | [`WelshPowell.c`](./WelshPowell.c), [`WelshPowell.py`](./WelshPowell.py) | Ordenação prévia $O(V \log V + E)$ | Ordena vértices por grau decrescente antes de aplicar a coloração gulosa |
| **First-Fit** | [`FirstFit.c`](./FirstFit.c), [`FirstFit.py`](./FirstFit.py) | Guloso puro $O(V + E)$ | Atribui a menor cor viável na ordem natural dos vértices |
| **LDO (Largest Degree Ordering)** | [`LargestDegreeOrdering.c`](./LargestDegreeOrdering.c), [`.py`](./LargestDegreeOrdering.py) | Heurística de ordenação estática | Variação de ordenação por maior grau |
| **IDO (Incidence Degree Ordering)** | [`IncidenceDegreeOrdering.c`](./IncidenceDegreeOrdering.c) | Heurística de ordenação dinâmica | Ordena vértices baseado no número de vizinhos já coloridos |
| **Color Refinement (1-WL)** | [`colorRefinament.c`](./colorRefinament.c), [`ColorRefinement.py`](./ColorRefinement.py) | Refinamento iterativo de classes | Teste 1-Weisfeiler-Lehman para detecção de não-isomorfismo |

---

## 🛠️ Utilitários de Grafos

* [`cluster.c`](./cluster.c): Cálculo do coeficiente de aglomeração (clustering coefficient) local e global.
* [`gerador.c`](./gerador.c): Gerador de grafos aleatórios e conversores para formato DIMACS.
* [`park.c`](./park.c): Estrutura para busca de caminhos e conectividade.
* [`pbm.py`](./pbm.py): Exportador de matrizes de adjacência de grafos para imagens bitmap PBM.
* [`linkedList.c`](./linkedList.c): Implementação base de listas de adjacência em C.

---

## 🚀 Como Executar

```bash
# Compilar heurística DSatur em C
gcc -O3 -Wall -Wextra DegreeofSaturation.c -o dsatur
./dsatur

# Executar First-Fit em Python
python3 FirstFit.py
```
