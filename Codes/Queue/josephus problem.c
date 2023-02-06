#include<stdio.h>
#include<stdlib.h>
struct node
{
	int playerid;
	struct node *next;
}*front=0,*newnode,*temp;
void main()
{
	int i,j,n,k,count=0;
	printf("\nEnter the no. of Players: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->playerid=i;
		if(front==0)
			front=temp=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		newnode->next=front;
	}
	printf("Players Ready");
	printf("\n\nEnter the no. to eliminate: ");
	scanf("%d",&k);
	for(j=n;j>1;j--) //To track no of players alive
	{
		count++;
		for(i=1;i<k;i++){
			temp=temp->next;
		}
		printf("\nPlayer no. %d Eliminated in round %d",temp->next->playerid,count);
		del=temp->next;
		temp->next=temp->next->next;
		free(del);
	}
	printf("\nWinner is %d",temp->playerid);
}
