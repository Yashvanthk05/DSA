#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createnode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
}

struct node* insert1(struct node *root,int data){
    if(root==NULL) return createnode(data);
    
    struct node **queue=(struct node**)malloc(10*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }else{
            temp->left=createnode(data);
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }else{
            temp->right=createnode(data);
        }
    }
    return root;
}

struct node* insert2(struct node *root,int data){
    if(root==NULL) return createnode(data);
    else if(data<root->data){
        root->left=insert2(root->left,data);
    }else if(data>root->data){
        root->right=insert2(root->right,data);
    }
    return root;
}

struct node* insert3(struct node *root,int *arr,int i,int n){
    if(i<n){
        root=createnode(arr[i]);
        root->left=insert3(root->left,arr,2*i+1,n);
        root->right=insert3(root->right,arr,2*i+2,n);
    }
    return root;
}

int height(struct node *root){
    if(root==NULL) return 0;
    else{
        int lh=height(root->left);
        int rh=height(root->right);
        return (lh>rh?lh:rh)+1;
    }
}

void printCurrentLevel(struct node *root,int level){
    if(root==NULL) return;
    if(level==1){
        printf("%d ",root->data);
    }else if(level>1){
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void levelorder1(struct node *root){
    if(root!=NULL){
        int h=height(root);
        for(int i=1;i<=h;i++){
            printCurrentLevel(root,i);
        }
    }
}

int main(){
    return 0;
}