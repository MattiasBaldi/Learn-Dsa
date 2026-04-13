#include <stdio.h>
#include <stdlib.h>

/**
 * Binary trees are non linear and hierarchial data structure where each node
 * has at most two children, referred to as the left child and the right child.
 * https://www.geeksforgeeks.org/dsa/introduction-to-binary-tree/
 */

 struct Node {
  int data; 
  struct Node *left; 
  struct Node *right; 
 }; 

 struct Node* createNode(int d)
 {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
  
  newNode->data = d; 
  newNode->left = NULL; 
  newNode->right = NULL; 
  return newNode; 
 }

 void dfs(struct Node* node) {
  if (node == NULL) return; 

  printf("dfs: %d ", node->data); 

  dfs(node->left); 
  dfs(node->right); 
 }


 void bfs(struct Node* node)
 {
  if (node == NULL) return; 

  int visited[10] = {}; 
  int Queue[10] = {0}; 
  int front = 0, rear = 0; 
  
  // enqueue

  // dequeue
 }

 int main() 
 {
  struct Node* firstNode = createNode(2); 
  struct Node* secondNode = createNode(3); 
  struct Node* thirdNode = createNode(4); 
  struct Node* fourthNode = createNode(5); 

  // Connect nodes
  firstNode->left = secondNode; 
  firstNode->right = thirdNode; 
  secondNode->left = fourthNode; 

  dfs(firstNode); 

  return 0; 
 }