#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;

void insert(){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
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

void unique(){
    struct node *t1=head;
    while(t1!=NULL){
        struct node *t2=t1->next;
        while(t2!=NULL){
            if(t1->data==t2->data){
                t2->prev->next=t2->next;
                t2->next->prev=t2->prev;
                free(t2);
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
}

void sort(){
    struct node *t1=head;
    while(t1!=NULL){
        struct node *t2=t1->next;
        while(t2!=NULL){
            if(t1->data>t2->data){
                int temp=t2->data;
                t2->data=t1->data;
                t1->data=temp;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
}


void display(){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    for(int i=0;i<5;i++){
        insert();
    }
    display();
    unique();
    display();
    sort();
    display();
    return 0;
}