//q4a    Simulating a Stack ADT using Queue ADT iteratively

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{
    int cap;
    int front;
    int back;
    int* arr;
};

struct queue* createqueue(int cap){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->cap=cap;
    q->front=-1;
    q->back=-1;
    q->arr=(int*)malloc(sizeof(int)*q->cap);
    return q;
}

bool isempty(struct queue* q){
    if(q->back==-1){return true;}
    return false;
}

bool isfull(struct queue* q){
    if(q->back==q->cap-1){return true;}
    return false;
}

int size(struct queue* q){
    if(q->back==q->front && q->front==-1){return 0;}
    return q->back-q->front+1;
}

void enqueue(struct queue* q, int x){
    if(!isfull(q)){
        if(q->front==-1){
            q->front=0;
        }
        q->arr[++q->back]=x;
    }
    else{
        printf("Queue overflow!\n");
    }
}

int dequeue(struct queue* q){
    if(!isempty(q)){
        if(q->front==q->back){
            int k=q->arr[q->front];
            q->front=-1;
            q->back=-1;
            return k;
        }
        else{
            return q->arr[q->front++];
        }
    }
    else{
        printf("Queue underflow!\n");
        return -1;
    }
}

void stackpush(struct queue* q,int x){
    struct queue* temp=createqueue(q->cap);
    while(size(q)){
        enqueue(temp,dequeue(q));
    }
    enqueue(q,x);
    while(size(temp)){
        enqueue(q,dequeue(temp));
    }
}

int main(){
    struct queue* q = createqueue(5);
    stackpush(q, 1);
    stackpush(q, 2);
    stackpush(q, 3);
    printf("Popped: %d\n", dequeue(q));
    printf("Popped: %d\n", dequeue(q));
    printf("Popped: %d\n", dequeue(q));
    return 0;
}

/*Popped: 3
Popped: 2
Popped: 1*/