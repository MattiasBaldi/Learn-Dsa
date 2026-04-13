#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
 * EXERCISE 1: RECURSIVE DFS
 */
void dfs_recursive(Graph* g, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    Node* temp = g->adj_lists[v];
    while (temp) {
        int adj_v = temp->vertex;
        if (!visited[adj_v]) {
            dfs_recursive(g, adj_v, visited);
        }
        temp = temp->next;
    }
}

/**
 * EXERCISE 2: BREADTH-FIRST SEARCH
 */
void bfs(Graph* g, int start_v) {
    bool* visited = calloc(g->num_v, sizeof(bool));
    int* queue = malloc(g->num_v * sizeof(int));
    int front = 0, rear = 0;

    visited[start_v] = true;
    queue[rear++] = start_v;

    while (front < rear) {
        int current_v = queue[front++];
        printf("%d ", current_v);

        Node* temp = g->adj_lists[current_v];
        while (temp) {
            int adj_v = temp->vertex;
            if (!visited[adj_v]) {
                visited[adj_v] = true;
                queue[rear++] = adj_v;
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    free(queue);
}

/**
 * EXERCISE 3: PATH DETECTION
 */
bool has_path(Graph* g, int src, int dest, bool visited[]) {
    if (src == dest) return true;
    visited[src] = true;

    Node* temp = g->adj_lists[src];
    while (temp) {
        int adj_v = temp->vertex;
        if (!visited[adj_v]) {
            if (has_path(g, adj_v, dest, visited)) return true;
        }
        temp = temp->next;
    }
    return false;
}

/**
 * EXERCISE 4: SHORTEST PATH (UNWEIGHTED)
 */
int shortest_path_distance(Graph* g, int src, int dest) {
    int* distance = malloc(g->num_v * sizeof(int));
    for (int i = 0; i < g->num_v; i++) distance[i] = -1;

    int* queue = malloc(g->num_v * sizeof(int));
    int front = 0, rear = 0;

    distance[src] = 0;
    queue[rear++] = src;

    while (front < rear) {
        int current_v = queue[front++];

        if (current_v == dest) {
            int result = distance[current_v];
            free(distance); free(queue);
            return result;
        }

        Node* temp = g->adj_lists[current_v];
        while (temp) {
            int adj_v = temp->vertex;
            if (distance[adj_v] == -1) {
                distance[adj_v] = distance[current_v] + 1;
                queue[rear++] = adj_v;
            }
            temp = temp->next;
        }
    }

    free(distance); free(queue);
    return -1;
}

/**
 * EXERCISE 5: CYCLE DETECTION (DIRECTED GRAPH)
 */
bool is_cyclic_util(Graph* g, int v, bool visited[], bool rec_stack[]) {
    visited[v] = true;
    rec_stack[v] = true;

    Node* temp = g->adj_lists[v];
    while (temp) {
        int adj_v = temp->vertex;
        if (!visited[adj_v]) {
            if (is_cyclic_util(g, adj_v, visited, rec_stack)) return true;
        } else if (rec_stack[adj_v]) {
            return true;
        }
        temp = temp->next;
    }

    rec_stack[v] = false;
    return false;
}

bool has_cycle(Graph* g) {
    bool* visited = calloc(g->num_v, sizeof(bool));
    bool* rec_stack = calloc(g->num_v, sizeof(bool));

    for (int i = 0; i < g->num_v; i++) {
        if (!visited[i]) {
            if (is_cyclic_util(g, i, visited, rec_stack)) {
                free(visited); free(rec_stack);
                return true;
            }
        }
    }
    free(visited); free(rec_stack);
    return false;
}

void run_tests() {
    Graph* g = create_graph(6);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 5);
    add_edge(g, 4, 5);

    printf("--- Testing Traversals ---\n");
    bool* v = calloc(6, sizeof(bool));
    printf("DFS from 0: "); dfs_recursive(g, 0, v); printf("\n");
    free(v);

    printf("BFS from 0: "); bfs(g, 0);

    printf("\n--- Testing Path Detection ---\n");
    bool* v2 = calloc(6, sizeof(bool));
    printf("Path 0->5? %s\n", has_path(g, 0, 5, v2) ? "YES" : "NO");
    free(v2);
    bool* v3 = calloc(6, sizeof(bool));
    printf("Path 5->0? %s\n", has_path(g, 5, 0, v3) ? "YES" : "NO");
    free(v3);

    printf("\n--- Testing Shortest Path ---\n");
    printf("Shortest path 0->5: %d (Expected: 3)\n", shortest_path_distance(g, 0, 5));

    printf("\n--- Testing Cycle Detection ---\n");
    printf("Has cycle? %s\n", has_cycle(g) ? "YES" : "NO");

    printf("\nAdding edge 5->2 (Creates cycle 2->3->5->2)...\n");
    add_edge(g, 5, 2);
    printf("Has cycle now? %s\n", has_cycle(g) ? "YES" : "NO");
}

int main() {
    run_tests();
    return 0;
}
