#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * https://www.geeksforgeeks.org/dsa/introduction-to-binary-tree/
 * A binary search tree is a special type of binary tree, where
 * each node is greater than every node in it's left subtree. 
 * This makes it easy to do recursive binary search, not the same type arrays use,
 * Similiar concept, but implementation is different for binary search trees.
 * @see https://www.youtube.com/watch?v=mtvbVLK5xDQ
 
  Advantages of Binary Search Tree (BST):
  Efficient searching: O(log n) time complexity for searching with a self balancing BST
  Ordered structure: Elements are stored in sorted order, making it easy to find the next or previous element
  Dynamic insertion and deletion: Elements can be added or removed efficiently
  Balanced structure: Balanced BSTs maintain a logarithmic height, ensuring efficient operations
  Doubly Ended Priority Queue: In BSTs, we can maintain both maximum and minimum efficiently
  
  Not self-balancing: Unbalanced BSTs can lead to poor performance
  Worst-case time complexity: In the worst case, BSTs can have a linear time complexity for searching and insertion
  Memory overhead: BSTs require additional memory to store pointers to child nodes
  Not suitable for large datasets: BSTs can become inefficient for very large datasets
  Limited functionality: BSTs only support searching, insertion, and deletion operations
 */

 typedef struct Node
 {
  int data; 
  struct Node *left; 
  struct Node *right; 
 } Node; 

 struct Node* newNode(int data)
 {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
  node->data = data; 
  node->left = node->right = NULL; 
  return node; 
 }

 // Insert
 struct Node* insert(struct Node* root, int key)
 {

  // if its empty 
  if (root == NULL)
    return newNode(key);
    
  // if the key is less than the root data recursive left
  if (key < root->data)
    root->left = insert(root->left, key); 

  // if the key is larger than the root data recursive right
  else if (key > root->data)
    root->right = insert(root->right, key); 

  return root; 
 }

 // Find
 struct Node* find(struct Node* root, int key)
 {
  if (root == NULL)
  {
    printf("key not in tree\n"); 
    return NULL;
  }

  if (key == root->data)
    return root; 
  
  if (key < root->data)
    return find(root->left, key); 

  return find(root->right, key); 
 }
   
 // Traversal (Using dfs)
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
    struct Node* Queue[10];
    int front, rear = 0;  

    // start with root 
    Queue[rear++] = node; 

    // visit all children and add to queue
    while (front < rear)
    {

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



 // use Inorder traversal to get the successor
 struct Node* getSuccessor(struct Node* curr)
 {
    // Inorder (L, N, R)
    curr = curr->right; 
    while (curr != NULL && curr->left != NULL)
      curr = curr->left; 

    return curr; 
 }

/** 
  Deletion
  @see https://www.geeksforgeeks.org/dsa/deletion-in-binary-search-tree/
 */

// Delete
struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with 0 or 1 child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with 2 children: Get the inorder successor
        struct Node* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}


int main() {
  
  // Creating BST
  //    6
  //   / \
  //  2   8
  //     / \
  //    7   9
  
  // Insert
  struct Node* root = newNode(6); 
  insert(root, 2);
  insert(root, 8);
  insert(root, 7);
  insert(root, 9);

  // Find
  struct Node* found = find(root, 7); 
  if (found != NULL) printf("Found: %d\n", found->data);  

  // Traversal
  printf("Postorder:\n");
  traversal("postorder", root); 

  // Delete
  printf("\nDeleting 7...\n");
  root = deleteNode(root, 7); 

  // Try find again 
  found = find(root, 7);
  if (found != NULL) {
    printf("Found: %d\n", found->data);
  } else {
    printf("7 was successfully deleted.\n");
  }

  return 0;
}