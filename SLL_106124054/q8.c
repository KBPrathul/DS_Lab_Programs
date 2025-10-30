//q8 Adding numbers as LL

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

int main() {
    int n, m;
    printf("What is the first number? ");
    scanf("%d", &n);
    printf("What is the second number? ");
    scanf("%d", &m);
    int value1 = n % 10;
    n /= 10;
    struct node* head1 = create_node(value1);
    struct node* temp1 = head1;
    while(n > 0) {
        value1 = n % 10;
        n /= 10;
        temp1->next = create_node(value1);
        temp1 = temp1->next;
    }
    int value2 = m % 10;
    m /= 10;
    struct node* head2 = create_node(value2);
    struct node* temp2 = head2;
    while(m > 0) {
        value2 = m % 10;
        m /= 10;
        temp2->next = create_node(value2);
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    struct node* head3 = NULL;
    struct node* temp3 = NULL;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL || carry != 0) {
        int sum = carry;
        if(temp1 != NULL) {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if(temp2 != NULL) {
            sum += temp2->val;
            temp2 = temp2->next;
        }
        carry = sum / 10;
        int digit = sum % 10;
        struct node* new_node = create_node(digit);
        if(head3 == NULL) {
            head3 = new_node;
            temp3 = head3;
        } else {
            temp3->next = new_node;
            temp3 = temp3->next;
        }
    }
    printf("Sum as list (reversed digits): ");
	temp3=head3;
    while(temp3 != NULL) {
        printf("%d ", temp3->val);
        temp3 = temp3->next;
    }
    printf("\n");
    return 0;
}
/*What is the first number? 123
What is the second number? 19
Sum as list (reversed digits): 2 4 1 
*/