//q2b2    Infix to Prefix conversion using stack

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

void reverseString(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    printf("Enter the maximum length of the expression: ");
    scanf("%d", &n);
    getchar();
    char infix[n+1];
    printf("Enter the infix expression: ");
    fgets(infix, n+1, stdin);
    n = strlen(infix);
    
    reverseString(infix, n);
    
    for(int i = 0; i < n; i++) {
        if(infix[i] == '(') {
            infix[i] = ')';
        }
        else if(infix[i] == ')') {
            infix[i] = '(';
        }
    }
    
    struct stack* s = createstack(n);
    char postfix[n+1];
    int ptr = 0;
    
    for(int i = 0; i < n; i++) {
        if(isalnum(infix[i])) {
            postfix[ptr++] = infix[i];
        }
        else if(infix[i] == '(') {
            push(s, infix[i]);
        }
        else if(infix[i] == ')') {
            while(!isEmpty(s) && peek(s) != '(') {
                postfix[ptr++] = pop(s);
            }
            pop(s);
        }
        else {
            while(!isEmpty(s) && prec(infix[i]) < prec(peek(s))) {
                postfix[ptr++] = pop(s);
            }
            push(s, infix[i]);
        }
    }
    while(!isEmpty(s)) {
        postfix[ptr++] = pop(s);
    }
    postfix[ptr] = '\0';
    reverseString(postfix, ptr);
    
    printf("Prefix expression: %s\n", postfix);
    return 0;
}

/*Enter the maximum length of the expression: 5
Enter the infix expression: 1+2*3
Prefix expression: +1*23
*/
