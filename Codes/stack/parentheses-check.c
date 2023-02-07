#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
  if (top >= MAX-1) {
    printf("Error: Stack overflow\n");
    exit(1);
  } else {
    stack[++top] = c;
  }
}

char pop() {
  if (top < 0) {
    printf("Error: Stack underflow\n");
    exit(1);
  } else {
    return stack[top--];
  }
}

int check_nesting(char exp[]) {
  int i;
  for (i = 0; i < strlen(exp); i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      push(exp[i]);
    } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if (top < 0) {
        return 0;
      } else if (exp[i] == ')' && stack[top] == '(') {
        pop();
      } else if (exp[i] == '}' && stack[top] == '{') {
        pop();
      } else if (exp[i] == ']' && stack[top] == '[') {
        pop();
      } else {
        return 0;
      }
    }
  }
  if (top >= 0) {
    return 0;
  }
  return 1;
}

int main() {
  char exp[MAX];
  printf("Enter an expression: ");
  scanf("%s", exp);
  if (check_nesting(exp)) {
    printf("Expression has balanced parentheses\n");
  } else {
    printf("Expression has unbalanced parentheses\n");
  }
  return 0;
}
