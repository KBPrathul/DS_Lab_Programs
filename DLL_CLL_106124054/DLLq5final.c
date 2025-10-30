//q5    Finding duplicates from unsorted DLL

#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int val;
    struct node* next;
};

struct node* create_node(int n) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = n;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void remove_duplicates(struct node* head) {
    struct node *current, *runner, *temp;
    current = head;
    while (current != NULL && current->next != NULL) {
        runner = current;
        while (runner->next != NULL) {
            if (current->val == runner->next->val) {
                temp = runner->next;
                runner->next = runner->next->next;
                if (runner->next != NULL) {
                    runner->next->prev = runner;
                }
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    printf("\n");
}

void print_list(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void free_list(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int m;
    printf("How many elements do you want in the list? ");
    scanf("%d", &m);
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    struct node* head = create_node(value);
    struct node* temp = head;
    for (int i = 1; i < m; i++) {
        printf("Enter the value: ");
        scanf("%d", &value);
        temp->next = create_node(value);
        temp->next->prev = temp;
        temp = temp->next;
    }
    printf("\nOriginal list: ");
    print_list(head);
    remove_duplicates(head);
    printf("List after removing duplicates: ");
    print_list(head);
    free_list(head);
    return 0;
}
/*How many elements do you want in the list? 6
Enter the value: 2
Enter the value: 1
Enter the value: 3
Enter the value: 2
Enter the value: 2
Enter the value: 3

Original list: 2 1 3 2 2 3 

List after removing duplicates: 2 1 3*/