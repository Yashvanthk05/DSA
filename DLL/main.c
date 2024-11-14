#include<stdio.h>
#include<stdlib.h>

// struct node{
//     int data;
//     struct node *next;
//     struct node *prev;
// };

// struct node *head=NULL,*newnode;

// void create(){
//     struct node *temp;
//     newnode=(struct node*)malloc(sizeof(struct node));
//     scanf("%d",&newnode->data);
//     newnode->prev=NULL;
//     newnode->next=NULL;
//     if(head==NULL){
//         head==temp=newnode;
//     }else{
//         temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         newnode->prev=temp;
//         temp->next=newnode;
//         temp=newnode;
//     }
// }

void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
//Starting..

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head,*tail;
void createDLL(){
    struct node *newnode;
    head=0;
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
    }else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insertfront(){
    struct node *newnode;
    newnode=(struct newnode*)malloc(sizeof(struct newnode));
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    
}