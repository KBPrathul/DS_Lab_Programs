//q4 Converting binary to decimal in LL

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* addNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        if (head->data == -1) {
            printf(".");
        } else {
            printf("%d", head->data);
        }
        head = head->next;
    }
    printf("\n");
}

double binaryToDecimal(char* binary) {
    double decimal = 0.0;
    int len = strlen(binary);
    int dotPos = -1;
    for (int i = 0; i < len; i++) {
        if (binary[i] == '.') {
            dotPos = i;
            break;
        }
    }
    if (dotPos == -1) dotPos = len;
    for (int i = 0; i < dotPos; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, dotPos - i - 1);
        }
    }
    for (int i = dotPos + 1; i < len; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, dotPos - i);
        }
    }
    return decimal;
}

struct Node* storeInList(double decimal) {
    struct Node* head = NULL;
    decimal = round(decimal * 1000.0) / 1000.0;
    char str[20];
    sprintf(str, "%.3f", decimal);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            head = addNode(head, -1);
        } else {
            head = addNode(head, str[i] - '0');
        }
    }
    return head;
}

int main() {
    char binary[50];
    printf("Enter binary number: ");
    scanf("%s", binary);
    double decimal = binaryToDecimal(binary);
    struct Node* result = storeInList(decimal);
    printf("Decimal in linked list: ");
    printList(result);
    return 0;
}

/*Enter binary number: 1000.11
Decimal in linked list: 8.750*/