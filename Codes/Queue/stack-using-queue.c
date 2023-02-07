#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue1[MAX];
int front1 = -1, rear1 = -1;
int queue2[MAX];
int front2 = -1, rear2 = -1;

void push(int data) {
    if (rear1 == MAX - 1) {
        printf("Error: Stack overflow\n");
        return;
    }

    rear1++;
    queue1[rear1] = data;
}

int pop() {
    if (front1 == -1 || front1 > rear1) {
        printf("Error: Stack underflow\n");
        return -1;
    }

    while (front1 < rear1) {
        int data = queue1[front1];
        front1++;
        if (front2 == -1 && rear2 == -1) {
            front2 = rear2 = 0;
            queue2[rear2] = data;
        } else {
            rear2++;
            queue2[rear2] = data;
        }
    }
    int pop_data = queue1[front1];
    front1 = -1;
    rear1 = -1;
    int i;
    for (i = front2; i <= rear2; i++) {
        if (front1 == -1 && rear1 == -1) {
            front1 = rear1 = 0;
            queue1[rear1] = queue2[i];
        } else {
            rear1++;
            queue1[rear1] = queue2[i];
        }
    }
    front2 = -1;
    rear2 = -1;
    return pop_data;
}

void display() {
    int i;
    for (i = front1; i <= rear1; i++) {
        printf("%d ", queue1[i]);
    }
    printf("\n");
}

void main() {
 	int ch,d;
    printf("\n1 - Enqueue element into stack");
    printf("\n2 - Dequeu element from stack");
    printf("\n3 - Display from stack");
    printf("\n4 - Exit");
    while (1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        	printf("Enter data to add");
        	scanf("%d",&d)
            push(d);
            display();
            break;
        case 2:
            d=pop();
            printf("%d is poped element",d);
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}
