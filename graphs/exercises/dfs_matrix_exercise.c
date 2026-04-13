// ================================================
// Topic: DFS with Adjacency Matrix
// Language: C
// Exercises: 1 (Beginner)
// ================================================
// Adjacency Matrix: A 2D array where matrix[i][j] = 1 
// means there is an edge from vertex i to vertex j.
// ================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 10

typedef struct {
    int num_v;
    int matrix[MAX_V][MAX_V];
} Graph;

// Helper to create a graph
Graph* create_graph(int v) {
    Graph* g = malloc(sizeof(Graph));
    g->num_v = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->matrix[i][j] = 0;
        }
    }
    return g;
}

// Helper to add a directed edge
void add_edge(Graph* g, int u, int v) {
    if (u < g->num_v && v < g->num_v) {
        g->matrix[u][v] = 1;
    }
}

// ============================================
// Exercise 1: Recursive DFS (Adjacency Matrix)
// ============================================
// Problem: Implement DFS starting from vertex 'v'.
// Instead of a linked list, you must loop from 0 to g->num_v - 1.
// Check if g->matrix[v][i] == 1 to find neighbors.

void dfs_matrix(Graph* g, int v, bool visited[]) {
    // TODO:
    // 1. Mark 'v' as visited.
    visited[v] = true; 
    // 2. Print 'v'.
    printf("%d \n", v); 
    // 3. Loop through all possible vertices 'i' from 0 to num_v:
    //    a. If there is an edge (matrix[v][i] == 1) AND 'i' is not visited:
    //       i. Recurse!
    for (int i = 0; i < g->num_v; i++)
    {
        if (g->matrix[v][i] == 1 && !visited[i])
        {
            dfs_matrix(g, i, visited); 
        }
    }
}

int main() {
    Graph* g = create_graph(5);
    // 0 -> 1, 2
    // 1 -> 3
    // 2 -> 4
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);

    bool visited[5] = {false};
    printf("DFS Matrix from vertex 0: ");
    dfs_matrix(g, 0, visited);
    printf("\n");

    return 0;
}
