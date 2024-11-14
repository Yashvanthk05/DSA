#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=0;

void insertfront(){
    struct node *newnode;
    newnode=(struct newnode*)malloc(sizeof(struct newnode));
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=head;
    if(head!=0){
        head->prev=newnode;
    }
    head=newnode;
}

void insertrear(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    struct node *temp;
    temp=head;
    newnode->next=0;
    if(head==0){
        newnode->prev=0;
        head=newnode
    }else{
        struct node *temp;
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void insertpos(int pos){
    int c=0;
    struct node *temp=head;
    while(temp!=0){
        c++;
        temp=temp->next;
    }
    if(pos>c+1 || pos<1){
        printf("Invalid Position!\n");
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(pos==1){
        newnode->prev=0;
        newnode->next=head;
        if(head!=0){
            head->prev=newnode;
        }
        head=newnode;
    }else{
        temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev = newnode;
        temp->next=newnode;
    }
}

void deletefront(){
    struct node *temp;
    if(head==0){
        printf("Deletion is not possible\n");
        return;
    }
    temp=head;
    head=head->next;
    head->prev=0;
    free(temp);
}

void deleterear(){
    if(head==0){
        printf("Deletion is not possible\n");
        return;
    }
    if(head->next==NULL){
        head=NULL;
        free(head);
    }else{
        struct node *temp;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        temp=head;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->prev->next=0;
        free(temp);
    }
}

void deletepos(int pos){
    int c=getLenght();
    if(pos>c){
        printf("Deletion not possible");
        return;
    }else{
        int count=1;
        struct node *temp=head;
        while(count<pos){
            temp=temp->next;
            count++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}