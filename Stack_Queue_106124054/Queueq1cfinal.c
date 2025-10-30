//q1c    Implementing Queue ADT with LL

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* back;
    int cap;
    int size;
};

struct node* createnode(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct queue* createqueue(int cap) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->back = NULL;
    q->cap = cap;
    q->size = 0;
    return q;
}

bool isEmpty(struct queue* q) {
    return q->size == 0;
}

bool isfull(struct queue* q) {
    return q->size == q->cap;
}

void enqueue(struct queue* q, int x) {
    if (isfull(q)) {
        printf("Queue overflow\n");
        return;
    }
    struct node* new_node = createnode(x);
    if (isEmpty(q)) {
        q->front = q->back = new_node;
    } else {
        q->back->next = new_node;
        q->back = new_node;
    }
    q->size++;
}

int dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    struct node* temp = q->front;
    int val = temp->val;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (isEmpty(q)) {
        q->back=NULL;
        q->front=NULL;
    }
    return val;
}

void printQueue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct queue* q = createqueue(3);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Queue: ");
    printQueue(q);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue after dequeue: ");
    printQueue(q);
    return 0;
}

/*Queue: 10 20 30 
Dequeued: 10
Queue after dequeue: 20 30*/
