#include <stdio.h>
#include <stdlib.h>

/**
 * https://www.geeksforgeeks.org/dsa/graph-and-its-representations/
 * https://www.geeksforgeeks.org/c/c-program-to-implement-adjacency-list/
 */

 struct Node {
  int vertex; 
  struct Node* next; 
 } Node; 

 struct Graph {
  int vertices; 
  struct Node** adjLists; 
  int isDirected; 
 } Graph; 

 struct Node* createNode(int v )
 {
  struct Node* newNode = malloc(sizeof(struct Node)); 
  newNode->vertex = v;
  newNode->next = NULL; 
  return newNode; 
 }

 struct Graph* createGraph(int vertices, int isDirected)
 {
  struct Graph* graph = malloc(sizeof(struct Graph)); 
  graph->vertices = vertices; 
  graph->isDirected = isDirected; 

  // Create an array of adjacency lists
  graph->adjLists = malloc(vertices * sizeof(struct Node*)); 

  // Initialize each adjacency list as empty
  for (int i = 0; i < vertices; i++)
  {
    graph->adjLists[i] = NULL; 
  }
 }