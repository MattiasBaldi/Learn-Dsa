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
 struct NodeDynamic **children; //pointer to pointer -> a dynamic array of children 
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
  n->childCount = childCount;

  if (childCount > 0) 
    n->children = malloc(sizeof(NodeDynamic*) * childCount);
  else 
    n->children = NULL;

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

  NodeDynamic *root_dynamic = newDynamicNode(1, 3); 
  // TODO -> create tree
  NodeDynamic *first = root_dynamic->children[0] = newDynamicNode(1, 2); 
  NodeDynamic *second = root_dynamic->children[1] = newDynamicNode(4, 2); 
  NodeDynamic *third = root_dynamic->children[2] = newDynamicNode(2, 2); 

  NodeDynamic *first_first = first->children[0] = newDynamicNode(2, 2); 
  NodeDynamic *second_first = second->children[0] = newDynamicNode(2, 2); 
  NodeDynamic *second_second = second->children[1] = newDynamicNode(2, 2); 

  NodeLinked *root_linked = newLinkedNode(1);
  // TODO -> create tree
  NodeLinked *childOne = root_linked->firstChild = newLinkedNode(1); 
  NodeLinked *childTwo = childOne->nextSibling = newLinkedNode(2); 
  NodeLinked *childThree = childTwo->nextSibling = newLinkedNode(3); 
  NodeLinked *childFour = childThree->nextSibling = newLinkedNode(4); 

  return 0; 
}