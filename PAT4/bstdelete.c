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

struct node* insert(struct node *root,int data){
    if(root==NULL) return createnode(data);
    else if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node *findMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node* delete(struct node *root,int data){
    if(root==NULL) return root;
    else if(data<root->data){
        root->left=delete(root->left,data);
    }else if(data>root->data){
        root->right=delete(root->right,data);
    }else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }else if(root->left==NULL){
            struct node *temp=root;
            root=root->right;
            free(temp);
        }else if(root->right==NULL){
            struct node *temp=root;
            root=root->left;
            free(temp);
        }else{
            struct node *temp=findMin(root);
            root->data=temp->data;
            root->right=delete(root->right,data);
        }
    }
    return root;
}

int main(){
    int arr[]={5,4,3,2,1,10,9,8,7,6};
    struct node *root=NULL;
    for(int i=0;i<10;i++){
        root=insert(root,arr[i]);
    }
    inorder(root);
    printf("\n");
    delete(root,4);
    inorder(root);
}