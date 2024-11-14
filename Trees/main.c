#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}

struct node* insert(struct node *root,int data){
    if(root==NULL) return createNode(data);
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
    printf("Minimum Element of the Tree is: %d\n",root->data);
}

void findMax(struct node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    printf("Maximum Element of the Tree is: %d\n",root->data);
}

struct node* levelOrderInsertion(struct node *root,int data){
    struct node *newnode=createNode(data);
    if(root==NULL){
        return newnode;
    }
    if(root->left==NULL){
        root->left=newnode;
    }else if(root->right==NULL){
        root->right=newnode;
    }else{
        if(insert(root->left,data)==NULL){
            insert(root->right,data);
        }
    }
    return root;
}


int height(struct node *root){
    if(root==NULL) return 0;
    else{
        int lh=height(root->left);
        int rh=height(root->right);
        return ((lh>rh)?lh:rh)+1;
    }
}

void printCurrentLevel(struct node *root,int level){
    if(root==NULL) return;
    else if(level==1){
        printf("%d ",root->data);
    }else if(level>1){
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

int findIndex(struct node* root, int data,int *index){
    if(root==NULL) return -1;
    int leftIndex=findIndex(root->left,data,index);
    if(leftIndex!=-1) return leftIndex;
    if(root->data==data) return *index;
    (*index)++;
    return findIndex(root->right,data,index);
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

void levelOrder(struct node *root){
    if(root!=NULL){
        printf("Level Order Traversal: ");
        int h=height(root);
        for(int i=1;i<=h;i++){
            printCurrentLevel(root,i);
        }
    }
}

void reverseLevelOrder(struct node *root){
    if(root!=NULL){
        printf("Reverse Level Order: ");
        int h=height(root);
        for(int i=h;i>=1;i--){
            printCurrentLevel(root,i);
        }
    }
}

void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    struct node *root=NULL;
    int num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=levelOrderInsertion(root,num);
    }
    levelOrder(root);
    printf("\nInOrder Traversal: ");
    inOrder(root);
    printf("\nPreOrder Traversal: ");
    preOrder(root);
    printf("\nPostOrder Traversal: ");
    postOrder(root);
    reverseLevelOrder(root);
    printf("\nIndex of 1: %d\n",findIndex(root,1,0));
    return 0;
}