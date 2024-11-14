#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int ex;
    struct node *next;
};

void insert(struct node **head,int coeff,int ex){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->ex=ex;
    if(*head==NULL){
        head=newnode;
    }else{
        struct node *temp;
        while(temp->next!=NULL && temp->ex>ex){
            if(temp->ex==ex){
                temp->coeff+=coeff;
            }
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void mulitply(struct node *poly1,struct node *poly2){
    for(struct node* p1;p1!=NULL;p1=p1->next){
        for(struct node *p2;p2!=NULL;p2=p2->next){
            
        }
    }
}

int main(){
    return 0;
}