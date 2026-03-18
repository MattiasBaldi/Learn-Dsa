#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

// Create a queue with a front, end and memory allocation (size)
typedef struct {
  int items[MAX_VERTICES]; 
  int front; 
  int rear; 
} Queue; 

/// Create a graph primitive with memory allocation (size), the adjacent matrix and adjacent size
typedef struct {
  int numVertices; 
  int* adjMatrix[MAX_VERTICES]; 
  int adjSize[MAX_VERTICES]; 
} Graph; 

/// Init queue
Queue* createQueue() {
  Queue* q = (Queue*)malloc(sizeof(Queue)); 
  q->front = 0; 
  q->rear = -1; 
  return q; 
}

// push
void enqueue(Queue* q, int value) {
  q->rear++; 
  q->items[q->rear] = value; 
}

// leftpop
int dequeue(Queue* q) {
  int value = q->items[q->front];
  q->front++; 
  return value; 
}

// test if queue is empty
int isQueueEmpty(Queue* q){
  return q->front > q->rear; 
}

// free up the memory for the entire queue
void freeQueue(Queue* q) {
  free(q); 
}

// create graph by allocating the size of the graph to memory
Graph* createGraph(int numVertices) {
  Graph* g = (Graph*)malloc(sizeof(Graph));
  g->numVertices = numVertices; // create a pointer that points numvertices to the given number of vertices from the input

  // iterate through num and point the adjMatrix to max vertices 
  for (int i = 0; i < numVertices; i++)
  {
      g->adjMatrix[i] = (int*)malloc(MAX_VERTICES * sizeof(int)); 
      g->adjSize[i] = 0;  // set adjsize to 0
  }
  return g; 
}

void addEdge(Graph* g, int src, int dest) {
  g->adjMatrix[src][g->adjSize[src]] = dest; // add edge by setting the adjMatrix to the destination
  g->adjSize[src]++;  // increment adjacent size
 
}

void freeGraph(Graph* g){
  // free the memory
  for (int i = 0; i < g->numVertices; i++)
  {
    free(g->adjMatrix[i]); 
  }
  free(g); 
}

/// DFS
void dfsHelper(Graph* g, int vertex, int visited[])
{
  visited[vertex] = 1; // assign  visit array 
  printf("%d ", vertex); 

  // Visit all adjacent vertices
  for (int i = 0; i < g->adjSize[vertex]; i++)
  {
    int adjVertex = g->adjMatrix[vertex][i]; 
    if (!visited[adjVertex]) // C treats numbers as bools where 0 = false, anything else = true
    {
      dfsHelper(g, adjVertex, visited); // recursion
    }
  }
}

void dfs(Graph* g, int startVertex) {
  int visited[MAX_VERTICES] = {0}; // initialize an array allocated 
  printf("DFS traversal starting from %d: ", startVertex); 
  dfsHelper(g, startVertex, visited); /// recursively run through each step and ensure it doesn't make any mistakes 
  printf("\n"); 
}

// Bfs
void bfs(Graph* g, int startVertex) {
  int visited[MAX_VERTICES] = {0}; // initialize an array empty array (0 on all indices)
  Queue* q = createQueue(); // initialize an empty queue

  visited[startVertex] = 1; // set first index to 1
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
  addEdge(g, 2, 3); 
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
  dfs(g, 0); 

  // Run BFS
  bfs(g, 0); 

  freeGraph(g); 

  return 0; 
}