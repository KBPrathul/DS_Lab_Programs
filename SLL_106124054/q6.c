//q6   Detecting a loop in LL

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
	struct node* temp2=head->next->next;
	temp->next=temp2;
	temp=head;
	struct node* slow=head;
	struct node* fast=head;
	do{
        if(fast==NULL||fast->next==NULL){
            printf("No cycle detected\n");
            return 0;
        }
        slow=slow->next;
        fast=fast->next->next;
        }while(slow!=fast);
	fast=head;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
	}
	printf("The value at the link is %d\n",slow->val);
}

/*How many elements do you want in the list? 5
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
The value at the link is 3
*/
