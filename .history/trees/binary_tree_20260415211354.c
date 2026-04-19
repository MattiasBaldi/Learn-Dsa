#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

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
 void level_order_traversal(struct Node* node)
 {
    if (node == NULL) return; 

    // Example
    //         100
    //        /   \
    //      20     200
    //     /  \    /  \
    //    10  30  150  300
    
    // use a queue
    struct Node* Queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;  

    // start with root 
    Queue[rear++] = node; 

    // visit all children and add to queue
    while (front < rear)
    {
        if (rear >= MAX_QUEUE_SIZE) 
        {
            printf("Queue overflow, Allocate more memory up front!\n"); 
            return NULL; 
        }

        // dequeue
        struct Node* current = Queue[front++]; 

        printf("bfs %d ", current->data);

        // enqueue left node
        if (current->left)
            Queue[rear++] = current->left; 

        // enqueue right node
        if (current->right)
            Queue[rear++] = current->right; 
    }


 } 

// Search
// O(n) because it has to search, in the worst case the entire tree, that's why we use BST 
struct Node* find(struct Node* root, int key)
    {
        if (root == NULL)
            return NULL; 

        if (key == root->data)
            return root->data; 

        // Look in left subtree
        struct Node* leftResult = find(root->left, key); 
        if (leftResult != NULL)
            return leftResult; 

        // if not in left it must be in right
        return find(root->right, key); 
    }

// Insert
struct Node* insert(struct Node* root, int data)
 {
    if (root == NULL)
        return NULL; 
    
    // level order traversal 
    struct Node* Queue[MAX_QUEUE_SIZE]; 
    int front = 0, rear = 0;

    // enqueue the root init
    Queue[rear++] = root; 

    while (front < rear)
    {
        if (rear >= MAX_QUEUE_SIZE)
        {
            printf("Queue overflow, allocate more memory upfront\n"); 
            return NULL; 
        }

        // dequeue front as its now visited and make it a temp, also increment it at the same time
        struct Node* temp = Queue[front++]; 

        // enqueue left
        if (temp->left != NULL)
            Queue[rear++] = root->left; 
        else {
            // Found a gap! Insert here. 
            temp->left = createNode(data); 
            return root; // Insertion complete
        }
            
        // enqueue right
        if (temp->right != NULL)
            Queue[rear++] = root->right; 
        else {
            // Found a gap! Insert here. 
            temp->right = createNode(data);
            return root; // Insertion complete
        }
    }
    return root; 
 }

// Delete

/**
 * Deletion in a Binary Tree (Level-Order):
 * 1. Find the target node (to be deleted) using BFS.
 * 2. Find the deepest and rightmost node in the tree.
 * 3. Replace the target node's data with the deepest node's data.
 * 4. Delete the original deepest node to maintain a compact structure.
 * 
 * Example 1:
 *        10
 *       /  \
 *     11    9
 *    /
 *   7
 *  /
 * 6  <-- Deepest, rightmost node
 * 
 * Example 2:
 *          10
 *        /    \
 *      11      9
 *     /  \    /  \
 *    7   12  15   8  <-- Deepest, rightmost node
 * 
 * Time Complexity: O(n)
 * Auxiliary Space: O(n)
 */
struct Node* deleteNode(struct Node* root, int key) {

    if (root == NULL)
        return NULL; 


    // Binary tree example
    //       10         
  	//      /  \       
  	//    11    9
  	//   / \   / \     
  	//  7  12 15  8     

    // The idea is to traverse the tree in bfs manner (level order manner)
    // Step 1. Find the deepest and rightmost node in the binary tree and the node which we want to delete
    // Step 2. Replace the deepest rightmost node's data with the node to be deleted
    // Step 3. Delete the deepest rightmost noe

    // init
    struct Node *toDelete = NULL, *deepestRightmost = NULL;

    // bfs 
    struct Node* Queue[MAX_QUEUE_SIZE]; 
    int rear = 0, front = 0; 


    // Step 1. Find the deepest and rightmost node in the binary tree and the node which we want to delete

    // start with root 
    Queue[rear++] = root; 
    while ( front < rear )
    {
        if (rear >= MAX_QUEUE_SIZE)
        {
            printf("Queue overflow, allocate more memory\n");
            return; 
        }

        struct Node* temp = Queue[front++]; // dequeue and update front

        // found to delete
        if (temp->data == key) toDelete = temp; 

        // last element is always the deepest rightmost, so update it each iteration and on finish it must be the right one
        deepestRightmost = temp; 

        // enqueue left
        if (temp->left)
            Queue[rear++] = temp->left; 

        // enqueue right
        if (temp->right)
            Queue[rear++] = temp->right; 
    }

    // Step 2. Replace the deepest rightmost node's data with the node to be deleted
    toDelete->data = deepestRightmost->data; 

    // Step 3. Delete deepest rightmost
    struct Node* Queue[MAX_QUEUE_SIZE] = {0}; 
    front = 0, rear = 0; 
    while (front < rear)
    {

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

  // Search
  int found = find(firstNode, 3);  
  printf("found: %d", found); 

  // Test

  // Delete 

  // Insert

//   traversal("preorder", firstNode);
//   printf("\n"); 
//   bfs(firstNode); 

  return 0; 
 }