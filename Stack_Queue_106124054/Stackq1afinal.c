//q1a    Stack ADT with static array

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int capacity;
    int* arr;
};

struct stack* createstack(int cap){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = cap;
    s->top = -1;
    s->arr = (int*)malloc(s->capacity * sizeof(int));
    return s;
}

int isFull(struct stack* s){
    return (s->top == s->capacity-1);
}

int isEmpty(struct stack* s){
    return (s->top == -1);
}

int size(struct stack* s){
    return s->top + 1;
}

void push(struct stack* s, int x){
    if(!isFull(s)){
        s->arr[++s->top] = x;
    }
    else {
        printf("Stack Overflow\n");
    }
}

int pop(struct stack* s){
    if(!isEmpty(s)){
        return s->arr[s->top--];
    }
    printf("Stack Underflow\n");
    return -1;
}

int peek(struct stack* s){
    if(!isEmpty(s)){
        return s->arr[s->top];
    }
    printf("Stack is empty\n");
    return -1;
}

int main(){
    struct stack* s=createstack(10);
    if(!isFull(s)){push(s,5);}
    printf("The top value is %d\n",peek(s));
    printf("The size is %d\n",size(s));
    if(!isEmpty(s)){pop(s);}
    printf("%d",peek(s));
    return 0;
}

/*The top value is 5
The size is 1
Stack is empty
-1*/
