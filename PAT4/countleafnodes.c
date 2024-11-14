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
        root=createnode(arr[i]);
        root->left=insert(root->left,arr,2*i+1,n);
        root->right=insert(root->right,arr,2*i+2,n);
    }
    return root;
}

void levelorder1(struct node *root){
    if(root==NULL) return;
    struct node **queue=(struct node**)malloc(30*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp->left==NULL && temp->right==NULL) printf("%d ",temp->data);
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }
    }
}

int height(struct node *root){
    if(root==NULL) return 0;
    else{
        int lh=height(root->left);
        int rh=height(root->right);
        return (lh>rh?lh:rh)+1;
    }
}

int printCurrentLevel(struct node *root,int level, int max){
    if(root==NULL) return max;
    if(level==1 ){
        if (max < root->data){
            max = root->data;
        }
        return max;
    }else if(level>1){
        int lmax = printCurrentLevel(root->left,level-1, max);
        int rmax = printCurrentLevel(root->right,level-1, max);
        return (lmax>rmax) ? lmax : rmax;
    }
    

}

void levelorder2(struct node *root){
    if(root!=NULL){
        int h=height(root);
        int max = -1;
        int res=0;
        for(int i=1;i<=h;i++){
            res=printCurrentLevel(root,i,max);
        }
        printf("%d ",res);
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    struct node *root=NULL;
    root=insert(root,arr,0,10);
    levelorder2(root);
    return 0;
}