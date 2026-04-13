#include <stdio.h>
#include <stdlib.h>

/*
  * https://www.geeksforgeeks.org/dsa/doubly-linked-list/
*/

typedef struct Node {
  int data; 
  struct Node* prev; 
  struct Node* next; 
} Node; 

Node* newNode(int data) {
  Node* n = (Node*)malloc(sizeof(struct Node));
  n->data = data; 
  n->prev = NULL; 
  n->next = NULL;
  return n; 
}

int main() {
  
  // Create link
  Node* head = newNode(5); 

  // Create next
  head->next = newNode(10);
  head->next->prev = head; // link back

  // Create next
  head->next->next = newNode(15); 
  head->next->next->prev = head->next;   // link back

  // Create next
  head->next->next->next = newNode(20); 
  head->next->next->next->prev = head->next->next;   // link back

  // Find the tail and log each on the way
  Node* temp = head;
  Node* tail = NULL;  

  // Traverse forward
  while (temp != NULL)
  {
    printf("Forward: %d\n", temp->data); 
    if (temp->next == NULL) tail = temp; 
    temp = temp->next;    
  }
  
  temp = tail; 
  // Traverse reversely  
  while (temp != NULL)
  {
    printf("Backwards: %d\n", temp->data); 
    temp = temp->prev; 
  }

  return 0; 

}
