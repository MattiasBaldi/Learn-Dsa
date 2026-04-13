#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// graph (Adjacency List) for dfs
typedef struct Node {
  int vertex; 
  struct Node* next; 
} Node; 

typedef struct {
  int num_v; 
  Node** adj_lists; 
} Graph; 

Graph* create_graph(int v)
{
  Graph* g = malloc(sizeof(Graph)); 
  g->num_v = v; 
  g->adj_lists = malloc(v * sizeof(Node*)); 
  for (int i = 0; i < v; i++) g->adj_lists[i] = NULL; 
  return g; 
}

void add_edge(Graph* g, int u, int v)
{
  Node* newNode = malloc(sizeof(Node)); 
  newNode->vertex = v; 
  newNode->next = g->adj_lists[u];
  g->adj_lists[u] = newNode;   
}

// Recursive DFS
// Time Complexity O(Vertices + edges)
// Space Complexity O(Vertices) for recursion stack

void dfs_recursive_helper(Graph* g, int v, bool visited[])
{

  // store all visited
  visited[v] = true; 
  printf("%d ", v); 

  // store a temporary variable as the first graph index
  Node* temp = g->adj_lists[v]; 
  // loop through all items
  while (temp) {
    // check adj
    int adj_v = temp->vertex; 
    // continue if it hasn't been visited
    if ((!visited[adj_v])) {
      dfs_recursive_helper(g, adj_v, visited); 
    }
    // update the temporary variable
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

// Iterative DFS
// Time complexity O(vertices + edges)
// Space Complexity O(vertices)
void dfs_iterative(Graph* g, int start_v)
{
  bool* visited = calloc(g->num_v, sizeof(bool)); 
  int* stack = malloc(g->num_v * sizeof(int)); 
  int top = -1; 

  stack[++top] = start_v; 
  printf("Iterative DFS; "); 
  while (top != -1)
  {
    int v = stack[top--]; 

    if (!visited[v])
    {
      visited[v] = true; 
      printf("%d ", v); 
    }

    Node* temp = g->adj_lists[v]; 
    while (temp) {
      int adj_v = temp->vertex; 
      if (!visited[adj_v])
      {
        stack[++top] = adj_v; 
      }
      temp = temp->next; 
    }
  }
}