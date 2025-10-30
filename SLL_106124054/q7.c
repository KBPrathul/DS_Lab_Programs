//q7    Reversing nodes of LL k at a time

#include<stdio.h>
#include<stdlib.h>

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
struct node* reverse(struct node* start, struct node* end) {
    struct node* prev = NULL;
    struct node* curr = start;
    struct node* next = NULL;
    
    while (curr != end) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    printf("How many ride requests are there? ");
    scanf("%d", &n);
    printf("What is the value of k? ");
    scanf("%d", &k);
    int value;
    printf("What is the value at this node? ");
    scanf("%d", &value);
    struct node* head = create_node(value);
    struct node* temp = head;
    for (int i = 1; i < n; i++) {
        printf("What is the value at this node? ");
        scanf("%d", &value);
        temp->next = create_node(value);
        temp = temp->next;
    }
    printf("Original list: ");
    print_list(head);

    struct node* dummy = create_node(0);
    dummy->next = head;
    struct node* prev_group_end = dummy;
    struct node* curr = head;
    
    while (curr != NULL) {
        struct node* group_start = curr;
        struct node* group_end = curr;
        int count = 1;
        while (group_end != NULL && count < k) {
            group_end = group_end->next;
            count++;
        }
        if (group_end == NULL) {
            break;
        }
        struct node* next_group_start = group_end->next;
        
        struct node* reversed_head = reverse(group_start, next_group_start);
        
        prev_group_end->next = reversed_head;
        group_start->next = next_group_start;
        
        prev_group_end = group_start;
        curr = next_group_start;
    }
    head = dummy->next;
    printf("List after reversing nodes: ");
    print_list(head);
    return 0;
}

/*How many ride requests are there? 8
What is the value of k? 3
What is the value of this node? 1
What is the value of this node? 2
What is the value of this node? 3
What is the value of this node? 4
What is the value of this node? 5
What is the value of this node? 6
What is the value of this node? 7
What is the value of this node? 8
Original list: 1 2 3 4 5 6 7 8 
List after reversing every 3 nodes: 3 2 1 6 5 4 7 8 */