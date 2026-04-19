#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// /**
//  * 
//  * Tree of any amount of subnode, but still follows hierarchy and has no cycles, AKA not a graph.
//  * https://www.geeksforgeeks.org/dsa/introduction-to-tree-data-structure/
//  */

// uses a dynamic array
typedef struct NodeDynamic {
 int data; 
 struct NodeDynamic **children; //pointer to pointer -> a dynamic array of children 
 int childCount; 
} NodeDynamic;

// uses clever link encoding (not a linked list)
typedef struct NodeLinked {
  int data; 
  struct NodeLinked *firstChild; 
  struct NodeLinked *nextSibling; 
} NodeLinked; 

NodeDynamic* newDynamicNode(int data, int childCount) {
  NodeDynamic* n = (NodeDynamic*)malloc(sizeof(struct NodeDynamic));
  n->data = data; 
  n->childCount = childCount;

  if (childCount > 0) 
    n->children = malloc(sizeof(NodeDynamic*) * childCount);
  else 
    n->children = NULL;

  return n; 
}

NodeLinked* newLinkedNode(int data) {
  NodeLinked* n = (NodeLinked*)malloc(sizeof(struct NodeLinked));
  n->data = data; 
  n->firstChild = NULL; 
  n->nextSibling = NULL; 
  return n; 
}

void dfs(char* type, struct NodeDynamic *dNode, struct NodeLinked *lNode) 
{

  if(strcmp(type, "dynamic") == 0)
  {
    if (dNode == NULL)
      return; 

      printf("dynamic: %d\n", dNode->data); 

      for (int i = 0; i < dNode->childCount; i++)
      {
        dfs("dynamic", dNode->children[i], NULL); 
      }
  }

  else if(strcmp(type, "linked") == 0)
  {
      if (lNode == NULL)
        return; 

      printf("linked: %d\n", lNode->data); 

      dfs("linked", NULL, lNode->firstChild);
      dfs("linked", NULL, lNode->nextSibling); 

  }

  return;
}

void bfs(char* type, struct NodeDynamic *dNode, struct NodeLinked *lNode) {


  if (strcmp(type, "dynamic") == 0)
  {

  }

  if (strcmp(type, "linked") == 0)
  {
    
  }

  

}

int main() {

  // Dynamic
  NodeDynamic *root_dynamic = newDynamicNode(1, 3);

  // TODO -> create tree
  NodeDynamic *first = root_dynamic->children[0] = newDynamicNode(1, 2); 
  NodeDynamic *second = root_dynamic->children[1] = newDynamicNode(4, 2); 
  NodeDynamic *third = root_dynamic->children[2] = newDynamicNode(2, 2); 

  NodeDynamic *first_first = first->children[0] = newDynamicNode(2, 2); 
  NodeDynamic *second_first = second->children[0] = newDynamicNode(2, 2); 
  NodeDynamic *second_second = second->children[1] = newDynamicNode(2, 2); 

  dfs("dynamic", root_dynamic, NULL); 

  // Linked
  NodeLinked *root_linked = newLinkedNode(1);
  // TODO -> create tree
  NodeLinked *childOne = root_linked->firstChild = newLinkedNode(1); 
  NodeLinked *childTwo = childOne->nextSibling = newLinkedNode(2); 
  NodeLinked *childThree = childTwo->nextSibling = newLinkedNode(3); 
  NodeLinked *childFour = childThree->nextSibling = newLinkedNode(4); 

  NodeLinked *childOne_One = childOne->firstChild = newLinkedNode(1); 
  NodeLinked *childOne_Two = childOne_One->nextSibling = newLinkedNode(1); 

  NodeLinked *childTwo_One = childTwo->firstChild = newLinkedNode(1); 
  NodeLinked *childTwo_Two = childTwo_One->nextSibling = newLinkedNode(1); 

  dfs("linked", NULL, root_linked); 

  return 0; 
}