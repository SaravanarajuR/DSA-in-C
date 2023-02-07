#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int eval(int op1, int op2, char operator) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
    }
    return 0;
}

int evaluatePrefix(char prefix[]) {
    int i, op1, op2;
    char ch;

    strrev(prefix);
    for (i = 0; i < strlen(prefix); i++) {
        ch = prefix[i];
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
    char prefix[MAX_SIZE];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    printf("Result: %d\n", evaluatePrefix(prefix));
    return 0;
}
