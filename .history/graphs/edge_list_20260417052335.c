#include <stdio.h>
#include <stdlib.h>

/**
 * Array of pairs
 * 
 */

 typedef struct Edge {
  int start; 
  int end; 
 } Edge; 

 // Edgelist
 struct Graph {
  int** edges;
  int edgesSize; 
  int edgesColSize;  
 } Graph; 

struct Graph* createGraph(int edgesColSize) {

  // allocate memory
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->edges = (Edge*)malloc(edgesColSize * sizeof(Edge)); 
  graph->edgesSize = 0; 
  graph->edgesColSize = edgesColSize; 

  return graph; 
}; 


void addEdge() {
  

}

void freeGraph() {
  
}

void printGraph() {

}

int main() {


  return 0;
}