#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * ============================================================================
 * EXERCISES: GRAPHS (BFS + DFS)
 * ============================================================================
 * Instructions:
 * 1. Implement the TODOs in each section.
 * 2. Compile and run: gcc exercises.c -o exercises && ./exercises
 * 3. Use the provided test_graph() to verify your implementations.
 * ============================================================================
 */

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int num_v;
    Node** adj_lists;
} Graph;

// Helper to create a graph
Graph* create_graph(int v) {
    Graph* g = malloc(sizeof(Graph));
    g->num_v = v;
    g->adj_lists = malloc(v * sizeof(Node*));
    for (int i = 0; i < v; i++) g->adj_lists[i] = NULL;
    return g;
}

// Helper to add a directed edge
void add_edge(Graph* g, int u, int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = g->adj_lists[u];
    g->adj_lists[u] = newNode;
}

/**
 * EXERCISE 1: RECURSIVE DFS
 * Objective: Print all reachable nodes starting from 'v' in Depth-First order.
 */
void dfs_recursive(Graph* g, int v, bool visited[]) 
{
    // TODO:
    // 1. Mark 'v' as visited.
    // 2. Print 'v'.
    // 3. For every neighbor of 'v', if not visited, recurse. 
    visited[v] = true; 
    printf(v);
    Node* temp = g->adj_lists[v]; 
    while (temp != NULL)
    {
        int neighbor = temp->vertex; 

        if (!visited[neighbor])
            dfs_recursive(g, neighbor, visited); 
            
        temp = temp->next; 
    }
}

/**
 * EXERCISE 2: BREADTH-FIRST SEARCH
 * Objective: Print all reachable nodes starting from 'start_v' in Breadth-First order.
 * Use a simple array-based queue or any queue implementation you prefer.
 */
void bfs(Graph* g, int start_v) {
    bool* visited = calloc(g->num_v, sizeof(bool));
    int* queue = malloc(g->num_v * sizeof(int));
    int front = 0, rear = 0;

    // TODO:
    // 1. Mark start_v as visited and enqueue it.
    visited[start_v] = true; 
    queue[rear++] = start_v; // enqueue

    while (front < rear) // while queue is not empty
    {
        int current_v = queue[front++]; // dequeue by incrementing front
        printf("%d", current_v);
            
        Node* temp = g->adj_lists[current_v]; 
        while (temp != NULL)
        {
            int neighbor = temp->vertex; // neighbors are the current vertex 
            if (!visited[neighbor])
            {
                visited[neighbor] = true; 
                queue[rear++] = neighbor; // check neighbors
            }
            temp = temp->next; // increment to check the next stuff
        }
    }

    // 2. While queue is not empty:
    //    a. Dequeue current_v and print it.
    //    b. For every neighbor of current_v:
    //       i. If neighbor is not visited, mark visited and enqueue.

    printf("\n");
    free(visited);
    free(queue);
}

/**
 * EXERCISE 3: PATH DETECTION
 * Objective: Return true if there is a path from 'src' to 'dest', false otherwise.
 * Hint: You can use either DFS or BFS.
 */
bool has_path(Graph* g, int src, int dest, bool visited[]) {
    // TODO:
    // 1. If src == dest, return true.
    // 2. Mark src as visited.
    // 3. For every neighbor of src:
    //    a. If neighbor is not visited:
    //       i. If has_path(neighbor, dest) is true, return true.
    // 4. Return false.
    return false;
}

/**
 * EXERCISE 4: SHORTEST PATH (UNWEIGHTED)
 * Objective: Find the minimum number of edges between 'src' and 'dest'.
 * Return -1 if no path exists.
 * Hint: BFS is ideal for shortest path in unweighted graphs.
 * Use a 'distance' array to keep track of steps from src.
 */
int shortest_path_distance(Graph* g, int src, int dest) {
    // TODO:
    // 1. Create a 'distance' array initialized to -1 (or some infinity).
    // 2. Create a queue and enqueue 'src'.
    // 3. distance[src] = 0.
    // 4. While queue is not empty:
    //    a. Dequeue current_v.
    //    b. If current_v == dest, return distance[current_v].
    //    c. For every neighbor:
    //       i. If distance[neighbor] == -1:
    //          - distance[neighbor] = distance[current_v] + 1
    //          - enqueue neighbor.
    return -1;
}

/**
 * EXERCISE 5: CYCLE DETECTION (DIRECTED GRAPH)
 * Objective: Return true if the graph contains a cycle, false otherwise.
 * Hint: Use DFS with a 'rec_stack' (recursion stack) array to track nodes 
 * in the current recursion path.
 */
bool is_cyclic_util(Graph* g, int v, bool visited[], bool rec_stack[]) {
    // TODO:
    // 1. Mark v as visited and add to rec_stack.
    // 2. For every neighbor:
    //    a. If neighbor is not visited:
    //       i. If is_cyclic_util(neighbor) is true, return true.
    //    b. Else if neighbor is in rec_stack, return true (Cycle found!).
    // 3. Remove v from rec_stack and return false.
    return false;
}

bool has_cycle(Graph* g) {
    bool* visited = calloc(g->num_v, sizeof(bool));
    bool* rec_stack = calloc(g->num_v, sizeof(bool));

    for (int i = 0; i < g->num_v; i++) {
        if (!visited[i]) {
            if (is_cyclic_util(g, i, visited, rec_stack)) {
                free(visited); free(rec_stack);
                return true;
            }
        }
    }
    free(visited); free(rec_stack);
    return false;
}

void run_tests() {
    Graph* g = create_graph(6);
    // 0 -> 1, 2
    // 1 -> 3
    // 2 -> 3, 4
    // 3 -> 5
    // 4 -> 5
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 5);
    add_edge(g, 4, 5);

    printf("--- Testing Traversals ---\n");
    bool* v = calloc(6, sizeof(bool));
    printf("DFS from 0: "); dfs_recursive(g, 0, v); printf("\n");
    free(v);

    printf("BFS from 0: "); bfs(g, 0);

    printf("\n--- Testing Path Detection ---\n");
    bool* v2 = calloc(6, sizeof(bool));
    printf("Path 0->5? %s\n", has_path(g, 0, 5, v2) ? "YES" : "NO");
    free(v2);
    bool* v3 = calloc(6, sizeof(bool));
    printf("Path 5->0? %s\n", has_path(g, 5, 0, v3) ? "YES" : "NO");
    free(v3);

    printf("\n--- Testing Shortest Path ---\n");
    printf("Shortest path 0->5: %d (Expected: 3)\n", shortest_path_distance(g, 0, 5));

    printf("\n--- Testing Cycle Detection ---\n");
    printf("Has cycle? %s\n", has_cycle(g) ? "YES" : "NO");

    printf("\nAdding edge 5->2 (Creates cycle 2->3->5->2)...\n");
    add_edge(g, 5, 2);
    printf("Has cycle now? %s\n", has_cycle(g) ? "YES" : "NO");
}

int main() {
    run_tests();
    return 0;
}
