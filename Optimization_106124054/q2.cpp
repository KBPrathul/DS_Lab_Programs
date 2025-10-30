//q2    Reordering LL

#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node* next;
    node(int v){
        val=v;
        next=nullptr;
    }
};

int main(){
    int n;
    cout<<"How many elements in the CLL: ";
    cin>>n;
    int x;
    cout<<"Enter the value: ";
    cin>>x;
    struct node* head= new node(x);
    struct node* temp=head;
    for(int i=1;i<n;i++){
        cout<<"Enter the value: ";
        cin>>x;
        temp->next = new node(x);
        temp=temp->next;
    }
    temp->next=head;
    temp=head;
    struct node* head2;
    struct node* temp2=head;
    for(int i=0;i<n/2-1;i++){
        temp2=temp2->next;
    }
    temp=temp2->next;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=nullptr;
    head2=temp2->next;
    temp2->next=nullptr;
    temp=head2;
    temp2=head;
    struct node* prev=nullptr;
    struct node* next=nullptr;
    while(temp!=nullptr){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head2=prev;
    temp=head;
    temp2=head2;
    while(temp!=nullptr && temp2!=nullptr){
        struct node* next2=temp2->next;
        struct node* next1=temp->next;
        temp2->next=temp;
        temp->next=next2;
        temp=next1;
        temp2=next2;
    }
    temp=head2;
    while(temp!=nullptr){
        cout<<temp->val;
        temp=temp->next;
    }
    temp->next=head2;
}

/*How many elements in the CLL: 6
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
Enter the value: 6
615243*/