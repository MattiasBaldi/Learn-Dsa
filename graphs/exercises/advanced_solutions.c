// ================================================
// Topic: Advanced Graph Algorithms - SOLUTIONS
// Language: C
// ================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_V 100

// --- Adjacency List Structure ---
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct {
    int num_v;
    Node* adj[MAX_V];
    bool is_directed;
} Graph;

Graph* create_graph(int v, bool directed) {
    Graph* g = malloc(sizeof(Graph));
    g->num_v = v;
    g->is_directed = directed;
    for (int i = 0; i < v; i++) g->adj[i] = NULL;
    return g;
}

void add_edge(Graph* g, int u, int v, int w) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
    
    if (!g->is_directed) {
        Node* newNode2 = malloc(sizeof(Node));
        newNode2->vertex = u;
        newNode2->weight = w;
        newNode2->next = g->adj[v];
        g->adj[v] = newNode2;
    }
}

// ============================================
// Exercise 1: Bipartite Graph Check
// ============================================
bool is_bipartite(Graph* g) {
    int colors[MAX_V] = {0}; // 0: uncolored, 1: red, 2: blue
    int queue[MAX_V];
    
    for (int i = 0; i < g->num_v; i++) {
        if (colors[i] == 0) {
            int front = 0, rear = 0;
            queue[rear++] = i;
            colors[i] = 1;
            
            while (front < rear) {
                int u = queue[front++];
                Node* curr = g->adj[u];
                while (curr) {
                    int v = curr->vertex;
                    if (colors[v] == 0) {
                        colors[v] = 3 - colors[u];
                        queue[rear++] = v;
                    } else if (colors[v] == colors[u]) {
                        return false;
                    }
                    curr = curr->next;
                }
            }
        }
    }
    return true;
}

// ============================================
// Exercise 2: Topological Sort
// ============================================
void topological_sort(Graph* g) {
    int indegree[MAX_V] = {0};
    for (int i = 0; i < g->num_v; i++) {
        Node* curr = g->adj[i];
        while (curr) {
            indegree[curr->vertex]++;
            curr = curr->next;
        }
    }
    
    int queue[MAX_V];
    int front = 0, rear = 0;
    for (int i = 0; i < g->num_v; i++) {
        if (indegree[i] == 0) queue[rear++] = i;
    }
    
    int count = 0;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;
        
        Node* curr = g->adj[u];
        while (curr) {
            indegree[curr->vertex]--;
            if (indegree[curr->vertex] == 0) {
                queue[rear++] = curr->vertex;
            }
            curr = curr->next;
        }
    }
    
    if (count != g->num_v) printf("\nCycle detected");
}

// ============================================
// Exercise 3: Cycle Detection - Undirected
// ============================================
typedef struct {
    int parent[MAX_V];
} DSU;

int find(DSU* dsu, int i) {
    if (dsu->parent[i] == i) return i;
    return dsu->parent[i] = find(dsu, dsu->parent[i]);
}

void unite(DSU* dsu, int i, int j) {
    int root_i = find(dsu, i);
    int root_j = find(dsu, j);
    if (root_i != root_j) dsu->parent[root_i] = root_j;
}

bool has_cycle_undirected(Graph* g) {
    DSU dsu;
    for (int i = 0; i < g->num_v; i++) dsu.parent[i] = i;
    
    // For undirected graph, we only process each edge once
    for (int u = 0; u < g->num_v; u++) {
        Node* curr = g->adj[u];
        while (curr) {
            int v = curr->vertex;
            if (u < v) { // Only process u->v if u < v to avoid double counting
                int root_u = find(&dsu, u);
                int root_v = find(&dsu, v);
                if (root_u == root_v) return true;
                unite(&dsu, root_u, root_v);
            }
            curr = curr->next;
        }
    }
    return false;
}

// ============================================
// Exercise 4: Dijkstra's Algorithm
// ============================================
int* dijkstra(Graph* g, int start_v) {
    int* dist = malloc(g->num_v * sizeof(int));
    bool visited[MAX_V] = {0};
    
    for (int i = 0; i < g->num_v; i++) dist[i] = INT_MAX;
    dist[start_v] = 0;

    for (int count = 0; count < g->num_v - 1; count++) {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < g->num_v; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v]; u = v;
            }
        }
        
        if (u == -1) break;
        visited[u] = true;
        
        Node* curr = g->adj[u];
        while (curr) {
            int v = curr->vertex;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + curr->weight < dist[v]) {
                dist[v] = dist[u] + curr->weight;
            }
            curr = curr->next;
        }
    }
    return dist;
}

// ============================================
// Exercise 5: Prim's Algorithm
// ============================================
int prim_mst_weight(Graph* g) {
    int key[MAX_V];
    bool mstSet[MAX_V] = {0};
    for (int i = 0; i < g->num_v; i++) key[i] = INT_MAX;
    key[0] = 0;
    
    int total_weight = 0;
    for (int count = 0; count < g->num_v; count++) {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < g->num_v; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v]; u = v;
            }
        }
        
        if (u == -1) break;
        mstSet[u] = true;
        total_weight += key[u];
        
        Node* curr = g->adj[u];
        while (curr) {
            int v = curr->vertex;
            if (!mstSet[v] && curr->weight < key[v]) {
                key[v] = curr->weight;
            }
            curr = curr->next;
        }
    }
    return total_weight;
}

// ============================================
// Exercise 6: Kosaraju's Algorithm
// ============================================
void dfs_finish_time(Graph* g, int v, bool visited[], int stack[], int* top) {
    visited[v] = true;
    Node* curr = g->adj[v];
    while (curr) {
        if (!visited[curr->vertex]) dfs_finish_time(g, curr->vertex, visited, stack, top);
        curr = curr->next;
    }
    stack[(*top)++] = v;
}

void dfs_simple(Graph* g, int v, bool visited[]) {
    visited[v] = true;
    Node* curr = g->adj[v];
    while (curr) {
        if (!visited[curr->vertex]) dfs_simple(g, curr->vertex, visited);
        curr = curr->next;
    }
}

int count_sccs(Graph* g) {
    bool visited[MAX_V] = {0};
    int stack[MAX_V], top = 0;
    
    for (int i = 0; i < g->num_v; i++) {
        if (!visited[i]) dfs_finish_time(g, i, visited, stack, &top);
    }
    
    Graph* transposed = create_graph(g->num_v, true);
    for (int i = 0; i < g->num_v; i++) {
        Node* curr = g->adj[i];
        while (curr) {
            add_edge(transposed, curr->vertex, i, curr->weight);
            curr = curr->next;
        }
    }
    
    for (int i = 0; i < g->num_v; i++) visited[i] = false;
    int scc_count = 0;
    while (top > 0) {
        int v = stack[--top];
        if (!visited[v]) {
            dfs_simple(transposed, v, visited);
            scc_count++;
        }
    }
    return scc_count;
}

// ============================================
// TEST SUITE
// ============================================

void test_bipartite() {
    printf("Test Bipartite: ");
    Graph* g = create_graph(4, false);
    add_edge(g, 0, 1, 1);
    add_edge(g, 1, 2, 1);
    add_edge(g, 2, 3, 1);
    add_edge(g, 3, 0, 1);
    printf("%s (Expected: PASS)\n", is_bipartite(g) ? "PASS" : "FAIL");
}

void test_topo() {
    printf("Test Topo Sort: ");
    Graph* g = create_graph(6, true);
    add_edge(g, 5, 2, 1);
    add_edge(g, 5, 0, 1);
    add_edge(g, 4, 0, 1);
    add_edge(g, 4, 1, 1);
    add_edge(g, 2, 3, 1);
    add_edge(g, 3, 1, 1);
    topological_sort(g);
    printf("\n");
}

void test_dijkstra() {
    printf("Test Dijkstra: ");
    Graph* g = create_graph(4, false);
    add_edge(g, 0, 1, 1);
    add_edge(g, 1, 2, 2);
    add_edge(g, 0, 2, 5);
    add_edge(g, 2, 3, 1);
    int* dists = dijkstra(g, 0);
    if (dists[2] == 3 && dists[3] == 4) printf("PASS\n");
    else printf("FAIL (Dist[2]=%d, Dist[3]=%d)\n", dists[2], dists[3]);
    free(dists);
}

void test_mst() {
    printf("Test MST: ");
    Graph* g = create_graph(4, false);
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 2, 6);
    add_edge(g, 0, 3, 5);
    add_edge(g, 1, 3, 15);
    add_edge(g, 2, 3, 4);
    int weight = prim_mst_weight(g);
    if (weight == 19) printf("PASS\n");
    else printf("FAIL (Weight=%d, Expected: 19)\n", weight);
}

void test_scc() {
    printf("Test SCC: ");
    Graph* g = create_graph(5, true);
    add_edge(g, 1, 0, 1);
    add_edge(g, 0, 2, 1);
    add_edge(g, 2, 1, 1);
    add_edge(g, 0, 3, 1);
    add_edge(g, 3, 4, 1);
    int count = count_sccs(g);
    if (count == 3) printf("PASS\n");
    else printf("FAIL (Count=%d, Expected: 3)\n", count);
}

int main() {
    test_bipartite();
    test_topo();
    test_dijkstra();
    test_mst();
    test_scc();
    return 0;
}
