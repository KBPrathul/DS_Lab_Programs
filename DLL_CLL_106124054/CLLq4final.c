//CLLq4    Josephus problem

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* rec(int n) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = n;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, k;
    printf("Enter number of people: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);
    struct node* head = rec(1);
    struct node* temp = head;
    for (int i = 2; i <= n; i++) {
        temp->next = rec(i);
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    while (temp->next != temp) {
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
        }
        struct node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        temp = temp->next;
    }
    printf("\nThe safe position is %d\n", temp->val);
    free(temp);
    return 0;
}

/*Enter number of people: 7
Enter k: 3
The safe position is 4
*/
