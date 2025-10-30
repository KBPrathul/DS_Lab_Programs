//q2-a    Traversal and size of DLL & CLL

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
	int size1=0;
	while(temp1!=NULL){
		printf("%d ",temp1->val);
		temp1=temp1->next;
		size1++;
	}
	
	printf("%d\n",size1);
	printf("\n");
	int m;
	printf("How many elements do you want in the list? ");
	scanf("%d", &m);
	int value;
	printf("Enter the value: ");
	scanf("%d",&value);
	struct node* head=rec(value);
	struct node* temp=head;
	for(int i=1;i<m;i++){
		printf("Enter the value: ");
		scanf("%d",&value);
		temp->next=rec(value);
		temp=temp->next;
	}
	temp->next=head;
	temp=head;
	int size=0;
	do{
		printf("%d ",temp->val);
		temp=temp->next;
		size++;
	}while(temp!=head);
	printf("\n");
	printf("%d\n",size);
}

/*How many elements do you want in the list? 5
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
1 2 3 4 5 5

How many elements do you want in the list? 4
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
1 2 3 4 
4
*/
