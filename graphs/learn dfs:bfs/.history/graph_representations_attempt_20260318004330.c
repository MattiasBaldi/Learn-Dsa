#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Adjacency Matrix */
// Best for dense graphs, fast edge lookups
typedef struct {
  int **matrix; /// 
  int num_vertices; 
  int is_weighted; 
} AdjacencyMatrix; 

AdjacencyMatrix* create_adj_matrix(int num_vertices, int is_weighted) {
  AdjacencyMatrix *graph = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
  graph->num_vertices = num_vertices;
  graph->is_weighted = is_weighted; 
  graph->matrix = (int**)malloc(num_vertices * sizeof(int*)); 

  for (int i = 0; i < num_vertices; i++)
  {
    graph->matrix[i] = (int*)calloc(num_vertices, sizeof(int)); 
  }

  return graph; 
}

void add_edge_matrix(AdjacencyMatrix *graph, int u, int v, int weight) {
  graph->matrix[u][v] = weight;   // For undirected: graph->matrix[v][u] = weight; 
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
  for (int i = 0; i < graph->num_vertices; i++)
  {
    free(graph->matrix[i]); 
  }
  free(graph->matrix); 
  free(graph); 
}

/* Adjacency List */
/* Best for: Sparse graphs, memory efficient */
typedef struct Node {
  int vertex; 
  int weight; 
  struct Node *next; 
} Node; 

typedef struct {
  Node **list; 
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
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Vertex %d: ", i); 
    Node *current = graph->list[i]; 
    while (current) {
      printf("-> %d", current->vertex); 
      if (graph->is_weighted) printf("(w:%d)", current->weight); 
      current = current->next;     
    }

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


// Edge list
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

EdgeList* create_edge_list(int num_vertices, int capacity, int is_weighted)
{
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
  printf("\n=== Edge List === \n"); 
  for (int i = 0;  i < graph->num_edges; i++) {
    printf("Edge %d: %d -> %d", i, graph->edges[i].source, graph->edges[i].destination); 
    if (graph->is_weighted) printf(" (weight: %d)", graph->edges[i].weight); 
    printf("\n"); 
  }
}

// Main
int main() {

  int num_vertices = 4;

  /// --- ADJACENCY MATRIX ---
  AdjacencyMatrix *matrix = create_adj_matrix(num_vertices, 0); // Allocate
  add_edge_matrix(matrix, 0, 1, 1); 
  add_edge_matrix(matrix, 1, 2, 1);  
  print_adj_matrix(matrix); 
  free_adj_matrix(matrix); 

  /// --- ADJACENCY LIST ---
  AdjacencyList *adj_list = create_adj_list(num_vertices, 0); 
  add_edge_list(adj_list, 0, 1, 1); 
  add_edge_list(adj_list, 1, 2, 1); 
  add_edge_list(adj_list, 2, 3, 1); 
  add_edge_list(adj_list, 3, 0, 1); 
  print_adj_list(adj_list); 
  free_adj_list(adj_list); 


  return 0; 
}

