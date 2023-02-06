#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};
struct node *temp,*newnode,*head=0,*tail=0;

void display(struct node *h){
    temp=h;
    if(temp->next!=0){
        printf("\n%d",temp->data);
        temp=temp->next;
        display(temp);
    }else{
        printf("\n%d",temp->data);
        return;
    }
}

void delete(int c){
        if(head==0 && tail==0){
        printf("\nEmpty list");
        return;
    }else{
    switch(c){
        case -1:
            head=head->next;
            head->prev=0;
             break;
        case 1:
            tail=tail->prev;
            tail->next=0;
             break;
    }
    return;
    }
}

void insert(int c){
    int d;
    printf("Enter the data");
    scanf("%d",&d);
    newnode=malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next=0;
    newnode->prev=0;
    if(head==0 && tail==0){
        head=newnode;
        tail=newnode;
        return;
    }else{
    switch(c){
        case -1:
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
             break;
        case 1:
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
             break;
    }
    return;
    }
}

void main(){
    int choice=1;
    do{
        printf("\nEnter the choice \n 1.insert right \n 2.insert left \n 3.delete right \n 4.delete left \n 5.display \n 6.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert(1);
                display(head);
                break;
            case 2:
                insert(-1);
                display(head);
                break;
            case 3:
                delete(1);
                display(head);
                 break;
            case 4:
                delete(-1);
                display(head);
                 break;
                case 5:
                display(head);
                 break;
            case 6:
                break;
        }
    }while(choice!=6);
}
