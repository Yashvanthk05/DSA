#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node *root,int *arr,int i,int n){
    if(i<n){
        struct node *temp=createnode(arr[i]);
        root=temp;
        root->left=insert(root->left,arr,2*i+1,n);
        root->right=insert(root->right,arr,2*i+2,n);
    }
    return root;
}