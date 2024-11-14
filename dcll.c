#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head,*tail;

void createDCLL(){
    head=tail=0;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
        head->prev=newnode;
        head->next=newnode;
    }else{
        tail->next=newnode;
        newnode->prev=tail;
        head->prev=newnode;
        newnode->next=head;
        tail=newnode;
    }
}

void display(){
    if(head==0){
        printf("Doubly Linked List is Empty\n");
        return;
    }
    struct node *temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

void insertfront(){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        newnode->prev=tail;
        tail->next=head;
    }
}

void insertend(){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
    }else{
        tail->next=newnode;
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=tail;
        tail=newnode;
    }
}

void deletefront(){
    if(head==0){
        return;
    }
    else if(head->next==head){
        head=tail=0;
    }else{
        struct node *temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void deleteend(){
    if(head==0){
        return;
    }else if(head->next==head){
        head=tail=0;
    }else{
        struct node *temp=tail;
        tail->prev->next=head;
        head->prev=tail->prev;
        tail=tail->prev;
        free(temp);
    }
}