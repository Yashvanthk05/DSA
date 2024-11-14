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

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        if(root->data!=-1) printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    root=insert(arr,)
    return 0;
}