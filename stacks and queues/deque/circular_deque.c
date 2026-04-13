#include <stdio.h>
#include <stdlib.h>

struct myDeque {
    int *arr;
    int front, size, capacity;
};

// Constructor to initialize the deque
struct myDeque* create_deque(int c) {
    struct myDeque* dq = (struct myDeque*)malloc(sizeof(struct myDeque));
    dq->arr = (int*)malloc(c * sizeof(int));
    dq->capacity = c;
    dq->size = 0;
    dq->front = 0;
    return dq;
}

// Delete element from the front
int deleteFront(struct myDeque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    int res = dq->arr[dq->front];
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    return res;
}

// Insert element at the front
void insertFront(struct myDeque* dq, int x) {
    if (dq->size == dq->capacity) {
        printf("Deque is full\n");
        return;
    }

    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->arr[dq->front] = x;
    dq->size++;
}

// Insert element at the rear
void insertRear(struct myDeque* dq, int x) {
    if (dq->size == dq->capacity) {
        printf("Deque is full\n");
        return;
    }
    int rear = (dq->front + dq->size) % dq->capacity;
    dq->arr[rear] = x;
    dq->size++;
}

// Delete element from the rear
int deleteRear(struct myDeque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    int rear = (dq->front + dq->size - 1) % dq->capacity;
    int res = dq->arr[rear];
    dq->size--;
    return res;
}

// Get the front element
int frontEle(struct myDeque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get the rear element
int rearEle(struct myDeque* dq) {
    if (dq->size == 0) {
        printf("Deque is empty\n");
        return -1;
    }
    int rear = (dq->front + dq->size - 1) % dq->capacity;
    return dq->arr[rear];
}

int main() {
    struct myDeque* dq = create_deque(4);

    insertRear(dq, 10);
    insertFront(dq, 20);
    insertRear(dq, 30);

    printf("Front: %d, Rear: %d\n", frontEle(dq), rearEle(dq));

    deleteFront(dq);
    printf("Front: %d, Rear: %d\n", frontEle(dq), rearEle(dq));

    deleteRear(dq);
    printf("Front: %d, Rear: %d\n", frontEle(dq), rearEle(dq));

    return 0;
}