#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Graph structure (Adjacency List)
 */
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int num_v;
    Node** adj_lists;
} Graph;

Graph* create_graph(int v) {
    Graph* g = malloc(sizeof(Graph));
    g->num_v = v;
    g->adj_lists = malloc(v * sizeof(Node*));
    for (int i = 0; i < v; i++) g->adj_lists[i] = NULL;
    return g;
}

void add_edge(Graph* g, int u, int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adj_lists[u];
    g->adj_lists[u] = newNode;
}

/**
 * ============================================================================
 * QUEUE FOR BFS
 * ============================================================================
 */
typedef struct {
    int* items;
    int front;
    int rear;
    int size;
} Queue;

Queue* create_queue(int size) {
    Queue* q = malloc(sizeof(Queue));
    q->items = malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

bool is_empty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->size - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item;
    if (is_empty(q)) return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

/**
 * ============================================================================
 * BFS (BREADTH-FIRST SEARCH)
 * ============================================================================
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) for queue and visited array
 */
void bfs(Graph* g, int start_v) {
    bool* visited = calloc(g->num_v, sizeof(bool));
    Queue* q = create_queue(g->num_v);

    visited[start_v] = true;
    enqueue(q, start_v);

    printf("BFS Traversal: ");
    while (!is_empty(q)) {
        int current_v = dequeue(q);
        printf("%d ", current_v);

        Node* temp = g->adj_lists[current_v];
        while (temp) {
            int adj_v = temp->vertex;
            if (!visited[adj_v]) {
                visited[adj_v] = true;
                enqueue(q, adj_v);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(q->items);
    free(q);
}

int main() {
    Graph* g = create_graph(4);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 0);
    add_edge(g, 2, 3);
    add_edge(g, 3, 3);

    bfs(g, 2);

    return 0;
}
