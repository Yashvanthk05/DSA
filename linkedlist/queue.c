#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int num){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }else{
        rear->next=newnode;
        rear=newnode;
    }
    printf("Enqueued: %d\n",rear->data);
}
void dequeue(){
    if(front==NULL && rear==NULL){
        printf("Queue is Empty\n");
        return;
    }
    printf("Dequeued: %d\n",front->data);
    front=front->next;
}
void display(){
    if(front==NULL && rear==NULL){
        printf("Queue is Empty\n");
        return;
    }
    struct node *temp;
    temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void peek(){
    if(front==NULL && rear==NULL){
        printf("Queue is Empty\n");
        return;
    }
    printf("Top of the Queue: %d\n",front->data);
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    return 0;
}