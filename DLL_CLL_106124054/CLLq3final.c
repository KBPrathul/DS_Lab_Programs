//q1-a    Rearranging nodes in CLL

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

int main() {
    int n, value;
    printf("How many elements do you want in the list? ");
    scanf("%d", &n);
    printf("Enter the value: ");
    scanf("%d", &value);
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->val = value;
    head->next = head;
    struct node* temp = head;
    for(int i = 1; i < n; i++) {
        printf("Enter the value: ");
        scanf("%d", &value);
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp = temp->next;
        temp->val = value;
        temp->next = head;
    }
    struct node* slow = head;
    struct node* fast = head;
    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct node* head2 = slow->next;
    slow->next = head;
    struct node* tail2 = head2;
    while(tail2->next != head) {
        tail2 = tail2->next;
    }
    tail2->next = head2;
    struct node* prev = NULL;
    struct node* current = head2;
    struct node* next = NULL;
    struct node* tail_reversed = head2;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while(current != head2);
    head2 = prev;
    tail_reversed->next = head2;
    struct node* p1 = head;
    struct node* p2 = head2;
    struct node* result = NULL;
    struct node* tail_result = NULL;
    while(1) {
        if(result == NULL) {
            result = p1;
            tail_result = p1;
            p1 = p1->next;
        } else {
            tail_result->next = p1;
            tail_result = p1;
            p1 = p1->next;
        }
        tail_result->next = p2;
        tail_result = p2;
        p2 = p2->next;
        if(p1 == head && p2 == head2) {
            break;
        }
        if(p1 == head || p2 == head2) {
            if(p1 == head) {
                tail_result->next = p2;
                while(p2->next != head2) p2 = p2->next;
                p2->next = result;
            } else {
                tail_result->next = p1;
                while(p1->next != head) p1 = p1->next;
                p1->next = result;
            }
            break;
        }
    }
    tail_result->next = result;
    head = result;
    printf("Rearranged list: ");
    temp = head;
    do {
        printf("%d ", temp->val);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
    return 0;
}

/*How many elements do you want in the list? 6
Enter the value: 1
Enter the value: 2
Enter the value: 3
Enter the value: 4
Enter the value: 5
Enter the value: 6
Rearranged list: 1 6 2 5 3 4*/
