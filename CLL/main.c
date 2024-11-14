#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head=0;

void CreateCLL(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    if(head==0){
        head=newnode;
        newnode->next=head;
    }else{
        struct node *temp;
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
}

void display(){
   struct node *temp=head;
   while(temp->next!=head){
    printf("%d ",temp->data);
    temp=temp->next;
   }
   printf("%d\n",temp->data);
}