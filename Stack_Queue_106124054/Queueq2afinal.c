//q2a    Implementing Circular queue ADT using static array

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue {
    int cap;
    int front;
    int back;
    int* arr;
};

struct queue* createqueue(int cap) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->cap = cap;
    q->front = -1;
    q->back = -1;
    q->arr = (int*)malloc(sizeof(int) * cap);
    return q;
}

bool isempty(struct queue* q) {
    return (q->front == -1);
}

bool isfull(struct queue* q) {
    return ((q->back + 1) % q->cap == q->front);
}

void enqueue(struct queue* q, int x) {
    if (isfull(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (isempty(q)) {
        q->front = q->back = 0;
    } else {
        q->back = (q->back + 1) % q->cap;
    }
    q->arr[q->back] = x;
}

int dequeue(struct queue* q) {
    if (isempty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    
    int val = q->arr[q->front];
    
    if ((q->front)%(q->cap) == (q->back)%(q->cap)) {
        q->front = q->back = -1;
    } else {
        q->front = (q->front + 1) % q->cap;
    }
    
    return val;
}

int peek(struct queue* q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(struct queue* q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    do {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->cap;
    } while (i != (q->back + 1) % q->cap);
    printf("\n");
}

int main() {
    struct queue* q = createqueue(3);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    enqueue(q, 40);
    display(q);
    return 0;
}

/*Queue: 10 20 30 
Dequeued: 10
Queue: 20 30 
Queue: 20 30 40*/