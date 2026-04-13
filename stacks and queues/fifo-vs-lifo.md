## FIFO vs LIFO (Core Data Structure Behaviors)

### FIFO (Queue)
- Meaning: First In, First Out
- Behavior: Oldest element is removed first
- Operations:
  - enqueue → add to back
  - dequeue → remove from front

Example:
A → B → C  
Removal order: A, B, C


---

### LIFO (Stack)
- Meaning: Last In, First Out
- Behavior: Newest element is removed first
- Operations:
  - push → add to top
  - pop → remove from top

Example:
A → B → C  
Removal order: C, B, A


---

## Key Idea
- FIFO = queue behavior (oldest first out)
- LIFO = stack behavior (newest first out)


---

## Other related concepts

### Priority Queue
- Elements are removed based on priority, not insertion order
- Not FIFO or LIFO

### Deque (Double-ended queue)
- Insert/remove from both ends
- Can behave like FIFO or LIFO depending on usage