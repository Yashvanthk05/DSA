#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node* top=NULL;
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
        printf("Stack is Empty\n");
        return;
    }
    printf("Popped: %d\n",top->data);
    top=top->next;
}
void display(){
    if(top==NULL){
        printf("Stack is Empty\n");
        return;
    }
    struct node *temp;
    temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void peek(){
    if(top==NULL){
        printf("Stack is Empty\n");
        return;
    }
    printf("Top of the Stack: %d\n",top->data);
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    display();
    push(6);
    peek();
    display();
    return 0;
}