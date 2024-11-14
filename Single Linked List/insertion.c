#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}

struct node *head,*newnode;
head=NULL;
newnode=(struct node*)malloc(sizeof(struct node));

void insertfront(int num){
    newnode->data=num;
    newnode->next=head;
    head=newnode;
}

void insertend(int num){
    newnode->data=num;
    newnode->next=NULL;
    struct node *temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    text->next=newnode;
}

void insertusr(int pos,int num){
    int count=1;
    struct node *temp;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    if(pos>count){
        printf("Position is out of Boundary!!\n");
    }else{
        temp=head;
        count=1;
        while(count<pos){
            temp=temp->next;
        }
        newnode->data=num;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

int main(){
    return 0;
}