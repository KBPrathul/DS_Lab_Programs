//DLL q4    Reversing a DLL

#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* prev;
	int val;
	struct node* next;
};

struct node* rec(int n){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->val=n;
	new->prev=NULL;
	new->next=NULL;
	return new;
}

int main(){
	int n;
	printf("How many elements do you want in the list? ");
	scanf("%d", &n);
	int value;
	printf("Enter the value: ");
	scanf("%d",&value);
	struct node* head=rec(value);
	struct node* temp=head;
	for(int i=1;i<n;i++){
		printf("Enter the value: ");
		scanf("%d",&value);
		temp->next=rec(value);
		temp->next->prev=temp;
		temp=temp->next;
	}
	struct node* ptr=head;
	while(ptr!=temp){
		int t=ptr->val;
		ptr->val=temp->val;
		temp->val=t;
		ptr=ptr->next;
		temp=temp->prev;
	}
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->val);
		temp=temp->next;
	}
	printf("\n");
}

/*How many elements do you want in the list? 5
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
5 4 3 2 1*/
