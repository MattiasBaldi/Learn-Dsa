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
  Edge *edges;
  int edgesSize; 
  int capacity;  
 } Graph; 

struct Graph* createGraph(int capacity) {

  // allocate memory
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->edges = (Edge*)malloc(capacity * sizeof(Edge)); 
  graph->edgesSize = 0; 
  graph->capacity = edgesColSize; 

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