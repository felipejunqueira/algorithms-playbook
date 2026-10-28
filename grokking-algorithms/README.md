# Entendendo Algoritmos (Grokking Algorithms) 📖

Códigos de estudo e implementações práticas baseados no livro didático *"Grokking Algorithms: An Illustrated Guide for Programmers and Other Curious People"* de Aditya Y. Bhargava.

---

## 📊 Relação dos Exercícios e Algoritmos

| Capítulo / Tema | Arquivo Python | Arquivo C / Java | Algoritmo / Conceito |
| :--- | :--- | :--- | :--- |
| **Cap. 1: Busca Binária** | [`1.py`](./1.py), [`cobra.py`](./cobra.py) | - | Busca binária iterativa em lista ordenada ($O(\log n)$) |
| **Cap. 2: Ordenação por Seleção** | [`2.py`](./2.py) | [`2.c`](./2.c) | Selection Sort ($O(n^2)$) |
| **Cap. 3: Recursão** | [`4.py`](./4.py), [`6.py`](./6.py) | - | Casos base, contagem regressiva e cálculo de fatorial recursivo |
| **Cap. 4: Divisão e Conquista** | [`7.py`](./7.py), [`8.py`](./8.py) | [`5.c`](./5.c), [`7.c`](./7.c), [`8.c`](./8.c) | Quicksort, soma recursiva, contagem de itens em listas |
| **Cap. 5: Tabelas Hash** | [`9.py`](./9.py), [`10.py`](./10.py), [`11.py`](./11.py) | [`9.c`](./9.c), [`j9.java`](./j9.java) | Dicionários, verificação de votantes duplicados e sistema de cache |
| **Cap. 6: Pesquisa em Largura** | [`12.py`](./12.py) | [`j13.java`](./j13.java) | BFS (Breadth-First Search) para caminhos mais curtos em grafos não ponderados |
| **Cap. 7: Algoritmo de Dijkstra** | [`13.py`](./13.py) | - | Menor caminho em grafos valorados com pesos não-negativos |
| **Cap. 8: Algoritmos Gulosos** | [`14.py`](./14.py), [`15.py`](./15.py) | [`j15.java`](./j15.java) | Problema da Cobertura de Conjuntos (*Set Cover Problem*) com aproximação gulosa |

---

## 🛠️ Como Executar os Códigos

Este módulo conta com um `Makefile` configurado para testes rápidos:

```bash
# Executar o código C principal
make c

# Executar o script Python de teste
make p

# Executar qualquer script Python diretamente
python3 8.py

# Compilar e rodar arquivos Java
javac j15.java && java j15
```
