//q1b    Implementing Queue ADT using dynamic array

#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int back;
    int capacity;
    int* arr;
};

struct queue* createQueue(int cap) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = cap;
    q->front = -1;
    q->back = -1;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

int isFull(struct queue* q) {
    return (q->back == q->capacity - 1);
}

int isEmpty(struct queue* q) {
    return (q->back == -1);
}

int size(struct queue* q) {
    if (isEmpty(q)) return 0;
    return q->back - q->front + 1;
}

void resizeQueue(struct queue* q) {
    q->capacity = q->capacity * 2;
    q->arr = (int*)realloc(q->arr, (q->capacity) * sizeof(int));    
    printf("Queue resized to %d\n", q->capacity);
}

void enqueue(struct queue* q, int x) {
    if (isFull(q)) {
        resizeQueue(q);
    }
    if (q->front == -1){
        q->front = 0;
    }
    q->arr[++q->back] = x;
}

void dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return;
    }
    q->front++;
    if (q->front > q->back) {
        q->front = -1;
        q->back = -1;
    }
}

int front(struct queue* q) {
    if (!isEmpty(q))
        return q->arr[q->front];
    return -1;
}

void freeQueue(struct queue* q) {
    free(q->arr);
    free(q);
}

int main() {
    struct queue* q = createQueue(2);
    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    printf("Front element is %d\n", front(q));
    printf("Size is %d\n", size(q));
    printf("Capacity is %d\n", q->capacity);
    dequeue(q);
    printf("Front element is %d\n", front(q));
    printf("Size is %d\n", size(q));
    return 0;
}

/*Queue resized to 4
Front element is 5
Size is 3
Capacity is 4
Front element is 10
Size is 2*/