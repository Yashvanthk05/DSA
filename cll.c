#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=0;
struct node *tail=0;

void createCLL(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
    tail->next=head;
}

void displayCLL(){
    struct node *temp;
    if(tail==0){
        printf("Empty\n");
    }else{
        temp = tail->next;
        while(temp->next!=tail->next){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

void insertfront(){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0){
        tail=newnode;
        tail->next=newnode;
    }else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
}
 