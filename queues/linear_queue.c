#include <stdio.h>
#include <stdlib.h>

/**
 * https://www.geeksforgeeks.org/dsa/array-implementation-of-queue-simple/
 * 
 * 
 * The linear queue is used as a learning example and shouldn't be implemented in production, thereby the name "naive",
 * The main reason being, that memory is wasted and dequeuing is expensive, 
 * as it requires shifting all elements leftwards on just one dequeue operation.
 * 
 * Instead of ending the queue we can take advantage of circular buffers, that means we, wrap around the queue in a loop,
 * and just change the front index, that way we don't have to shift all elements leftwards. See circular_queue.c for the example.
 */

struct naiveQueue {
    int *arr; 
    int capacity; 
    int size; 
}; 

struct naiveQueue* createQueue(int capacity) {
  struct naiveQueue* q = (struct naiveQueue*)malloc(sizeof(struct naiveQueue)); 
  if (q == NULL) return NULL;

  q->capacity = capacity; 
  q->size = 0; 

  // Array to store queue elements; 
  q->arr = (int*)malloc(capacity * sizeof(int)); 
  return q; 
}

int isEmpty(struct naiveQueue* q) {
  return q->size == 0; 
}

int isFull(struct naiveQueue* q) {
  return q->size == q->capacity; 
}

// First in
// O(1)
void enqueue(struct naiveQueue* q, int value)
{
  if (isFull(q)) 
  {
    printf("Queue Overflow"); 
    return; 
  }

  q->arr[q->size++] = value;  
}

// First out
// O(n)
void dequeue(struct naiveQueue* q)
{
  if (isEmpty(q))
  {
    printf("Queue Underflow"); 
    return; 
  }

  // This is O(n), because the q doesn't wrap around
  for (int i = 1; i < q->size; i++)
  {
    q->arr[i-1] = q->arr[i]; 
  }

  q->size--; 
}

int getFront(struct naiveQueue* q) {
  if (isEmpty(q))
  {
    printf("Queue is empty"); 
    return 0; 
  }

  return q->arr[0]; 
}

int getRear(struct naiveQueue* q)
{
  if (isEmpty(q)) 
  {
    printf("Queue is empty"); 
    return 0; 
  }

  return q->arr[q->size -1]; 
}

int main() {
  struct naiveQueue* q = createQueue(3); 

  enqueue(q, 10); 
  enqueue(q, 20); 
  enqueue(q, 30); 
  printf("Front %d\n", getFront(q)); 

  dequeue(q); 
  printf("Front %d\n", getFront(q)); 
  printf("Rear %d\n", getRear(q)); 

  enqueue(q, 40); 
  printf("Rear %d\n", getRear(q)); 

  return 0; 


}