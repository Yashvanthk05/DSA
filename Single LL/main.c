#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void insertfront(int num){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
}

void insertrear(int num){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    struct node *temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertpos(int pos,int num){
    int c=0;
    struct node *temp;
    while(temp!=NULL){
        temp=temp->next;
        c++;
    }
    
    if(pos>c+1 || pos<1){
        printf("Invalid Position\n");
        return;
    }
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct newnode));
    newnode->data=num;
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }else{
        int count=1;
        temp=head;
        while(count<pos-1){
            count++;
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deletefront(){
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
}

void deleterear(){
    if(head==NULL) return;
    if(head->next==NULL){
        free(head);
        head=NULL;
        return
    }
    struct node *temp,*prev;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}

void deletepos(int pos){
    struct node *temp,*prev;
    temp=head;
    int count=1;
    while(count<pos){
        prev=temp;
        temp=temp->next;
        count++;
    }
    prev->next=temp->next;
    free(temp);
}

void length(){
    struct node *temp;
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
}

void reverse(){
    struct node *prev,*current,*next;
    prev=NULL;
    current=next=head;
    while(current!=NULL){
        next=next->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

void display(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}