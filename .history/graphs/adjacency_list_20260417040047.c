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
 }