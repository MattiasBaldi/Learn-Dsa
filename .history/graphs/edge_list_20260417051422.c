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

 struct Graph {
  int** edges;
  int edgesSize; 
  int edgesColSize;  
 } Graph; 

struct Graph* createGraph(int edgesColSize) {

  // allocate memory
  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->edges = malloc(edgesColSize * sizeof *graph->edges); 
  graph->edgesSize = 0; 
  graph->edgesColSize = 0; 

  return graph; 
}; 

void addEdge() {
  

}

void printGraph() {

}

int main() {


  return 0;
}