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
  graph->capacity = capacity; 

  return graph; 
}; 

void addEdge(struct Graph *graph, int start, int end) {

  // double memory, allocate more memory if we reach capacity
  if (graph->edgesSize == graph->capacity)
  {
    graph->capacity *= 2; 
    graph->edges = (Edge*)realloc(
      graph->edges, 
      sizeof(Edge) * graph->capacity
    ); 
  }

  // add edge, update sizes
  graph->edges[graph->edgesSize].start = start; 
  graph->edges[graph->edgesSize].end = end; 
  graph->edgesSize++; 
}

void freeGraph(struct Graph *graph) {
  free(graph->edges); 
  free(graph); 
}

void printGraph(struct Graph *graph) {
  
  for (int i = 0; i < graph->edgesSize; i++)
  {
    printf("Start: %d ", graph->edges[i].start); 
    printf("End: %d ", graph->edges[i].start); 
    printf("\n")
  }
}

int main() {


  return 0;
}