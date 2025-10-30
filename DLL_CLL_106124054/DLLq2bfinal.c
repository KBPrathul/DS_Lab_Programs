//q2-b    Insert element in DLL

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
	int value1;
	printf("Enter the value: ");
	scanf("%d",&value1);
	struct node* head1=rec(value1);
	struct node* temp1=head1;
	for(int i=1;i<n;i++){
		printf("Enter the value: ");
		scanf("%d",&value1);
		temp1->next=rec(value1);
		temp1->next->prev=temp1;
		temp1=temp1->next;
	}
	temp1=head1;
	int val;
	printf("What is the value?");
	scanf("%d",&val);
	int pos;
	printf("Where to insert?");
	scanf("%d",&pos);
	int size=1;
	while(temp1!=NULL && size<pos){
		temp1=temp1->next;
		size++;
	}
	struct node* newnode=rec(val);
	newnode->next=temp1->next;
	newnode->prev=temp1;
	temp1->next=newnode;
	newnode->next->prev=newnode;
	temp1=head1;
	while(temp1!=NULL){
		printf("%d ",temp1->val);
		temp1=temp1->next;
	}
	printf("\n");
	
}

/*How many elements do you want in the list? 5
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
What is the value?6
Where to insert?3
1 2 3 6 4 5
*/
