#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

 // Insert

 // Search

 // Delete

 // Traversal ( DFS Traversal - 3 Types of DFS)
 void traversal(char* type, struct Node* root)
 {
  if (root == NULL)
    return;

  // Example
  //         100
  //        /   \
  //      20     200
  //     /  \    /  \
  //    10  30  150  300
  
  // Inorder Traversal (L, N, R); 
  // Inorder Traversal: 10 20 30 100 150 200 300
  // At first traverse left subtree then visit the root and then traverse the right subtree.

  /**
   * The inorder traversal of the BST gives the values of the nodes in sorted order. 
   * To get the decreasing order visit the right, root, and left subtree.
  */
  
  if (strcmp(type, "inorder") == 0)
  {
    // Traverse left subtree
    traversal(type, root->left); 
    
    // Visit node
    printf("inorder: %d \n", root->data); 

    // Traverse right subtree
    traversal(type, root->right); 

  }

  // Preorder Traversal (N, L, R); 
  // Preorder Traversal: 100 20 10 30 200 150 300

  if (strcmp(type, "preorder") == 0)
  {
    // visit node
    printf("%d\n", root->data); 

    // traverse left
    traversal(type, root->left); 
    
    // traverse right
    traversal(type, root->right); 

  }
  
  // Postorder Traversal (L, R, N); 
  // Postorder Traversal: 10 30 20 150 300 200 100
  if (strcmp(type, "postorder") == 0)
  {
      // traverse left subtree
      traversal(type, root->left); 

      // then traverse right
      traversal(type, root->right); 

      // then visit node
      printf("%d\n", root->data); 
  }

 }


 // Traversal ( BFS Traversal - 1 Types of BFS)

 void bfs(struct Node* node)
    {
    if (node == NULL) return;

    struct Node* Queue[10];
    int front = 0, rear = 0;

    // start with root
    Queue[rear++] = node;

    while (front < rear)
    {
        struct Node* current = Queue[front++];

        printf("bfs: %d ", current->data);

        if (current->left != NULL)
            Queue[rear++] = current->left;

        if (current->right != NULL)
            Queue[rear++] = current->right;
    }
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

  traversal("preorder", firstNode);
  printf("\n"); 
  bfs(firstNode); 

  return 0; 
 }