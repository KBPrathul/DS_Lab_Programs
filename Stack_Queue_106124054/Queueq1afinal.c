//q1a    Implementing Queue ADT using static array

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

void enqueue(struct queue* q, int x) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue %d\n", x);
        return;
    }
    if (q->front == -1){
        q->front = 0;
    }
    q->arr[++q->back] = x;
}

void dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return;
    }
    q->arr[q->front] = 0;
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

int main() {
    struct queue* q = createQueue(10);
    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    printf("Front is %d\n", front(q));
    printf("Size is %d\n", size(q));
    dequeue(q);
    printf("After dequeue front is %d\n", front(q));
    printf("Size is %d\n", size(q));
    dequeue(q);
    dequeue(q);
    return 0;
}

/*Front element is 5
Size is 3
After dequeue, front element is 10
Size is 2
*/
