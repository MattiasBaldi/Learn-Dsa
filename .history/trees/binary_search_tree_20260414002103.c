#include <stdio.h>
#include <stdlib.h>

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
  struct Node* left; 
  struct Node* right; 
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
      return NULL; // or maybe return unfound?
    }


  if (key == root->data)
    return root; 

  if (key > root->data)
    root->left = find(root->left, key); 

  if (key > root->data)
    root->right = find(root->right, key); 

 }

// Delete
//  struct Node* find(struct Node* root, int key)
//  {
//   if (root == NULL)
//     return newNode(key);

//   if (key == root->data)
//     return root; 

//   if (key > root->data)
//     root->left = find(root->left, key); 

//   if (key > root->data)
//     root->right = find(root->right, key); 

//  }

int main() {

}