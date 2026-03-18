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

void enqueue(Queue* q, int value) {
  q->rear++; 
  q->items[q->rear] = value; 
}

int dequeue(Queue* q) {
  int value = q->items[q->front];
  q->front++; 
  return value; 
}

int isQueueEmpty(Queue* q){
  return q->front > q->rear; 
}

void freeQueue(Queue* q) {
  free(q); 
}

Graph* createGraph(int numVertices) {
  Graph* g = (Graph*)malloc(sizeof(Graph));
  g->numVertices = numVertices; 

  for (int i = 0; i < numVertices; i++)
  {
      g->adjMatrix[i] = (int*)malloc(MAX_VERTICES * sizeof(int)); 
      g->adjSize[i] = 0; 
  }
  return g; 
}

void addEdge(Graph* g, int src, int dest) {
  g->adjMatrix[src][g->adjSize[src]] = dest; 
  g->adjSize[src]++; 
}

void freeGraph(Graph* g){
  for (int i = 0; i < g->numVertices; i++)
  {
    free(g->adjMatrix); 
  }
  free(g); 
}

/// DFS
void dfsHelper(Graph* g, int vertex, int visited[])
{
  visited[vertex] = 1; 
  printf("%d ", vertex); 

  // Visit all adjacent vertices
  for (int i = 0; i < g->adjSize[vertex]; i++)
  {
    int adjVertex = g->adjMatrix[vertex][i]; 
    if (!visited[adjVertex]) {
      dfsHelper(g, adjVertex, visited); 
    }
  }
}

void dfs(Graph* g, int startVertex) {
  int visited[MAX_VERTICES] = {0}; 
  printf("DFS traversal starting from %d: ", startVertex); 
  dfsHelper(g, startVertex, visited); 
  printf("\n"); 
}

// Bfs
void bfs(Graph* g, int startVertex) {
  int visited[MAX_VERTICES] = {0}; 
  Queue* q = createQueue(); 

  visited[startVertex] = 1; 
  enqueue(q, startVertex); 

  printf("BFS traversal starting from vertex %d: ", startVertex); 

  while (!isQueueEmpty(q)) {
    int vertex = dequeue(q); 
    printf("%d ", vertex); 


    // visit all adjacent vertices
    for (int i = 0; i < g->adjSize[vertex]; i++) 
    {
      int adjVertex = g->adjMatrix[vertex][i]; 
        if (!visited[adjVertex]) {
          visited[adjVertex] = 1; 
          enqueue(q, adjVertex); 
        }
    }
  }

  printf("\n"); 

  freeQueue(q); 
}

// Main
  
int main() {
  // Create a graph with 6 vertices
  Graph* g = createGraph(6); 

  // add edges
  addEdge(g, 0, 1); 
  addEdge(g, 0, 2); 
  addEdge(g, 1, 3); 
  addEdge(g, 2, 1); 
  addEdge(g, 2, 4); 
  addEdge(g, 3, 5);
  addEdge(g, 4, 5); 

  printf("Graph structure:\n");
  printf("0 -> 1, 2\n");
  printf("1 -> 3\n");
  printf("2 -> 3, 4\n");
  printf("3 -> 5\n");
  printf("4 -> 5\n");
  printf("5 -> (no outgoing edges)\n\n");

  // Run DFS 
  dfs(q, 0); 

  // Run BFS
  bfs(g, 0); 

  freeGraph(g); 

  return 0; 
}