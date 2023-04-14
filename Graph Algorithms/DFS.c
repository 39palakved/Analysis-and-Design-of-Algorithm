#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // maximum size of the graph

int graph[MAX_SIZE][MAX_SIZE]; // adjacency matrix representation of the graph
bool visited[MAX_SIZE]; // boolean array to keep track of visited nodes
int num_vertices; // number of vertices in the graph

// DFS function to traverse the graph
void DFS(int node) {
    visited[node] = true; // mark the current node as visited
    printf("%d ", node); // print the current node

    for (int i = 0; i < num_vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i); // recursively call DFS for unvisited adjacent nodes
        }
    }
}

// function to find the connected components in the graph
void findConnectedComponents() {
    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i]) {
            printf("Connected component: ");
            DFS(i); // call DFS for each unvisited node
            printf("\n");
        }
    }
}

int main() {
    // read the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    // read the adjacency matrix of the graph
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // initialize the visited array to false
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }

    // find the connected components in the graph
    findConnectedComponents();

    return 0;
}