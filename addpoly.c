#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
};

struct node* createNode(int coeff,int exp){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->next=NULL;
    return newnode;
}

void insertNode(struct node **head,int coeff,int exp){
    struct node* newnode=createNode(coeff,exp);
    if(*head==NULL || (*head)->exp<exp){
        newnode->next=head;
        head=newnode;
    }else{
        struct node *temp=*head;
        while(temp->next!=NULL && temp->next->exp>exp){
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}

struct addPolynomials(struct node *poly1,struct node *poly2){
    struct node *result=NULL;
    while(poly1!=NULL && poly2!=NULL){
        if(poly1->exp==poly2->exp){
            int sum=poly1->coeff+poly2->coeff;
            if(sum!=0){
                insertNode(&result,sum,poly1->exp);
            }
            poly1=poly1->next;
            poly2=poly2->next;
        }else if(poly1->exp>poly2->exp){
            insertNode(&result,)
        }
    }
}

int main(){
    return 0;
}