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
  n->data = data; 
  n->childCount = 0;
  n->children = (NodeDynamic*)malloc(sizeof(struct NodeDynamic)); 
  return n; 
}

NodeLinked* newLinkedNode(int data) {
  NodeLinked* n = (NodeLinked*)malloc(sizeof(struct NodeLinked) * childCount);
  n->data = data; 
  n->firstChild = NULL; 
  n->nextSibling = NULL; 
  return n; 
}

int main() {

  NodeDynamic *root_dynamic = newNodeDynamic(1, 3); 

  // TODO -> create tree
  root_dynamic->children = malloc(root_dynamic->childCount* sizeof(NodeDynamic*)); 
  root_dynamic->children[0] = newNodeDynamic(2); 
  root_dynamic->children[1] = newNodeDynamic(2); 
  root_dynamic->children[2] = newNodeDynamic(2); 
  
  NodeLinked *root_linked = newNodeLinked(1); 
  // TODO -> create tree

  return 0; 
}