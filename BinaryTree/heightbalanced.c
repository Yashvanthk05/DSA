#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node* root,int data){
    if(root==NULL){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

int height(struct node *root){
    if(root==NULL){
        return 0;
    }else{
        int lh=height(root->left);
        int rh=height(root->right);
        return (lh>rh)?lh+1:rh+1;
    }
}

bool isBalanced(struct node *root){
    if(root==NULL) return true;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1){
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    int n;
    scanf("%d",&n);
    int num;
    struct node* root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=insert(root,num);
    }
    if(isBalanced(root)){
        printf("Tree is Balanced");
    }else{
        printf("Tree is not Balanced");
    }
    return 0;
}