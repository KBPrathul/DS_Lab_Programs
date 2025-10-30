//q3    Sort the given nums in a stack

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

void realpush(struct stack* s, int x){
    struct stack* temp=createstack(s->capacity);
    while(size(s) && peek(s)>x){
        push(temp,peek(s));
        pop(s);
    }
    push(s,x);
    while(size(temp)){
        push(s,peek(temp));
        pop(temp);
    }
}

int main(){
    struct stack* s=createstack(5);
    realpush(s,5);
    realpush(s,1);
    realpush(s,3);
    realpush(s,2);
    printf("The elements are:\n");
    while(size(s)){
        printf("%d ",peek(s));
        pop(s);
    }
}

/*The elements are:
5 3 2 1*/
