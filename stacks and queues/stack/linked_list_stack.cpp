#include <iostream>
#include <cstddef> // For NULL

/*
  * https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/
  *
  * Linked-list stacks are rarely used in modern production compared to
  * array-based implementations and are mainly used for educational purposes
  * and specific niche/system-level cases.
  * 
  * When you need a stack built on individually allocated nodes with stable memory addresses and no reliance on contiguous storage or resizing.
  * 
  * Historically, they were more attractive when dynamic memory management
  * and resizing arrays were more expensive or less efficient. Today, array-based
  * stacks dominate due to better cache performance and lower memory overhead.
*/

class Node {
  public: 
    int data; 
    Node* next; 

    Node(int x) {
      data = x; 
      next = NULL;
    }
}; 

class Stack {
  Node* top; 

  public: 
    Stack() {
      // initially its empty
      top = NULL; 
    }

    // Time Complexity: O(1)
    // Auxiliary Space: O(1)

    void push(int x) {
      Node* temp = new Node(x);
      temp->next = top; 
      top = temp;  
    }

    int pop() {
      if (top == NULL)
      {
        std::cout << "Stack Underflow" << std::endl; 
        return -1; 
      }

      Node* temp = top; 
      top = top->next; 
      int val = temp->data; 

      delete temp; 
      return val; 
    }

    int peek() {
      if (top == NULL)
      {
        std::cout << "Stack is Empty" << std::endl;
        return -1;  
      }
      
      return top->data; 
    }

    bool isEmpty() {
      return top == NULL; 
    }
}; 
