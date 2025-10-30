#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* rec(int n) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = n;
    new_node->next = NULL;
    return new_node;
}

int main() {
    int n, m;
    int value;
    printf("How many elements? ");
    scanf("%d", &n);
    printf("Enter the value: ");
    scanf("%d", &value);
    struct node* head1 = rec(value);
    struct node* temp1 = head1;
    for (int i = 1; i < n; i++) {
        printf("Enter the value: ");
        scanf("%d", &value);
        temp1->next = rec(value);
        temp1 = temp1->next;
    }
    temp1->next = head1;
    printf("How many elements? ");
    scanf("%d", &m);
    printf("Enter the value: ");
    scanf("%d", &value);
    struct node* head2 = rec(value);
    struct node* temp2 = head2;
    for (int i = 1; i < m; i++) {
        printf("Enter the value: ");
        scanf("%d", &value);
        temp2->next = rec(value);
        temp2 = temp2->next;
    }
    temp2->next = head2;
    struct node* head = NULL;
    struct node* temp = NULL;
    struct node* curr1 = head1;
    struct node* curr2 = head2;
    int done1 = 0, done2 = 0;
    while (!done1 || !done2) {
        if (done1) {
            if (head == NULL) {
                head = rec(curr2->val);
                temp = head;
            } else {
                temp->next = rec(curr2->val);
                temp = temp->next;
            }
            curr2 = curr2->next;
            if (curr2 == head2) done2 = 1;
        } else if (done2) {
            if (head == NULL) {
                head = rec(curr1->val);
                temp = head;
            } else {
                temp->next = rec(curr1->val);
                temp = temp->next;
            }
            curr1 = curr1->next;
            if (curr1 == head1) done1 = 1;
        } else {
            if (curr1->val < curr2->val) {
                if (head == NULL) {
                    head = rec(curr1->val);
                    temp = head;
                } else {
                    temp->next = rec(curr1->val);
                    temp = temp->next;
                }
                curr1 = curr1->next;
                if (curr1 == head1) done1 = 1;
            } else if (curr1->val > curr2->val) {
                if (head == NULL) {
                    head = rec(curr2->val);
                    temp = head;
                } else {
                    temp->next = rec(curr2->val);
                    temp = temp->next;
                }
                curr2 = curr2->next;
                if (curr2 == head2) done2 = 1;
            } else {
                if (head == NULL) {
                    head = rec(curr1->val);
                    temp = head;
                } else {
                    temp->next = rec(curr1->val);
                    temp = temp->next;
                }
                curr1 = curr1->next;
                curr2 = curr2->next;
                if (curr1 == head1) done1 = 1;
                if (curr2 == head2) done2 = 1;
            }
        }
    }
    temp->next = head;
    struct node* iter = head;
    do {
        printf("%d ", iter->val);
        iter = iter->next;
    } while (iter != head);
    printf("\n");
    return 0;
}

/*How many elements? 2
Enter the value: 1
Enter the value: 3
How many elements? 2
Enter the value: 2
Enter the value: 4
1 2 3 4 
*/
