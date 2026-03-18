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

