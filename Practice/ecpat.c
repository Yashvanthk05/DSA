#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *top=NULL;
void push(int num){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=top;
    top=newnode;
    printf("Pushed: %d\n",top->data);
}

void pop(){
    if(top==NULL){
        printf("Stack is Empty!!");
        return;
    }
}

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}

void display(){
    if(top==NULL){
        printf("Stack is Empty\n");
        return;
    }
    struct node* temp;
    temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    for(int i=num;i>=1;i--){
        push(factorial(i));
    }
    display();
    return 0;
}