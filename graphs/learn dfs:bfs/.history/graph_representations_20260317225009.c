#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== REPRESENTATION 1: ADJACENCY MATRIX ===== */
/* Best for: Dense graphs, fast edge lookups */
typedef struct {
    int **matrix;  // 2D array where matrix[i][j] = weight/1 if edge exists
    int num_vertices;
    int is_weighted;
} AdjacencyMatrix;

AdjacencyMatrix* create_adj_matrix(int num_vertices, int is_weighted) {
    AdjacencyMatrix *graph = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    graph->num_vertices = num_vertices;
    graph->is_weighted = is_weighted;

    graph->matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->matrix[i] = (int*)calloc(num_vertices, sizeof(int));
    }
    return graph;
}

void add_edge_matrix(AdjacencyMatrix *graph, int u, int v, int weight) {
    graph->matrix[u][v] = weight;
    // For undirected: graph->matrix[v][u] = weight;
}

void print_adj_matrix(AdjacencyMatrix *graph) {
    printf("\n=== ADJACENCY MATRIX ===\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void free_adj_matrix(AdjacencyMatrix *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}


/* ===== REPRESENTATION 2: ADJACENCY LIST ===== */
/* Best for: Sparse graphs, memory efficient */
typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct {
    Node **list;  // Array of linked lists
    int num_vertices;
    int is_weighted;
} AdjacencyList;

AdjacencyList* create_adj_list(int num_vertices, int is_weighted) {
    AdjacencyList *graph = (AdjacencyList*)malloc(sizeof(AdjacencyList));
    graph->num_vertices = num_vertices;
    graph->is_weighted = is_weighted;

    graph->list = (Node**)calloc(num_vertices, sizeof(Node*));
    return graph;
}

void add_edge_list(AdjacencyList *graph, int u, int v, int weight) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->weight = weight;
    new_node->next = graph->list[u];
    graph->list[u] = new_node;
}

void print_adj_list(AdjacencyList *graph) {
    printf("\n=== ADJACENCY LIST ===\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        Node *current = graph->list[i];
        while (current) {
            printf("-> %d", current->vertex);
            if (graph->is_weighted) printf("(w:%d)", current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

void free_adj_list(AdjacencyList *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Node *current = graph->list[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->list);
    free(graph);
}


/* ===== REPRESENTATION 3: EDGE LIST ===== */
/* Best for: Simple storage, iteration over edges */
typedef struct {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct {
    Edge *edges;
    int num_edges;
    int num_vertices;
    int capacity;
    int is_weighted;
} EdgeList;

EdgeList* create_edge_list(int num_vertices, int capacity, int is_weighted) {
    EdgeList *graph = (EdgeList*)malloc(sizeof(EdgeList));
    graph->num_vertices = num_vertices;
    graph->capacity = capacity;
    graph->num_edges = 0;
    graph->is_weighted = is_weighted;

    graph->edges = (Edge*)malloc(capacity * sizeof(Edge));
    return graph;
}

void add_edge_to_list(EdgeList *graph, int u, int v, int weight) {
    if (graph->num_edges >= graph->capacity) {
        graph->capacity *= 2;
        graph->edges = (Edge*)realloc(graph->edges, graph->capacity * sizeof(Edge));
    }
    graph->edges[graph->num_edges].source = u;
    graph->edges[graph->num_edges].destination = v;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

void print_edge_list(EdgeList *graph) {
    printf("\n=== EDGE LIST ===\n");
    for (int i = 0; i < graph->num_edges; i++) {
        printf("Edge %d: %d -> %d", i, graph->edges[i].source, graph->edges[i].destination);
        if (graph->is_weighted) printf(" (weight: %d)", graph->edges[i].weight);
        printf("\n");
    }
}

void free_edge_list(EdgeList *graph) {
    free(graph->edges);
    free(graph);
}


/* ===== REPRESENTATION 4: INCIDENCE MATRIX ===== */
/* Best for: Edge-centric algorithms */
typedef struct {
    int **matrix;  // matrix[vertex][edge] = +1 (leaving), -1 (entering), 0 (not incident)
    int num_vertices;
    int num_edges;
} IncidenceMatrix;

IncidenceMatrix* create_incidence_matrix(int num_vertices, int num_edges) {
    IncidenceMatrix *graph = (IncidenceMatrix*)malloc(sizeof(IncidenceMatrix));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;

    graph->matrix = (int**)malloc(num_vertices * sizeof(int*));
    for (int i = 0; i < num_vertices; i++) {
        graph->matrix[i] = (int*)calloc(num_edges, sizeof(int));
    }
    return graph;
}

void add_edge_incidence(IncidenceMatrix *graph, int edge_idx, int from, int to) {
    graph->matrix[from][edge_idx] = 1;   // Outgoing
    graph->matrix[to][edge_idx] = -1;    // Incoming
}

void print_incidence_matrix(IncidenceMatrix *graph) {
    printf("\n=== INCIDENCE MATRIX ===\n");
    printf("     ");
    for (int j = 0; j < graph->num_edges; j++) {
        printf("e%d ", j);
    }
    printf("\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("v%d: ", i);
        for (int j = 0; j < graph->num_edges; j++) {
            printf("%2d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void free_incidence_matrix(IncidenceMatrix *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}


/* ===== DEMO ===== */
int main() {
    printf("======= GRAPH REPRESENTATIONS =======\n");

    // Example: 4 vertices, edges 0->1, 1->2, 2->3, 3->0
    int num_vertices = 4;

    // --- ADJACENCY MATRIX ---
    AdjacencyMatrix *adj_matrix = create_adj_matrix(num_vertices, 0);
    add_edge_matrix(adj_matrix, 0, 1, 1);
    add_edge_matrix(adj_matrix, 1, 2, 1);
    add_edge_matrix(adj_matrix, 2, 3, 1);
    add_edge_matrix(adj_matrix, 3, 0, 1);
    print_adj_matrix(adj_matrix);
    free_adj_matrix(adj_matrix);

    // --- ADJACENCY LIST ---
    AdjacencyList *adj_list = create_adj_list(num_vertices, 0);
    add_edge_list(adj_list, 0, 1, 1);
    add_edge_list(adj_list, 1, 2, 1);
    add_edge_list(adj_list, 2, 3, 1);
    add_edge_list(adj_list, 3, 0, 1);
    print_adj_list(adj_list);
    free_adj_list(adj_list);

    // --- EDGE LIST ---
    EdgeList *edge_list = create_edge_list(num_vertices, 10, 0);
    add_edge_to_list(edge_list, 0, 1, 1);
    add_edge_to_list(edge_list, 1, 2, 1);
    add_edge_to_list(edge_list, 2, 3, 1);
    add_edge_to_list(edge_list, 3, 0, 1);
    print_edge_list(edge_list);
    free_edge_list(edge_list);

    // --- INCIDENCE MATRIX ---
    IncidenceMatrix *incidence = create_incidence_matrix(num_vertices, 4);
    add_edge_incidence(incidence, 0, 0, 1);
    add_edge_incidence(incidence, 1, 1, 2);
    add_edge_incidence(incidence, 2, 2, 3);
    add_edge_incidence(incidence, 3, 3, 0);
    print_incidence_matrix(incidence);
    free_incidence_matrix(incidence);

    return 0;
}
