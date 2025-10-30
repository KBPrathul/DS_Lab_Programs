//q3b    Simulate a queue using stack ADT recursively

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
    int cap;
    int top;
    int* arr;
};

struct stack* createstack(int cap){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->cap=cap;
    s->top=-1;
    s->arr=(int*)malloc(sizeof(int)*(s->cap));
    return s;
}

bool isfull(struct stack* s){
    if(s->top==s->cap-1){return true;}
    return false;
}

bool isempty(struct stack* s){
    if(s->top==-1){return true;}
    return false;
}

void push(struct stack* s, int x){
    if(!isfull(s)){
        s->arr[++s->top]=x;
    }
    else{
        printf("Stack overflow!");
    }
}

int pop(struct stack* s){
    if(isempty(s)){
        printf("Stack underflow!");
        return -1;
    }
    else{
        return s->arr[s->top--];
    }
}

int peek(struct stack* s){
    return s->arr[s->top];
}

int size(struct stack* s){
    return s->top+1;
}

void rec(struct stack*s, struct stack* temp){
    if(size(s)){
        push(temp,peek(s));
        pop(s);
        rec(s,temp);
    }
    else{return;}
}

void queuepush(struct stack* s, int x){
    struct stack* temp=createstack(s->cap);
    if(!isfull(s)){
        rec(s,temp);
        push(s,x);
        rec(temp,s);
    }
    else{
        printf("Stack overflow!");
    }
}

int main(){
    struct stack* s = createstack(5);
    queuepush(s, 1);
    queuepush(s, 2);
    queuepush(s, 3);
    
    printf("The popped element is %d\n", pop(s));
    printf("The popped element is %d\n", pop(s));

    return 0;
}

/*The popped element is 1
The popped element is 2*/