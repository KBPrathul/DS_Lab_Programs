//q1-b    Inserting element in LL

#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};

struct node* rec(int n){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->val=n;
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
		temp=temp->next;
	}
	temp=head;
	int target;
	printf("Which node value do you want to insert at? ");
	scanf("%d",&target);
	int insertval;
	printf("What value do you want to insert?");
	scanf("%d",&insertval);
	while(temp->val!=target){
		temp=temp->next;
	}
	struct node* temp2=temp->next;
	temp->next=rec(insertval);
	temp->next->next=temp2;
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
Which node value do you want to insert at? 3
What value do you want to insert?6
1 2 3 6 4 5*/
