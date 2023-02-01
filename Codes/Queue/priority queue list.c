#include<stdio.h>
#include<stdlib.h>
struct node{
	int data,priority;
	struct node *next;
}*front=0,*newnode,*temp;
void enqueue(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data and priority: ");
	scanf("%d %d",&newnode->data,&newnode->priority);
	if(front==0||(newnode->priority)<(front->priority)){
		newnode->next=front;
		front=newnode;
	}else{
		temp=front;
		while((temp->next!=0)&&(temp->next->priority)<=(newnode->priority)){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	printf("Element Inserted");
}
void dequeue(){
	if(front==0){
		printf("Queue is Empty");
	}else{
		temp=front;
		printf("Dequeued element-%d--priority-%d\t",front->data,front->priority);
		front=front->next;
		free(temp);
	}
}
void display(){
	if(front==0){
		printf("Queue is Empty");
	    }else{
		temp=front;
		while(temp!=0){
			printf("Element-%d--priority %d\n",temp->data,temp->priority);
			temp=temp->next;
		}
	}
}
void main(){
	int choice;
	printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.End");
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;
			case 4:
					break;
			default: printf("Invalid Choice");
		}
	}while(choice!=4);
}
