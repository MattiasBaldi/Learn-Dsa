#include <stdio.h>
#include <stdlib.h>

/*
  * https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/
*/

// Node
typedef struct Node {
  int data;
  struct Node* next; 
} Node; 


Node* newNode(int data)
{
  Node* n = (Node*)malloc(sizeof(struct Node));
  n->data = data; 
  n->next = NULL; 
  return n; 
}

int main() {
  Node* head = newNode(10); 

  head->next = newNode(20); 
  
  head->next->next = newNode(30); 

  head->next->next->next = newNode(40); 

  Node* temp = head; 
  while (temp != NULL)
  {
    printf("data: %d ", temp->data); 
    temp = temp->next; 
  }

  return 0; 
}