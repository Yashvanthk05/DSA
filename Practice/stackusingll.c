#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;

void push(int num){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=top;
    top=newnode;
}

void display(){
    struct node* temp;
    if(top==NULL){
        printf("Stack is Empty!!\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void peek(){
    if(top==NULL){
        printf("Stack is Empty!!\n");
        return;
    }
    printf("Top of the Stack: %d\n",top->data);
}

void pop(){
    if(top=NULL){
        printf()
    }
}

int main(){

    return 0;
}