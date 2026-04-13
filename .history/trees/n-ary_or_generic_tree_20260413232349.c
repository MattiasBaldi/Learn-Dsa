#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * Tree of any amount of subnode, but still follows hierarchy and has no cycles, AKA not a graph.
 * https://www.geeksforgeeks.org/dsa/introduction-to-tree-data-structure/
 */

typedef struct Node {
 int data; 
 struct Node* children[];
 int size; 
 int capacity;   
} Node; 

Node* newNode(int data) {
  Node* n = (Node*)malloc(sizeof(struct Node));
  n->children = malloc(sizeof(struct Node));  
  return n; 
}

int main() {

  // initialize tree's

  return 0; 
}