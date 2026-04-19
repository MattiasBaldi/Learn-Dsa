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

  if (key > root->data)
    return find(root->right, key); 

 }
   
 // DFS Traversal
 void traversal(char* type, struct Node* root)
 {

  // Example
  //         100
  //        /   \
  //      20     200
  //     /  \    /  \
  //    10  30  150  300
  
  // Inorder Traversal (N, L, R); 
  // Inorder Traversal: 10 20 30 100 150 200 300
  // At first traverse left subtree then visit the root and then traverse the right subtree.

  /**
   * The inorder traversal of the BST gives the values of the nodes in sorted order. 
   * To get the decreasing order visit the right, root, and left subtree.
  */
  
  if (strcmp(type, "inorder") == 0)
  {
    if (root == NULL)
      return;

    // Traverse left subtree
    traversal(type, root->left); 
  
    // Visit node
    printf("inorder: %d \n", root->data); 

    // Traverse right subtree
    traversal(type, root->right); 

  }


  // Preorder Traversal: 100 20 10 30 200 150 300
  // Depth first Traversal
  if (strcmp(type, "preorder") == 0)
  {

    if (root == NULL) return; 

    // traverse left
    traversal(type, root->left); 

    printf("%d", root->data); 
    
    // traverse right
    traversal(type, root->right); 

  }
  
  // Postorder Traversal: 10 30 20 150 300 200 100
  // Breadth first traversal, from low to high
  if (strcmp(type, "postorder") == 0)
  {

      // traverse left subtree
      traversal(type, root->left); 

      // then traverse right
      traversal(type, root->right); 

      // then visit root
      printf("%d", root->data); 
  }

 }

/** 
  Deletion
  @see https://www.geeksforgeeks.org/dsa/deletion-in-binary-search-tree/
  The deletion process in BST depends on the number of children of the node.
  No children means simply remove the node.
  One child means remove the node and connect its parent to the node’s only child.
  Two children means replace the node with its inorder successor/predecessor and delete that node. 
 */

// Delete
//  void delete(struct Node* root, int key)
//  {

//   if (root == NULL)
//     return;

//   // Find it first
//   if (key > root->data)
//     return delete(root->left, key); 

//   if (key < root->data)
//     return delete(root->right, key); 

//   // Then do deletion
//   else {

//     // Node with 0 or 1 child
//     if (root->left == NULL)
//     {
//       struct Node* temp = root->right; 
//       free(root); 
//       return temp; 
//     }

//     if (root->right == NULL)
//     {
//       struct Node* temp = root->left; 
//       free(root); 
//       return temp; 
//     }
    
//   }

//   // Node with 2 children
//   // struct Node* succ = getSuccessor(root); 
//   // root->data = succ->data; 
//   // root->right = delete(root->right, succ->data); 
 
  
// }
 

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
  printf("Found: %d\n", found->data);  


  traversal("inorder", root); 

  // // Delete
  // delete(root, 7); 

  // // Try find again 
  // found = find(root, 7);
  // printf("Found: %d\n", found->data);

}