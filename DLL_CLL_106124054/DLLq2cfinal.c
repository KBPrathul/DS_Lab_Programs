//q1-a    Inserting node in CLL

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
	int val;
	printf("Enter the value: ");
	scanf("%d",&val);
	temp->next=rec(val);
	temp->next->next=head;
	temp=head;
	do{
		printf("%d ",temp->val);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}

/*How many elements do you want in the list? 5
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
Enter the value: 7
1 2 3 4 5 7 */
