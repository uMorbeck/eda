#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned from, to;
    int weight;
} Edge;

typedef struct {
    int **edges;
    unsigned V, E;
} Graph;

int tc[2001][2001];

Graph iniciar_grafo(unsigned vertices) {
    Graph g = {.V = vertices, .E = 0};
    g.edges = malloc(sizeof(int *) * g.V);
    for (unsigned i = 0; i < g.V; i++) {
        g.edges[i] = malloc(sizeof(int) * g.V);
        for (unsigned j = 0; j < g.V; j++)
            g.edges[i][j] = 2147483647;
    }
    return g;
}

void limpa_grafo(Graph g) {
    for (unsigned i = 0; i < g.V; i++)
        free(g.edges[i]);
    free(g.edges);
}

void insere_grafo(Graph *g, Edge e) {
    if (e.from > g->V || e.to > g->V)
        return;

    g->E += (g->edges[e.from][e.to] == 2147483647);
    g->edges[e.from][e.to] = e.weight;
}

void transitiveClosure(Graph g, int transitive[][2001]) {
    for (unsigned i = 0; i < g.V; i++) {
        for (unsigned j = 0; j < g.V; j++)
            transitive[i][j] = g.edges[i][j] != 2147483647;
        transitive[i][i] = 1;
    }

    for (unsigned i = 0; i < g.V; i++)
        for (unsigned j = 0; j < g.V; j++)
            if (transitive[j][i] == 1)
                for (unsigned k = 0; k < g.V; k++)
                    if (transitive[i][k] == 1)
                        transitive[j][k] = 1;
}


int main() {
    int v;
    scanf(" %d", &v);

    Graph g = iniciar_grafo(v);
    for (int f, t, d; scanf(" %d %d %d", &f, &t, &d) == 3 && d;)
    {
        insere_grafo(&g, (Edge){.from = f, .to = t, .weight = 1});
        if (d == 2)
            insere_grafo(&g, (Edge){.from = t, .to = f, .weight = 1});
    }

    transitiveClosure(g, tc);
    limpa_grafo(g);

    for (int t, x; scanf(" %d %d", &t, &x) == 2;)
        printf("%s\n", (tc[t][x] && tc[x][t] ? "Ida e Volta" : (tc[t][x] ? "Apenas Ida" : (tc[x][t] ? "Apenas Volta" : "Impossibru"))));

    return 0;
}