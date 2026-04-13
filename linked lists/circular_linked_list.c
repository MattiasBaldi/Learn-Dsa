#include <stdio.h>
#include <stdlib.h>

/*
  * https://www.geeksforgeeks.org/dsa/circular-linked-list/
  The next pointer of the last node points back to the first node and this results in forming a circle

  Circular Singly Linked List:
  In circular doubly linked list, each node has two pointers prev and next, 
  similar to doubly linked list. 
  The prev pointer points to the previous node 
  and the next points to the next node. 

  Here, in addition to the last node storing the address of the first node, 
  the first node will also store the address of the last node.

  Circular Doubly Linked List:
  In circular doubly linked list, each node has two pointers prev and next, 
  similar to doubly linked list. The prev pointer points to the previous node 
  and the next points to the next node. Here, in addition to the last node storing the address of the first node, 
  the first node will also store the address of the last node.
  */

  typedef struct Singly_Node {
      int data; 
      struct Singly_Node* next; 
  } Singly_Node; 

  Singly_Node* newSinglyNode(int data) {
    Singly_Node* n = (Singly_Node*)malloc(sizeof(struct Singly_Node)); 
    n->next = NULL; 
    n->data = data; 
    return n; 
  }

  typedef struct Doubly_Node {
      int data; 
      struct Doubly_Node* next;
      struct Doubly_Node* prev; // Fixed: capitalized 'N' to match struct name
  } Doubly_Node; 

  Doubly_Node* newDoublyNode(int data) {
    Doubly_Node* n = (Doubly_Node*)malloc(sizeof(struct Doubly_Node)); 
    n->next = NULL;
    n->prev = NULL; 
    n->data = data; 
    return n; 
  }
  
  int main() {
    
    // Singly Circular
    Singly_Node* head_singly = newSinglyNode(5); 
    head_singly->next = newSinglyNode(10); 
    head_singly->next->next = newSinglyNode(15); 
    head_singly->next->next->next = newSinglyNode(20);

    // link tail to head
    head_singly->next->next->next->next = head_singly; 

    // Go one round
    Singly_Node* temp_singly = head_singly; 
    do 
    {
        printf("Singly Circular: %d\n", temp_singly->data);
        temp_singly = temp_singly->next; 
    } while (temp_singly != head_singly); // Fixed: compare pointers instead of data

    // Doubly Circular
    Doubly_Node* head_doubly = newDoublyNode(5); 
    head_doubly->next = newDoublyNode(10); 
    head_doubly->next->prev = head_doubly; // Fixed: added missing link back to head

    head_doubly->next->next = newDoublyNode(15); 
    head_doubly->next->next->prev = head_doubly->next;  

    head_doubly->next->next->next = newDoublyNode(20); 
    head_doubly->next->next->next->prev = head_doubly->next->next; 

    // Link tail and head together
    head_doubly->next->next->next->next = head_doubly; 
    head_doubly->prev = head_doubly->next->next->next; 

    // Go one round
    Doubly_Node* temp_doubly = head_doubly;
    Doubly_Node* tail = NULL;  
    do 
    {
      printf("Doubly Circular Forward: %d\n", temp_doubly->data);
      if (temp_doubly->next == head_doubly) tail = temp_doubly; // Fixed: tail is current node, not prev
      temp_doubly = temp_doubly->next;

    } while (temp_doubly != head_doubly); 

    temp_doubly = tail; 
    do 
    {
      printf("Doubly Circular Backwards: %d\n", temp_doubly->data);
      temp_doubly = temp_doubly->prev;
    } while (temp_doubly != tail); // Fixed: loop until we return to the tail

    return 0; 
  }
