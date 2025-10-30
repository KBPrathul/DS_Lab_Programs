//q2b    Implementing Circular queue ADT using dynamic array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void expandqueue(struct queue* q) {
    int new_cap = q->cap * 2;
    int* new_arr = (int*)malloc(sizeof(int) * new_cap);
    int i = q->front;
    int j = 0;
    while (i != q->back) {
        new_arr[j++] = q->arr[i];
        i = (i + 1) % q->cap;
    }
    new_arr[j] = q->arr[i];
    free(q->arr);
    q->arr = new_arr;
    q->front = 0;
    q->back = j;
    q->cap = new_cap;
    printf("Queue expanded to capacity %d\n", new_cap);
}

void enqueue(struct queue* q, int x) {
    if (isfull(q)) {
        expandqueue(q);
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
    if (q->front == q->back) {
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
    printf("Queue (size=%d, cap=%d): ",(q->back >= q->front)?(q->back - q->front + 1):(q->cap - q->front + q->back + 1),q->cap);
    int i = q->front;
    while (true) {
        printf("%d ", q->arr[i]);
        if (i == q->back) break;
        i = (i + 1) % q->cap;
    }
    printf("\n");
}

int main() {
    struct queue* q = createqueue(3);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    enqueue(q, 40);
    display(q);
    return 0;
}

/*Queue (size=3, cap=3): 10 20 30 
Queue expanded to capacity 6
Queue (size=4, cap=6): 10 20 30 40*/