//q2a    Infix to Postfix conversion using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct stack {
    int top;
    int capacity;
    char* arr;
};

struct stack* createstack(int cap) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = cap;
    s->top = -1;
    s->arr = (char*)malloc(s->capacity * sizeof(char));
    return s;
}

int isFull(struct stack* s) {
    return (s->top == s->capacity-1);
}

int isEmpty(struct stack* s) {
    return (s->top == -1);
}

void push(struct stack* s, char x) {
    if(!isFull(s)) {
        s->arr[++s->top] = x;
    }
    else {
        printf("Stack Overflow\n");
    }
}

char pop(struct stack* s) {
    if(!isEmpty(s)) {
        return s->arr[s->top--];
    }
    printf("Stack Underflow\n");
    return '\0';
}

char peek(struct stack* s) {
    if(!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

int prec(char x) {
    if(x=='*'||x=='/'){return 2;}
    else if(x=='+'||x=='-'){return 1;}
    else{return 0;}
}

int main() {
    int n;
    printf("Enter the maximum length of the expression: ");
    scanf("%d", &n);
    getchar();
    char arr[n+1];
    printf("Enter the infix expression: ");
    fgets(arr, n+1, stdin);
    n = strlen(arr);
    char ans[n+1];
    struct stack* s = createstack(n);
    int ptr = 0;
    for(int i = 0; i < n; i++) {
        if(isalnum(arr[i])) {
            ans[ptr++] = arr[i];
        }
        else if(arr[i] == '(') {
            push(s, arr[i]);
        }
        else if(arr[i] == ')') {
            while(!isEmpty(s) && peek(s) != '(') {
                ans[ptr++] = pop(s);
            }
            pop(s);
        }
        else {
            while(!isEmpty(s) && prec(arr[i]) <= prec(peek(s))) {
                ans[ptr++] = pop(s);
            }
            push(s, arr[i]);
        }
    }
    
    while(!isEmpty(s)) {
        ans[ptr++] = pop(s);
    }
    ans[ptr] = '\0';
    printf("Postfix expression: %s\n", ans);
    return 0;
}

/*Enter the maximum length of the expression: 5
Enter the infix expression: 1+2*3
Postfix expression: 123*+
*/
