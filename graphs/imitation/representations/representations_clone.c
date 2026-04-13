#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Adjacency Matrix

#define MAX_V 10

typedef struct {
  int num_v; 
  bool matrix[MAX_V][MAX_V] 
} AdjMatrix; 

void init_matrix(AdjMatrix* g, int v)
{
  // graph number of vertices are whats given
  g->num_v = v; 
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      // initialize all of them to be false
      g->matrix[i][j] = false; 
    }
  }
}

void add_edge_matrix(AdjMatrix* g, int u, int v, bool directed)
{
  g->matrix[u][v] = true; 
  
  // if undirected we only add the bool to one matrix
  if (!directed) {
    g->matrix[v][u] = true; 
  }
}

void print_matrix(AdjMatrix* g)
{
  printf("\nAdjacency Matrix:\n"); 
  for (int i = 0; i < g->num_v; i++)
  {
    for (int j = 0; j < g->num_v; j++)
    {
      printf("%d ", g->matrix[i][j]); 
    }
    printf("\n"); 
  }
}


// Adjacency List
typedef struct Node {
  int vertex; 
  struct Node* next; 
} Node; 


typedef struct {
  int num_v; 
  Node** adj_lists; 
} AdjListGraph; 

Node* create_node(int v)
{
  Node* newNode = malloc(sizeof(Node)); 
  newNode->vertex = v; 
  newNode->next = NULL; 
  return newNode; 
}

AdjListGraph* create_adj_list_graph(int v)
{
  AdjListGraph* graph = malloc(sizeof(AdjListGraph)); 
  graph->num_v = v; 
  graph->adj_lists = malloc(v * sizeof(Node*)); 

  for (int i = 0; i < v; i++)
  { 
    graph->adj_lists[i] = NULL; 
  }

  return graph; 
}

void add_edge_list(AdjListGraph* g, int u, int v, bool directed)
{
  // Add edge from u to v
  Node* newNode = create_node(v); 
  newNode->next = g->adj_lists[u]; 
  g->adj_lists[u] = newNode; 

  // if undirected, add edge from v to ud
  if (!directed)
  {
    newNode = create_node(u); 
    newNode->next = g->adj_lists[v]; 
    g->adj_lists[v] = newNode; 
  }
}

void print_adj_list(AdjListGraph* g)
{
  printf("\nAdjacency List:\n"); 
  for (int i = 0; i < g->num_v; i++)
  {
    Node* temp = g->adj_lists[i]; 
    printf("%d: ", i); 
    while (temp) {
      printf("%d -> ", temp->vertex); 
    }
    printf("NULL\n"); 
  }
}

void free_adj_list(AdjListGraph* g)
{
  for (int i = 0; i < g->num_v; i++)
  {
    Node* temp = g->adj_lists[i]; 
    while (temp) {
      Node* toFree = temp; 
      temp = temp->next; 
      free(toFree); 
    }
  }
  free(g->adj_lists); 
  free(g); 
}


int main() {
  int vertices = 5; 


  // 1. Matrix Demo
  AdjMatrix m; 
  init_matrix(&m, vertices); 
  add_edge_matrix(&m, 0, 1, false); 
  add_edge_matrix(&m, 0, 4, false); 
  add_edge_matrix(&m, 1, 2, false); 
  add_edge_matrix(&m, 1, 3, false); 
  add_edge_matrix(&m, 1, 4, false); 
  add_edge_matrix(&m, 2, 3, false); 
  add_edge_matrix(&m, 3, 4, false); 
  print_matrix(&m); 

  // 2. List Demo
  AdjListGraph* l = create_adj_list_graph(vertices); 
  add_edge_list(l, 0, 1, false); 
  add_edge_list(l, 0, 4, false); 
  add_edge_list(l, 1, 2, false); 
  add_edge_list(l, 1, 3, false); 
  add_edge_list(l, 1, 4, false); 
  add_edge_list(l, 2, 3, false); 
  add_edge_list(l, 3, 4, false); 
  print_adj_list(l); 

  free_adj_list(l); 
  return 0; 

}


