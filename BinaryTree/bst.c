#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node *root,int data){
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

void levelOrderTraversal(struct node* root){
    if(root==NULL) return;
    struct node **queue=(struct node**)malloc(100*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        printf("%d ",temp->data);
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }
    }
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void findMin(struct node* root){
    if(root!=NULL){
        while(root->left!=NULL){
            root=root->left;
        }
        printf("\n%d ",root->data);
    }
}

void findMax(struct node* root){
    if(root!=NULL){
        while(root->right!=NULL){
            root=root->right;
        }
        printf("\n%d ",root->data);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    struct node *root=NULL;
    int num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=insert(root,num);
    }
    levelOrderTraversal(root);
    printf("\n");
    inorder(root);
    findMax(root);
    return 0;
}