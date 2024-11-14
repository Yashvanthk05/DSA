#include<stdio.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node *head,*newnode,*temp;
head=NULL;
newnode=(node*)malloc(sizeof(node));
printf("Enter Data: ");
scanf("%d",&newnode->data);
newnode->next=0;
if(head==NULL){
    head=temp=newnode;
}else{
    temp->next=newnode;
    temp=newnode;
}
