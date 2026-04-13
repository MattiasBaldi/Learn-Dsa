#include <stdio.h>
#include <stdlib.h>

/*
  * https://www.geeksforgeeks.org/dsa/queue-linked-list-implementation/
*/

// Node structure
typedef struct Node {
  int data; 
  struct Node* next;
} Node; 


typedef struct linked_list_queue {
  int currSize; 
  Node* front; 
  Node* rear; 
} linked_list_queue; 

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node)); 
  node->data = data; 
  node->next = NULL; 
  return node; 
}

linked_list_queue* createQueue() {
  linked_list_queue* q = (linked_list_queue*)malloc(sizeof(linked_list_queue)); 
  q->front = q->rear = NULL; 
  q->currSize = 0; 
  return q; 
}
// Linked list queues are dynamic so they cannot be full, only empty or not empty
int isEmpty(linked_list_queue* q)
{
  return q->front == NULL;
}

void enqueue(linked_list_queue* q, int data)
{
  Node* node = newNode(data); 
  if (isEmpty(q))
  {
    q->front = q->rear = node; 
  }
  else {
    q->rear->next = node; 
    q->rear = node;
  }

  q->currSize++; 
}

int dequeue(linked_list_queue* q) {
  if (isEmpty(q))
  {
    printf("Queue Underflow\n"); 
    return -1;
  }

  Node* temp = q->front; 
  int removedData = temp->data;
  q->front = q->front->next; 
  if (q->front == NULL) q->rear = NULL; 
  free(temp); 

  q->currSize--; 
  return removedData; 
}

int getFront(linked_list_queue* q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n"); 
    return -1; 
  }

  return q->front->data;
}

int size(linked_list_queue* q)
{
  return q->currSize; 
}

int main() {
  linked_list_queue* q = createQueue(); 

  enqueue(q, 10); 
  enqueue(q, 20);
  
  printf("Dequeue: %d\n", dequeue(q)); 

  enqueue(q, 30); 

  printf("Front: %d\n", getFront(q)); 
  printf("Size: %d\n", size(q)); 

  return 0; 
}




