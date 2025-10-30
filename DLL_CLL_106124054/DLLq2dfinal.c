//q2-b    Deleting element from DLL

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
	printf("Where to delete?");
	scanf("%d",&val);
	int size=1;
	while(temp1!=NULL && size<val){
		temp1=temp1->next;
		size++;
	}
	temp1->next=temp1->next->next;
	temp1->prev->next=temp1;
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
Where to delete?3
1 2 3 5
*/
