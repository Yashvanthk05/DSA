#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}

struct node *head=NULL;

void deletefront(){
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
}

void deleterear(){
    struct node *temp,*prev;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=0;
    }else{
        prev->next=0;
    }
    free(temp);
}

void deleteusr(int pos){
    struct node *temp=head;
    int count=1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
}

void display(){
    struct node *temp=head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
    }
    printf("\n");
}

int main(){
    return 0;
}