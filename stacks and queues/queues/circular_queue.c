#include <stdio.h>
#include <stdlib.h>

/*
* https://www.geeksforgeeks.org/dsa/introduction-to-circular-queue/
*
*
*
*/

struct circular_queue {
  int *arr; 
  int front; 
  int size; 
  int capacity; 
};

struct circular_queue* createQueue(int capacity) {

  struct circular_queue* q = (struct circular_queue*)malloc(sizeof(struct circular_queue)); 

  if (q == NULL) return NULL; 
  q->capacity = capacity; 
  q->size = 0;
  q->front = 0; // needs to be specified

  q->arr = (int*)malloc(capacity * sizeof(int)); 
  return q; 
};

int isFull(struct circular_queue* q) {
  return q->size == q->capacity; 
}

int isEmpty(struct circular_queue* q) {
    return q->size == 0; 
}

void enqueue(struct circular_queue* q, int value)
{
  if (isFull(q))
  {
    printf("Queue overflow"); 
    return; 
  }
  int rear = (q->front + q->size) % q->capacity; 
  q->arr[rear] = value;
  q->size++;  
}

void dequeue(struct circular_queue* q)
{
  if (isEmpty(q))
  {
    printf("Queue underflow"); 
    return; 
  }
  q->front = (q->front + 1) % q->capacity; 
  q->size--; 
}

int getFront(struct circular_queue* q) {
  if (isEmpty(q)) return -1; 
  return q->arr[q->front]; 
}

int getRear(struct circular_queue* q) {
  if (isEmpty(q)) return -1;
  int rear = (q->front + q->size - 1) % q->capacity;
  return q->arr[rear];
}

int main() {
   struct circular_queue* q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Front: %d, Rear: %d\n", getFront(q), getRear(q)); 
    dequeue(q); 
    printf("Front: %d, Rear: %d\n", getFront(q), getRear(q)); 
    enqueue(q, 40); 
    printf("Front: %d, Rear: %d\n", getFront(q), getRear(q)); 
    return 0;
}