/*
COMPLEXIDADE
O REP roda M vezes lendo com scanf, custo O(M)
A ordenacao (gargalo) O(MlogM) usando qsort padrao do C
O loop principal e o union-find O(M * alpha(N)) que eu nao conhecia, de acordo
com esse site: https://cp-algorithms.com/data_structures/disjoint_set_union.html
Sem a otimizacao o total seria O(M * N)
Com a otimizacao ficamos com O(alpha(N))

TOTAL = O(M) + O(MlogM) + O(M * alpha(N)) = O(MLogM)

o espaco guarda o vetor de aresta e o vetor dos pais, O(N + M)
*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10005
#define REP(i, n) for(int i=0; i<n; i++) // brincando de substituir o for
#define IMPOSSIVEL -1

typedef struct{
    int origem, destino, custo;
}Aresta;

int pred[MAX_N];
Aresta lista_arestas[MAX_N * 10]; //chutando com seguranca

int func_comp(const void*a, const void*b){
    Aresta *a1 = (Aresta*)a;
    Aresta *a2 = (Aresta*)b;
    return a1->custo - a2->custo;
}

int busca_chefe(int i){
    if(pred[i] == i) return i;
    return busca_chefe(pred[i]);
}


int main(){
    int n=0,m=0,cenario=1;
    while(scanf("%d", &n) && n != 0){
        scanf("%d", &m);
        REP(i, m){
            scanf("%d %d %d", &lista_arestas[i].origem, &lista_arestas[i].destino, &lista_arestas[i].custo);
        }
        // ordenar a lista melhor que ordenar matriz. 
        // assim nao corre o risco de se precipitar em
        // pegar alguma aresta cara logo no comeco
        qsort(lista_arestas, m, sizeof(Aresta), func_comp);

        for(int i = 1; i<=n; i++) pred[i] = i;
        int custo_total = 0;
        int arestas_selecionadas = 0;

        REP(i, m){
            int u = lista_arestas[i].origem;
            int v = lista_arestas[i].destino;
            int c = lista_arestas[i].custo;

            int chefe_u = busca_chefe(u);
            int chefe_v = busca_chefe(v);

            if(chefe_u != chefe_v){
                pred[chefe_u] = chefe_v; // uniao dos grupos
                custo_total += c;
                arestas_selecionadas++;
            }
        }
        printf("Cenario %d: ", cenario);

        if(arestas_selecionadas < n - 1) printf("%d\n", IMPOSSIVEL);
        else printf("%d\n", custo_total);
        cenario++;
    }
    return 0;
}