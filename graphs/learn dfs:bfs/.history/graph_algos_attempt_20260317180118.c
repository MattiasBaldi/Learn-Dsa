#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100


typedef struct {
  int items[MAX_VERTICES]; 
  int front; 
  int rear; 
} Queue; 

typedef struct {
  int numVertices; 
  int* adjMatrix[MAX_VERTICES]; 
  int adjSize[MAX_VERTICES]; 
} Graph; 

Queue* createQueue() {
  Queue* q = (Queue*)malloc(sizeof(Queue)); 
  q->front = 0; 
  q->rear = -1; 
  return q; 
}

