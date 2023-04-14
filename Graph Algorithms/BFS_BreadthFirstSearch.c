#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int adj_matrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE];
int distance[MAX_SIZE];
int parent[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1, rear = -1;

void bfs(int start, int end, int num_vertices) {
    visited[start] = true;
    distance[start] = 0;
    parent[start] = -1;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];

        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[current][i] && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[current] + 1;
                parent[i] = current;
                queue[++rear] = i;

                if (i == end) {
                    return; // Found the shortest path
                }
            }
        }
    }
}

void print_path(int start, int end) {
    if (end == -1) {
        return; // Reached the start node
    }

    print_path(start, parent[end]);
    printf("%d ", end);
}

int main() {
    int num_vertices, num_edges;
    scanf("%d %d", &num_vertices, &num_edges);

    // Initialize adjacency matrix
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj_matrix[u][v] = adj_matrix[v][u] = 1;
    }

    int start, end;
    scanf("%d %d", &start, &end);

    // Initialize visited array, distance array, and parent array
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
        distance[i] = -1;
        parent[i] = -1;
    }

    bfs(start, end, num_vertices);

    if (distance[end] == -1) {
        printf("No path found");
    } else {
        printf("Shortest path from %d to %d: ", start, end);
        print_path(start, end);
    }

    return 0;
}