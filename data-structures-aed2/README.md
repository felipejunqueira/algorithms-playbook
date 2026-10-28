# Estruturas de Dados (AED 2) 🧱

Este módulo reúne implementações em C desenvolvidas para a disciplina de **Algoritmos e Estruturas de Dados II** (UFABC), com ênfase em **Tabelas Hash**, tratamento de colisões e estruturas em árvore balanceadas.

---

## 📊 Sumário das Implementações de Tabelas Hash

| Arquivo | Política de Colisão | Tipo de Chave | Descrição |
| :--- | :--- | :--- | :--- |
| [`HashList.c`](./HashList.c) | Encadeamento Exterior (Separate Chaining) | Inteiro (`int`) | Lista encadeada dinâmica para cada índice da tabela |
| [`HashVet.c`](./HashVet.c) | Endereçamento Aberto (Open Addressing) | Inteiro (`int`) | Sondagem linear (Linear Probing) no próprio vetor |
| [`HashString.c`](./HashString.c) | Encadeamento Exterior | String / Struct | Tabela hash com registros contratuais, datas e endereços |
| [`HashStruct.c`](./HashStruct.c) | Encadeamento Exterior | Struct | Mapeamento de registros estruturados completos |
| [`HashQ1.c`](./HashQ1.c) | Encadeamento Exterior | Caractere (`A-Z`) | Indexação alfabética de países e capitais |

---

## 📁 Projetos e Práticas (PAs)

| Diretório | Conteúdo e Tópicos Abordados |
| :--- | :--- |
| [`PA1/`](./PA1/) | Listas encadeadas, filas, pilhas e manipulação de ponteiros (`q1.c` a `q7.c`) |
| [`PA2/`](./PA2/) | Tabelas hash com listas e endereçamento aberto (`AED-II-*.c`, `q1.c` a `q6.c`) |
| [`PA3/`](./PA3/) | Árvores binárias de busca, árvores balanceadas (AVL) e tabelas de consulta (`q1.c` a `q3.c`, `L3.c`) |
| [`PA4/`](./PA4/) | Árvores B e indexação de dados em memória secundária (`q1.c`) |

---

## 🛠️ Como Compilar e Executar

Utilize o compilador GCC com otimizações:

```bash
# Exemplo: compilar a tabela hash com listas encadeadas
gcc -O3 -Wall -Wextra HashList.c -o hash_list
./hash_list

# Exemplo: compilar uma questão de PA
gcc -O3 -Wall -Wextra PA1/q1.c -o pa1_q1
./pa1_q1
```
