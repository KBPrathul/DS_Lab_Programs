//q1c    Stack ADT with LL

#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* newnode(int val) {
    struct node* s = (struct node*)malloc(sizeof(struct node));
    s->val = val;
    s->next = NULL;
    return s;
}

int isEmpty(struct node* head) {
    return (head == NULL);
}

void push(struct node** head, int x) {
    struct node* new = newnode(x);
    new->next = *head;
    *head = new;
}

void pop(struct node** head) {
    if (isEmpty(*head)) {
        printf("Stack underflow\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    struct node* head = NULL;
    
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    pop(&head);

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}


/*3 2 1 
2 1 */
