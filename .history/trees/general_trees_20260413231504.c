/**
 * 
 * Tree of any amount of subnode, but still follows hierarchy and has no cycles, AKA not a graph.
 * https://www.geeksforgeeks.org/dsa/introduction-to-tree-data-structure/
 */

struct Node {
 int data; 
 struct Node* children;  
} Node; 