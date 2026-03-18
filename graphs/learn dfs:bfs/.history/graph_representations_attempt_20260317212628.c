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

int main() {
  AdjacencyMatrix *matrix = create_adj_matrix(4, 0); // Allocate
  add_edge_matrix(matrix, 0, 1, 1); 
  add_edge_matrix(matrix, 1, 2, 1);  
  print_adj_matrix(matrix); 
  free_adj_matrix(matrix); 
  return 0; 
}

