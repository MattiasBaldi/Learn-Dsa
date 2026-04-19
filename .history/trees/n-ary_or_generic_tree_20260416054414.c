#include <stdio.h>
#include <stdlib.h>

// /**
//  * 
//  * Tree of any amount of subnode, but still follows hierarchy and has no cycles, AKA not a graph.
//  * https://www.geeksforgeeks.org/dsa/introduction-to-tree-data-structure/
//  */


// uses a dynamic array
typedef struct NodeDynamic {
 int data; 
 struct Node **children; //pointer to pointer -> a dynamic array of children 
 int childCount; 
} NodeDynamic;


// uses clever link encoding (not a linked list)
typedef struct NodeLinked {
  int data; 
  struct NodeLinked *firstChild; 
  struct NodeLinked *nextSibling; 
} NodeLinked; 

NodeDynamic* newDynamicNode(int data, int childCount) {
  NodeDynamic* n = (NodeDynamic*)malloc(sizeof(struct NodeDynamic));
  n->children = malloc(sizeof(struct NodeDynamic) * childCount);  
  return n; 
}


NodeLinked* newLinkedNode(int data) {
  NodeLinked* n = (NodeLinked*)malloc(sizeof(struct NodeLinked));
  n->data = data; 
  n->firstChild = NULL; 
  n->nextSibling = NULL; 
  return n; 
}

int main() {

  // initialize tree's

  return 0; 
}