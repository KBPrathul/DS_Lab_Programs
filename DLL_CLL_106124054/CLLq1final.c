//CLL q1    Making 2 CLL from 1 CLL

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
	temp->next=head;
	temp=head;
	int size=0;
	do{
		temp=temp->next;
		size++;
	}while(temp!=head);
	struct node* head1=rec(temp->val);
	temp=temp->next;
	int size1=1;
	struct node* temp1=head1;
	while(size1<(size%2==0?size/2:(size/2)+1)){
		temp1->next=rec(temp->val);
		temp=temp->next;
		temp1=temp1->next;
		size1++;
	}
	temp1->next=head1;
	temp1=head1;
	do{
		printf("%d ",temp1->val);
		temp1=temp1->next;
	}while(temp1!=head1);
	printf("\n");
	struct node* head2=rec(temp->val);
	temp=temp->next;
	int size2=(size%2==0?(size/2)+1:(size/2)+2);
	struct node* temp2=head2;
	while(size2<size){
		temp2->next=rec(temp->val);
		temp=temp->next;
		temp2=temp2->next;
		size2++;
	}
	temp2->next=head2;
	temp2=head2;
	do{
		printf("%d ",temp2->val);
		temp2=temp2->next;
	}while(temp2!=head2);
}

/*How many elements do you want in the list? 3
Enter the value: 1
Enter the value: 2
Enter the value: 3
1 2 
3*/
