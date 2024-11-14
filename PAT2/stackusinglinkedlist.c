#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;
void push(int num){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=top;
    top=newnode;
    printf("Pushed: %d\n",top->data);
}
void display(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("Stack is Empty!!\n");
        return;
    }
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
}
void peek(){
    if(top==NULL){
        printf("Stack is Empty!!\n");
        return;
    }
    printf("Top of the Stack is: %d\n",top->data);
}
void pop(){
    if(top==NULL){
        printf("Stack is empty!!\n");
        return;
    }
    printf("Popped Element: %d\n",top->data);
    top=top->next;
}
int main(){
    push(2);
    push(3);
    push(10);
    display();
    peek();
    pop();
    display();
    return 0;
}