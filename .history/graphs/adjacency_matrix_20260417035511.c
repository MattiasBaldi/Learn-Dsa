#include <stdio.h>
#include <stdlib.h>

/**
 * https://www.geeksforgeeks.org/dsa/graph-and-its-representations/
 * https://www.geeksforgeeks.org/c/graph-representation-using-adjacency-matrix-in-c/
 * Not the most popular graph representation, but is often used in learning or in niche performance kernels, or for smaller graphs. 
 * fast O(1) edge lookup
  small graphs
  dense graphs
  graph theory / math
  GPU kernels / linear algebra

  👉 Used, but only when graphs are small or dense.
 */

 /*
 [ 
      We use an adjacency matrix to represent connections between vertices.
      Initially, the entire matrix is filled with 0s, meaning no edges exist.
      There is an edge between vertex 0 and vertex 1,so we set mat[0][1] = 1 and mat[1][0] = 1.
      There is an edge between vertex 0 and vertex 2,so we set mat[0][2] = 1 and mat[2][0] = 1.
      There is an edge between vertex 1 and vertex 2,so we set mat[1][2] = 1 and mat[2][1] = 1.  
 ]
 */

 typedef struct {
  int vertices; 
  int** adjMatrix; 
 } Graph; 
  
 // vertices + edges (size + column size)
 Graph* createGraph(int vertices) 
 {
  Graph* graph = (Graph*)malloc(sizeof(Graph)); 
  graph->vertices = vertices; 

  // allocate memory
  graph->adjMatrix = (int**)malloc(vertices * sizeof(int*)); 
  for (int i = 0; i < vertices; i++)
  {
    graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
  }

      return graph; 

  /*
    We use an adjacency matrix to represent connections between vertices.
    Initially, the entire matrix is filled with 0s, meaning no edges exist.
    There is an edge between vertex 0 and vertex 1,so we set mat[0][1] = 1 and mat[1][0] = 1.
    There is an edge between vertex 0 and vertex 2,so we set mat[0][2] = 1 and mat[2][0] = 1.
    There is an edge between vertex 1 and vertex 2,so we set mat[1][2] = 1 and mat[2][1] = 1.
  
    Adjacency matrix for this graph:

      0 1 2
  0 [ 0 1 1 ]
  1 [ 1 0 1 ]
  2 [ 1 1 0 ]

  Flattened in memory as:
  [0, 1, 1,
   1, 0, 1,
   1, 1, 0]
  */
 }


 void addEdge(Graph* graph, int src, int dest)
 {
  if (src >= graph->vertices || dest >= graph->vertices)
  {
    printf("Invalid vertices!\n"); 
    return; 
  }
  graph->adjMatrix[src][dest] = 1; 
  graph->adjMatrix[dest][src] = 1; 
 }
  
 void displayAdjMatrix(Graph* graph)
 {
  printf("Adjacency Matrix\n"); 
  for (int i = 0; i < graph->vertices; i++)
  {
    for (int j = 0; j < graph->vertices; j++)
    {
      printf("%d ", graph->adjMatrix[i][j]); 
    }

    printf("\n"); 
  }
 }
 
 void freeGraph(Graph* graph)
 {
  for (int i = 0; i < graph->vertices; i++)
  {
    free(graph->adjMatrix[i]); 
  }
  free(graph->adjMatrix); 
  free(graph); 
 }

 int main() {
  int vertices = 5; 

  // Create a graph
  Graph* graph = createGraph(vertices); 

  // Add edges to the graph
  addEdge(graph, 0, 1); 
  addEdge(graph, 0, 4); 
  addEdge(graph, 1, 2); 
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4); 

  displayAdjMatrix(graph); 

 }

