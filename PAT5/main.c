#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *left,*right;
};

struct node *createnode(char data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    return newnode;
}

struct node *insert(struct node *root,char data){
    if(root==NULL) return createnode(data);
    else if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void findMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    printf("Minimum value: %c\n",root->data);
}

void findMax(struct node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    printf("Maximum value: %c",root->data);
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    struct node *root=NULL;
    char c;
    for(int i=0;i<n;i++){
        scanf("%c",&c);
        getchar();
        root=insert(root,c);
    }
    findMin(root);
    findMax(root);
    return 0;
}