//q1b    Stack ADT with dynamic array

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int capacity;
    int* arr;
};

struct stack* createStack(int cap) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = cap;
    s->top = -1;
    s->arr = (int*)malloc(s->capacity * sizeof(int));
    return s;
}

int isFull(struct stack* s) {
    return (s->top == s->capacity - 1);
}

int isEmpty(struct stack* s) {
    return (s->top == -1);
}

int size(struct stack* s) {
    return s->top + 1;
}

void resize(struct stack* s) {
    s->capacity = s->capacity * 2;
    s->arr = (int*)realloc(s->arr, (s->capacity) * sizeof(int));
    printf("Stack resized to capacity %d\n", s->capacity);
}

void push(struct stack* s, int x) {
    if (isFull(s)) {
        resize(s);
    }
    s->arr[++s->top] = x;
}

int pop(struct stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    printf("Stack Underflow\n");
    return -1;
}

int peek(struct stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    printf("Stack is empty\n");
    return -1;
}

int main() {
    struct stack* s = createStack(2);
    
    push(s, 5);
    push(s, 10);
    push(s, 15);
    
    printf("The top value is %d\n", peek(s));
    printf("The size is %d\n", size(s));
    printf("The capacity is %d\n", s->capacity);
    
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    
    printf("%d\n", peek(s));
    return 0;
}

/*Stack resized to capacity 4
The top value is 15
The size is 3
The capacity is 4
Popped: 15
Popped: 10
Popped: 5
Stack is empty
-1*/