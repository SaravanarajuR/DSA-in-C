#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

int priority(char operator) {
    switch (operator) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void convertToPrefix(char infix[], char prefix[]) {
    int i, j = 0, k, op1, op2;
    char operator;
    strrev(infix);
    for (i = 0; i < strlen(infix); i++) {
        if (infix[i] == ')') {
            push(infix[i]);
        } else if (isdigit(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == '(') {
            while (stack[top] != ')') {
                prefix[j++] = pop();
            }
            top--;
        } else {
            while (priority(stack[top]) >= priority(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top > -1) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    convertToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
