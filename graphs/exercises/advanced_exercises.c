// ================================================
// Topic: Advanced Graph Algorithms
// Language: C
// Exercises: 6 (Intermediate: 3 | Advanced: 3)
// ================================================
// This file contains exercises for more advanced graph algorithms
// including shortest paths, spanning trees, and connectivity.
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
// Exercise 1: Bipartite Graph Check (Intermediate)
// ============================================
// Problem: Check if a graph is bipartite. A graph is bipartite if 
// its vertices can be divided into two independent sets U and V 
// such that every edge connects a vertex in U to one in V.
// Hint: Use 2-coloring (BFS or DFS).
// Return true if bipartite, false otherwise.

bool is_bipartite(Graph* g) {
    // TODO: Implement bipartite check using 2-coloring
    // 0: uncolored, 1: color A, 2: color B
    int colors[MAX_V] = {0};
    
    return true;
}

// ============================================
// Exercise 2: Topological Sort (Intermediate)
// ============================================
// Problem: Find a topological ordering of vertices in a DAG (Directed Acyclic Graph).
// Use Kahn's Algorithm (indegree-based).
// Print the ordering. If a cycle exists, print "Cycle detected".

void topological_sort(Graph* g) {
    // TODO: 
    // 1. Calculate indegree of all vertices.
    // 2. Enqueue all vertices with indegree 0.
    // 3. While queue is not empty:
    //    a. Dequeue u, print it.
    //    b. For each neighbor v of u, decrement indegree[v].
    //    c. If indegree[v] == 0, enqueue v.
}

// ============================================
// Exercise 3: Cycle Detection - Undirected (Intermediate)
// ============================================
// Problem: Detect if an undirected graph has a cycle using Union-Find.
// Use Path Compression for optimization.

typedef struct {
    int parent[MAX_V];
} DSU;

int find(DSU* dsu, int i) {
    // TODO: Implement find with path compression
    return i;
}

void unite(DSU* dsu, int i, int j) {
    // TODO: Implement union
}

bool has_cycle_undirected(Graph* g) {
    // TODO: Implement cycle detection using DSU
    return false;
}

// ============================================
// Exercise 4: Dijkstra's Algorithm (Advanced)
// ============================================
// Problem: Find the shortest path distances from a source vertex to all others.
// Return an array of distances. (Use INT_MAX for unreachable).
// Hint: For simplicity, you can use a basic O(V^2) approach or a priority queue if you have one.

int* dijkstra(Graph* g, int start_v) {
    int* dist = malloc(g->num_v * sizeof(int));
    bool visited[MAX_V] = {0};
    
    for (int i = 0; i < g->num_v; i++) dist[i] = INT_MAX;
    dist[start_v] = 0;

    // TODO: Implement Dijkstra
    
    return dist;
}

// ============================================
// Exercise 5: Prim's Algorithm (Advanced)
// ============================================
// Problem: Find the weight of the Minimum Spanning Tree (MST).
// Hint: Similar to Dijkstra but pick the minimum edge connecting to the MST.

int prim_mst_weight(Graph* g) {
    // TODO: Implement Prim's Algorithm
    return 0;
}

// ============================================
// Exercise 6: Kosaraju's Algorithm (Advanced)
// ============================================
// Problem: Count the number of Strongly Connected Components (SCCs) in a directed graph.
// Steps:
// 1. DFS to fill a stack based on finish times.
// 2. Transpose the graph.
// 3. DFS on transposed graph in order of stack.

int count_sccs(Graph* g) {
    // TODO: Implement Kosaraju's
    return 0;
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
    topological_sort(g); // Should print a valid topo order
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

int main() {
    test_bipartite();
    test_topo();
    test_dijkstra();
    return 0;
}
