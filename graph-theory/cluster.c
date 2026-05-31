#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXN 4010 // 1000 tarefas * 2 pontos + extras. margem segura
#define INF 1e9 // infinito
#define N_INF 1e-9
#define ms(a, v) memset(a, v, sizeof(a)) // inicializar os vetores
#define min(a, b) ((a) < (b) ? (a) : (b))

float cap[MAXN][MAXN]; // capacidade
float flow[MAXN][MAXN]; // fluxo atual
int pai[MAXN]; // para bfs
int tempos[MAXN]; // pontos de tempo discretos  

typedef struct {
    float p; // processamento
    int r; // inicio
    int d; // fim
} Tarefa;

Tarefa task[1005];

// funcao pra ser usada no qsort
int func_comparar(const void* a, const void* b){
    const int* pa = (const int*)a;
    const int* pb = (const int*)b; 
    return (*pa) - (*pb);
}

int bfs(int s, int t, int total_nos); // retorna o caminho percorrido 

float edmonds_karp(int s, int t, int total_nos); // retorna o fluxo maximo

int main(){
    int m, n, caso = 1;

    while(scanf("%d %d", &m, &n) && (m != 0 || n != 0)){
        ms(cap, 0);
        ms(flow, 0);
        int k = 0; // contar os tempos
        float req_total = 0; // requisito total

        for(int i = 1; i<=n; i++){
            scanf("%f %d %d", &task[i].p, &task[i].r, &task[i].d);
            // guardar r e d na lista de tempos;
            tempos[k++] = task[i].r;
            tempos[k++] = task[i].d;
            req_total += task[i].p;
        }
        // criamos os intervalos de tempos, ordenamos e removemos duplicatas
        qsort(tempos, k, sizeof(int), func_comparar);
        int duplic = 0;
        for(int i=0; i<k; i++){
            if(i==0 || tempos[i] != tempos[i-1])
                tempos[duplic++] = tempos[i];
        } // dessa maneira nao precisamos usar 2 vetores pra comparar, o resto do vetor sera ignorado

        int n_interv = duplic - 1;
        int S = 0;
        int T = n + n_interv + 1; // sorvedouro eh o ultimo
        int total_nos = T + 1;

        // montar o grafo
        for(int i=1; i<=n; i++) cap[S][i] = task[i].p;
        for(int j=0; j<n_interv; j++){
            int t_start = tempos[j];
            int t_end = tempos[j+1];
            int dur = t_end - t_start; // duracao da tarefa
            int u_interv = n+1+j; // ID do intervalo

            cap[u_interv][T] = (float)m * dur;
            for(int i=1; i<=n; i++){
                if(task[i].r <= t_start && task[i].d >= t_end){
                    cap[i][u_interv] = (float)dur; // sem clonagem
                }
            }
        }
        float mf = edmonds_karp(S, T, total_nos);
        printf("Instancia %d\n", caso++);
        if(fabs(mf - req_total) < N_INF) printf("Viavel\n\n");
        else printf("Inviavel\n\n");
    }
    return 0;
}


int bfs(int s, int t, int total_nos){
    ms(pai, -1);
    int q[MAXN], head = 0, tail = 0; // fila simples

    q[tail++] = s;
    pai[s] = -2; // ja visitado
    
    while(head < tail){
        int u = q[head++];
        for(int v = 0; v < total_nos; v++){
            // se nao visitado e tem capacidade residual
            if(pai[v] == -1 && (cap[u][v] - flow[u][v] > N_INF)) { // maior que infinito negativo
                pai[v] = u;
                if(v == t) return 1;
                q[tail++] = v;
            }
        }
    }
    return 0;
}

float edmonds_karp(int s, int t, int total_nos){
    float mf = 0.0; // max flow
    while(bfs(s, t, total_nos)) {
        float push = INF;

        // achar o gargalo
        for(int v = t; v != s; v = pai[v]) { // de tras p frente
            int u = pai[v];
            push = min(push, cap[u][v] - flow[u][v]); // a rede residual eh calculada na hora  
        }

        for(int v=t; v!=s; v = pai[v]){
            int u = pai[v];
            flow[u][v] += push;
            flow[v][u] -= push;
        }
        mf += push;
    }
    return mf;
}