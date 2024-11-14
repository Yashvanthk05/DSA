#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node *root,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        return newnode;
    }

    struct node** queue=(struct node*)malloc(100*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp->left==NULL){
            temp->left=newnode;
            return root;
        }else{
            queue[rear++]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=newnode;
            return root;
        }else{
            queue[rear++]=temp->right;
        }
    }
    return root;
}

int main(){
    int n;
    scanf("%d",&n);
    struct node *root=NULL;
    int num;
    
    return 0;
}