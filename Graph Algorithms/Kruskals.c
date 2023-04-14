#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 1000
#define MAX_VERTICES 1000

typedef struct Edge {
    int u, v, weight;
} Edge;

typedef struct Graph {
    int num_vertices, num_edges;
    Edge edges[MAX_EDGES];
} Graph;

Graph* create_graph(int num_vertices, int num_edges) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void union_set(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[xroot] = yroot;
}

int compare_edges(const void* a, const void* b) {
    Edge* edge_a = (Edge*) a;
    Edge* edge_b = (Edge*) b;
    return edge_a->weight - edge_b->weight;
}

void kruskal_mst(Graph* graph) {
    Edge result[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int i, e;

    qsort(graph->edges, graph->num_edges, sizeof(graph->edges[0]), compare_edges);

    for (i = 0; i < graph->num_vertices; i++)
        parent[i] = -1;

    i = 0;
    e = 0;
    while (e < graph->num_vertices - 1 && i < graph->num_edges) {
        Edge next_edge = graph->edges[i++];

        int x = find(parent, next_edge.u);
        int y = find(parent, next_edge.v);

        if (x != y) {
            result[e++] = next_edge;
            union_set(parent, x, y);
        }
    }

    printf("Edges in MST:\n");
    int total_weight = 0;
    for (i = 0; i < e; i++) {
        printf("(%d, %d) %d\n", result[i].u, result[i].v, result[i].weight);
        total_weight += result[i].weight;
    }
    printf("Total weight of MST: %d\n", total_weight);
}

int main() {
    Graph* graph = create_graph(4, 5);

    graph->edges[0].u = 0;
    graph->edges[0].v = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].u = 0;
    graph->edges[1].v = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].u = 0;
    graph->edges[2].v = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].u = 1;
    graph->edges[3].v = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].u = 2;
    graph->edges[4].v = 3;
    graph->edges[4].weight = 4;

    kruskal_mst(graph);
    return 0;
}