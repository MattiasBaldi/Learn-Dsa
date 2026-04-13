#include <stdio.h>
#include <stdlib.h>

/*
  Doubly linked list
  * https://www.geeksforgeeks.org/dsa/implementation-deque-using-doubly-linked-list/
*/

// Node
typedef struct Node {
  int data; 
  struct Node* prev; 
  struct Node* next; 
} Node; 

typedef struct linked_list_deque {
  int currSize; 
  struct Node* front; 
  struct Node* rear;
} linked_list_deque; 

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node)); 
  node->data = data;
  node->prev = NULL;  
  node->next = NULL;
  return node; 
}

linked_list_deque* create_deque() {
  linked_list_deque* q = (linked_list_deque*)malloc(sizeof(linked_list_deque)); 
  q->front = NULL;
  q->rear = NULL; 
  q->currSize = 0; 
  return q; 
}

int isEmpty(linked_list_deque* q) {
  return q->front == NULL; 
}

int getSize(linked_list_deque* q) { 
  return q->currSize; 
}

void insertFront(linked_list_deque* q, int value) 
{
  Node* new_node = newNode(value); 
  if (isEmpty(q))
  {
    q->front = q->rear = new_node; 
  }
  else {
    new_node->next = q->front; 
    q->front->prev = new_node;
    q->front = new_node; 
  }
  q->currSize++; 
}

void insertRear(linked_list_deque* q, int value)
{
  Node* new_node = newNode(value); 
  if (isEmpty(q))
  {
    q->front = q->rear = new_node; 
  }
  else {
    new_node->prev = q->rear; 
    q->rear->next = new_node; 
    q->rear = new_node;
  }
  q->currSize++; 
}

void deleteFront(linked_list_deque* q) 
{
  if (isEmpty(q))
  {
    printf("UnderFlow\n"); 
    return; 
  }

  Node* temp = q->front;
  q->front = q->front->next; 
  
  if (q->front == NULL) {
    q->rear = NULL;
  } else {
    q->front->prev = NULL;
  }
  
  free(temp); 
  q->currSize--;
}

void deleteRear(linked_list_deque* q) 
{
  if (isEmpty(q))
  {
    printf("UnderFlow\n"); 
    return; 
  }

  Node* temp = q->rear;
  q->rear = q->rear->prev;  
  
  if (q->rear == NULL) {
    q->front = NULL;
  } else {
    q->rear->next = NULL;
  }
  
  free(temp);
  q->currSize--;
}

int getFront(linked_list_deque* q)
{
  if (isEmpty(q))
  {
    return -1; 
  }
  return q->front->data; 
}

int getRear(linked_list_deque* q)
{
  if (isEmpty(q))
  {
    return -1; 
  }
  return q->rear->data;
}

void erase(linked_list_deque* q)
{
  while (!isEmpty(q)) deleteFront(q); 
}

int main() {
  linked_list_deque* q = create_deque(); 
  
  insertRear(q, 5); 
  insertRear(q, 10);
  printf("Rear: %d\n", getRear(q)); 
  
  deleteRear(q); 
  printf("New Rear: %d\n", getRear(q)); 

  insertFront(q, 15); 
  printf("Front: %d\n", getFront(q)); 
  printf("Size: %d\n", getSize(q)); 

  deleteFront(q); 
  printf("New Front: %d\n", getFront(q)); 

  return 0; 
}