#include <stdio.h>
#include <stdlib.h>

int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;

void enqueue()
{
    int data, i;
    printf("Enter data into queue");
    scanf("%d", &data);
    push1(data);
    st1[top1+1] = data;
    top1++;
}

void dequeue()
{
	if(top1==-1){
		printf("Empty queue");
		return;
	}
    for (int i = top1;i > 0;i--)
    {
       st2[top2+1]=st1[i];
       top2++;
    }
    top1=-1;
    for(int i=0;i<=top2;i++){
    	st1[top1+1]=st2[i];
    	top1++;
    }
    top2=-1;
}

void display()
{
if(top1==-1){
		printf("Empty queue");
		return;
	}
    int i;
for (i = 0;i <= top1;i++)
    {
        printf(" %d ", st1[i]);

    }
}

void main()
{
 	int ch;
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeu element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit");
    while (1)
    {
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            display();
            break;
        case 2:
            dequeue();
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
