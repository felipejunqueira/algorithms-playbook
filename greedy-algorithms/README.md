# Algoritmos Gulosos (Greedy Algorithms) 🗡️

Soluções ótimas desenvolvidas em **C++** para problemas de maratona de programação e otimização utilizando a estratégia gulosa (escolha local ótima que conduz à solução global ótima).

---

## 📊 Problemas e Soluções

| Arquivo | Origem / Problema | Complexidade de Tempo | Espaço Auxiliar | Resumo da Estratégia |
| :--- | :--- | :---: | :---: | :--- |
| [`katana.cpp`](./katana.cpp) | AtCoder Beginner Contest 085 - D (*Katana Thrower*) | $O(N \log N)$ | $O(N)$ | Prioriza arremessar espadas cujo dano de arremesso excede o maior dano de golpe contínuo |
| [`ArithSeq.cpp`](./ArithSeq.cpp) | Otimização de Sequência Aritmética | $O(1)$ | $O(1)$ | Cálculo direto do número mínimo de incrementos/decrementos para satisfazer $2b = a + c$ |

---

## 🛠️ Como Compilar e Executar

```bash
# Compilar Katana Thrower
g++ -std=c++20 -O3 -Wall -Wextra katana.cpp -o katana
./katana

# Compilar Sequência Aritmética
g++ -std=c++20 -O3 -Wall -Wextra ArithSeq.cpp -o arith_seq
./arith_seq
```
