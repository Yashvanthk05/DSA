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
    return newnode;
}

struct node* insert1(struct node *root,int data){
    if(root==NULL) return createnode(data);

    struct node **queue=(struct node**)malloc(30*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp->left==NULL){
            temp->left=createnode(data);
            return root;
        }else{
            queue[rear++]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=createnode(data);
            return root;
        }else{
            queue[rear++]=temp->right;
        }
    }
    return root;
}

struct node* insert2(struct node* root,int *arr,int i,int n){
    if(i<n){
        struct node *temp=createnode(arr[i]);
        root=temp;
        root->left=insert2(root->left,arr,2*i+1,n);
        root->right=insert2(root->right,arr,2*i+2,n);
    }
    return root;
}

struct node* insert3(struct node* root,int data){
    if(root==NULL) return createnode(data);
    else if(data<root->data){
        root->left=insert3(root->left,data);
    }else if(data>root->data){
        root->right=insert3(root->right,data);
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
    if(level==1 && root->left==NULL && root->right==NULL){
        printf("%d ",root->data);
    }else if(level>1){
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void levelorder2(struct node *root){
    if(root!=NULL){
        int h=height(root);
        for(int i=1;i<=h;i++){
            printCurrentLevel(root,i);
        }
    }
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
            struct node *temp=giveMin(root->right,data);
            root->data=temp->data;
            root->right=delete(root->right,data);
        }
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
        printf("%d ",temp->data);
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    struct node *root=NULL;
    int n;
    scanf("%d",&n);
    int num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=insert1(root,num);
    }
    levelorder(root,0,10);
    return 0;
}