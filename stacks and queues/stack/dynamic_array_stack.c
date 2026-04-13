#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
  * https://www.geeksforgeeks.org/dsa/implement-stack-using-array/#:~:text=Stack%20Implementation%20using%20Dynamic%20Array
  * Dynamic sized array stacks are the most common, because they are simple and work out of the box.
  * You allocate more memory dynamically so they can grow or shrink as you'd like, without much extra work.
*/


typedef struct Stack {
  int *arr; 
  int top; 
  int capacity; 
} Stack;

Stack *createStack(int initialCapacity)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack)); 
  stack->arr = (int *)malloc(initialCapacity * sizeof(int)); 
  stack->top = -1;
  stack->capacity = initialCapacity; 
  return stack;  
}


void push(Stack* stack, int value)
{
  // Resize array if needed
  if (stack->top + 1 >= stack->capacity)
  {
    stack->capacity *= 2; 
    stack->arr = (int *)realloc(stack->arr, stack->capacity * sizeof(int)); 
  }
  
  stack->arr[++stack->top] = value; 
}

int pop(Stack* stack)
{
  if (stack->top == -1)
  {
    printf("Stack Underflow\n"); 
    return -1; 
  }

  return stack->arr[stack->top--]; 
}

int peek(const Stack* stack) {
  if (stack->top == -1)
  {
    printf("Stack is Empty\n"); 
    return -1; 
  }
  return stack->arr[stack->top]; 
}

bool isEmpty(const Stack* stack)
{
  return stack->top == -1; 
}

int size(const Stack* stack)
{
  return stack->top + 1; 
}

void freeStack(Stack * stack)
{
  free(stack->arr); 
  free(stack); 
}
