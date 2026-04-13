#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Graph structure (Adjacency List) for DFS demo
 */
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int num_v;
    Node** adj_lists;
} Graph;

Graph* create_graph(int v) {
    Graph* g = malloc(sizeof(Graph));
    g->num_v = v;
    g->adj_lists = malloc(v * sizeof(Node*));
    for (int i = 0; i < v; i++) g->adj_lists[i] = NULL;
    return g;
}

void add_edge(Graph* g, int u, int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adj_lists[u];
    g->adj_lists[u] = newNode;
}

/**
 * ============================================================================
 * 1. RECURSIVE DFS
 * ============================================================================
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) for recursion stack
 */
void dfs_recursive_helper(Graph* g, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    Node* temp = g->adj_lists[v];
    while (temp) {
        int adj_v = temp->vertex;
        if (!visited[adj_v]) {
            dfs_recursive_helper(g, adj_v, visited);
        }
        temp = temp->next;
    }
}

void dfs_recursive(Graph* g, int start_v) {
    bool* visited = calloc(g->num_v, sizeof(bool));
    printf("Recursive DFS: ");
    dfs_recursive_helper(g, start_v, visited);
    printf("\n");
    free(visited);
}

/**
 * ============================================================================
 * 2. ITERATIVE DFS (Using Stack)
 * ============================================================================
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
void dfs_iterative(Graph* g, int start_v) {
    bool* visited = calloc(g->num_v, sizeof(bool));
    int* stack = malloc(g->num_v * sizeof(int));
    int top = -1;

    stack[++top] = start_v;

    printf("Iterative DFS: ");
    while (top != -1) {
        int v = stack[top--];

        if (!visited[v]) {
            visited[v] = true;
            printf("%d ", v);
        }

        Node* temp = g->adj_lists[v];
        while (temp) {
            int adj_v = temp->vertex;
            if (!visited[adj_v]) {
                stack[++top] = adj_v;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(stack);
}

int main() {
    Graph* g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 3);

    dfs_recursive(g, 2);
    dfs_iterative(g, 2);

    return 0;
}
