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
} Node;

typedef struct NodeLinked {

}

Node* newDynamicNode(int data) {
  Node* n = (Node*)malloc(sizeof(struct Node));
  n->children = malloc(sizeof(struct Node));  
  return n; 
}


Node* newLinkedNode(int data) {
  Node* n = (Node*)malloc(sizeof(struct Node));
  n->children = malloc(sizeof(struct Node));  
  return n; 
}

int main() {

  // initialize tree's

  return 0; 
}