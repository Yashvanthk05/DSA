#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;

void insert(){
    struct node *newnode=(struct node*)malloc((sizeof(struct node)));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
    }
}

void rotate(int pos){
    for(int i=0;i<pos;i++){
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        temp->prev=NULL;
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
}

void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    for(int i=0;i<5;i++){
        insert();
    }
    rotate(3);
    display();
    return 0;
}