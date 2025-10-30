//q2c    Implementing Circular queue ADT using LL

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int val;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* back;
    int cap;
    int size;
};

struct node* createnode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->val=val;
    temp->next=NULL;
    return temp;
}

struct queue* createqueue(int cap){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->back=NULL;
    q->front=NULL;
    q->cap=cap;
    q->size=0;
    int size=0;
    struct node* head=createnode(0);
    q->back=head;
    q->front=head;
    size++;
    while(size<q->cap){
        q->back->next=createnode(0);
        q->back=q->back->next;
        size++;
    }
    q->back->next=q->front;
    q->back=q->front;
    return q;
}

bool isempty(struct queue* q){
    return q->size==0;
}

bool isfull(struct queue* q){
    return q->size==q->cap;
}

int peek(struct queue* q){
    if(isempty(q)){
        printf("Queue is empty");
        return -1;
    }
    return q->front->val;
}

void enqueue(struct queue* q, int val){
    if(isfull(q)){
        printf("Queue overflow");
    }
    else{
        q->back->val=val;
        q->back=q->back->next;
        q->size++;
    }
}

int dequeue(struct queue* q){
    if(isempty(q)){
        printf("Queue underflow");
        return -1;
    }
    else{
        int k=q->front->val;
        q->front->val=0;
        q->front=q->front->next;
        q->size--;
        return k;
    }
}

int main(){
    struct queue* q=createqueue(3);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    printf("Dequeued:%d\n",dequeue(q));
    enqueue(q,4);
    struct node* temp=q->front;
    int count=0;
    while(count<q->size){
        printf("%d ",temp->val);
        temp=temp->next;
        count++;
    }
}

/*Dequeued:1
2 3 4*/