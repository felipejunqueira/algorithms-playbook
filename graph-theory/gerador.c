/*
 EP 1 - Algoritmos em Grafos
 Analise de complexidade: O(H * N^2) pois percorre o tempo H e para cada t percorre a matriz de adjacencia.
 Como N <= 100 e H <= 6000, roda dentro do tempo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 100
#define MAX_TEMPO 6000

typedef struct {
    int c; // custo (km)
    int t; // tempo (min)
    int existe;
} Aresta;

// globais para nao ficar passando muitos argumentos na funcao
Aresta adj[MAX][MAX]; // uma matriz das cidades com os cruzamentos do tipo struct
int dist[MAX][MAX_TEMPO]; // dist[cidade][tempo] 

void bfm(int n, int orig, int dest, int h) {
    int i, t, j;
    // Inicializa a tabela com infinito
    for (i = 0; i <= n; i++) {
        for (t = 0; t <= h; t++) {
            dist[i][t] = INF;
        }
    }
    dist[orig][0] = 0;
    // loop principal: avanca no tempo
    // parece algoritmo do FW mas nao eh porque o primeiro for itera sobre o tempo
    for (t = 0; t <= h; t++) {
        for (i = 1; i <= n; i++) {
            if (dist[i][t] == INF) continue;
            // verifica vizinhos
            for (j = 1; j <= n; j++) {
                if (adj[i][j].existe) {
                    int novo_t = t + adj[i][j].t;
                    int novo_c = dist[i][t] + adj[i][j].c;
                    if (novo_t <= h) {
                        if (novo_c < dist[j][novo_t]) dist[j][novo_t] = novo_c;
                    }
                }
            }
        }
    }
    // aqui entra a logica do Moore
    // pegar o melhor resultado
    int min_c = INF;
    int min_t = -1;
    for (t = 0; t <= h; t++) {
        if (dist[dest][t] < min_c) {
            min_c = dist[dest][t];
            min_t = t;
        }
    }
    if (min_c == INF) printf("Impossivel\n");
    else printf("Possivel - %d km, %d min\n", min_c, min_t);
}
// meus colegas falaram que esse codigo esta ineficiente por percorrer as 6000 colunas mas
// ele na vdd nao "morre na praia", o que acontece quando o algoritmo armazena o primeiro
// mais curto, porem futuramente perde outro caminho um pouco mais longo com o tempo que se adequa
// ao limite. esse problema ocorre usando outra estrutura de dados como dois vetores, trabalhar apenas
// em 1 dimensao

int main() {
    int n, m, k, u, v, c, t, i, j, conta_inst = 1;
    // leitura ate acabar arquivo
    while (scanf("%d %d", &n, &m) == 2 && n != 0) {
        // limpa grafo
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                adj[i][j].existe = 0;
            }
        }
        // ler arestas
        for (i = 0; i < m; i++) {
            scanf("%d %d %d %d", &u, &v, &c, &t);
            adj[u][v].c = c;
            adj[u][v].t = t;
            adj[u][v].existe = 1;
        }
        scanf("%d", &k);
        printf("Instancia %d\n", conta_inst++);
        // processa as entregas
        for (i = 0; i < k; i++) {
            int o, d, h;
            scanf("%d %d %d", &o, &d, &h);
            bfm(n, o, d, h);
        }
        printf("\n");
    }
    return 0;
}