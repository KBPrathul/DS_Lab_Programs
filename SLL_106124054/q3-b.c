//q3-b    Reversing LL recursively

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* create_node(int n) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = n;
    new_node->next = NULL;
    return new_node;
}

struct node* reverse_list(struct node* head,struct node* prev, struct node* curr, struct node* next) {
	if(curr==NULL){return prev;}
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        reverse_list(head,prev,curr,next);
}

int main() {
    int n, value;
    printf("How many elements do you want in the list? ");
    scanf("%d", &n);
    printf("Enter the value: ");
    scanf("%d", &value);
    struct node* head = create_node(value);
    struct node* temp = head;

    for (int i = 1; i < n; i++) {
        printf("Enter the value: ");
        scanf("%d", &value);
        temp->next = create_node(value);
        temp = temp->next;
    }
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    head = reverse_list(head,prev,curr,next);
    temp = head;
    printf("Reversed list: ");
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}

/*How many elements do you want in the list? 5
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
Reversed list: 5 4 3 2 1*/
