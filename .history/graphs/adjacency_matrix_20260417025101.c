#include <stdio.h>
#include <stdlib.h>

/**
 * https://www.geeksforgeeks.org/dsa/graph-and-its-representations/
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
  
 // vertices + edges (size + column size)
 int* createGraph(int v, int** edges, int edgesSize, int* edgesColSize) 
 {

  // allocate memory
  int *matrix = calloc(v * v, sizeof(int)); 
  if (!matrix) return NULL; 

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

  // add each edge to the adjacency matrix
  for (int i = 0; i < edges; i++)
  {
    int u = edges[i]; 
    int v = edges[i+1];
    
    // since its an undirected graph, both gets a 1
    matrix[u][v] = 1; 

  }

  return matrix; 
 }

 int main() {
  int V = 3; 


 }

