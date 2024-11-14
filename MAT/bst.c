#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createnode(int data){
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->left=NULL,root->right=NULL;
    root->data=data;
    return root;
}

struct node* insert(struct node* root,int data){
    if(root==NULL) return createnode(root,data);
    else if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void levelOrder(struct node *root){
    if(root==NULL) return;
    struct node **q=(struct node**)malloc(sizeof(struct node));
    int front=0,rear=0;
    q[rear++]=root;
    while(front<rear){
        struct node *temp=q[front++];
        if(temp->left!=NULL){
            q[rear++]=temp->left;
        }else{
            temp->left=newnode;
            return root;
        }
    }
}

int main(){
    return 0;
}