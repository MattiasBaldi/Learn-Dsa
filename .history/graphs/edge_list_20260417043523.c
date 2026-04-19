#include <stdio.h>
#include <stdlib.h>

/**
 * Array of pairs
 * 
 */

 struct Graph {
  int** edges;
  int edgesSize; 
  int edgesColSize;  
 } Graph; 

int** createGraph() {

  // allocate memory
  struct *Graph graph = (Graph*)malloc(sizeof(Graph)); 

  graph->edges = 
  graph->edgesSize = 0; 
  graph->edgesColSize = 0; 

}; 

void createEdge() {

}

void printGraph() {

}

int main() {


  return 0;
}