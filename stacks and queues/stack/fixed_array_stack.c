#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

/*
    * https://www.geeksforgeeks.org/dsa/implement-stack-using-array/#:~:text=Full%20Implementation%20of,JavaScript
    * Fixed sized array stacks are rarely used. Often in embedded systems where memory constraints are important. 
*/

typedef struct Stack {
    int arr[MAX_SIZE]; 
    int top; 
} Stack; 

void initStack(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(const Stack *stack) {
    return stack->top == -1;
}

bool isFull(const Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) return;
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) return -1;
    return stack->arr[stack->top--];
}

int peek(const Stack *stack) {
    if (isEmpty(stack)) return -1;
    return stack->arr[stack->top];
}
