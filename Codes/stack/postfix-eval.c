#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    top++;
    stack[top] = item;
}

int pop() {
    top--;
    return stack[top];
}

int eval(int op1, int op2, char operator) {
    switch (operator) {
        case '+': return op2 + op1;
        case '-': return op2 - op1;
        case '*': return op2 * op1;
        case '/': return op2 / op1;
        case '^': return op2 * op1;
    }
    return 0;
}

int evaluatePostfix(char postfix[],int n) {
    int i, op1, op2;
    char ch;

    for (i = 0; i < n; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op1 = pop();
            op2 = pop();
            push(eval(op1, op2, ch));
        }
    }
    return stack[top];
}

int main() {
    int n;
    char postfix[MAX];
    printf("Enter the length of postfix expression: ");
    scanf("%d",&n);
    printf("Enter the postfix expression: ");
    for(int i=0;i<n;i++){
        scanf("%c", postfix[i]);
    }
    printf("Result: %d\n", evaluatePostfix(postfix,n));
    return 0;
}
