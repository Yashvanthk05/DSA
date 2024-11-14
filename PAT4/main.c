#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
}

struct node* insert(struct node *root,int data){
    if(root==NULL) return createnode(data);
    if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

struct node* insertlevelorder(struct node *root,int *arr,int i,int n){
    if(i<n){
        struct node *temp=createnode(arr[i]);
        root=temp;
        root->left=insertlevelorder(root->left,arr,2*i+1,n);
        root->right=insertlevelorder(root->right,arr,2*i+2,n);
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
    else if(level==1){
        printf("%d ",root->data);
    }else if(level>1){
        printCurrentLevel(root->right,level-1);
        printCurrentLevel(root->left,level-1);
    }
}

void levelOrder(struct node *root){
    if(root!=NULL){
        int h=height(root);
        for(int i=1;i<=h;i++){
            printCurrentLevel(root,i);
        }
    }
}

void deletenormal(struct node *root,int data){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        if(root->data==data){
            free(root);
            root=NULL;
            printf("Node Deleted Successfully\n");
            return;
        }else{
            return;
        }
    }
    struct node **queue = (struct node**)malloc(sizeof(struct node));
    struct node *keynode=NULL,*lastnode=NULL;
    int front=0,rear=0;
    queue[rear++]=root;
    struct node *temp=NULL;
    while(front<rear){
        temp=queue[front++];
        if(temp->data==data){
            keynode=temp;
        }
        if(temp->left!=NULL){
            lastnode=temp;
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            lastnode=temp;
            queue[rear++]=temp->right;
        }
    }

    if(keynode!=NULL){
        keynode->data=temp->data;
        if(lastnode->left==temp){
            lastnode->left=NULL;
        }else{
            lastnode->right=NULL;
        }
        printf("Node deleted Successfully");
        free(temp);
        return;
    }
    printf("No node deleted");
}

void reverseLevelOrder(struct node *root){
    if(root!=NULL){
        int h=height(root);
        for(int i=h;i>=1;i--){
            printCurrentLevel(root,i);
        }
    }
}

bool isBalanced(struct node *root){
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1){
        printf("Tree is not balanced");
    }
    else{
        printf("Tree is balanced");
    }
}

struct node* ins(struct node *root,int *arr,int level,int n){
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}

void kthMin(struct node *root,int *k,int *result){
    if(root==NULL || *k<=0) return;
    kthMin(root->left,k,result);
    (*k)--;
    if(*k==0){
        *result=root->data;
        return;
    }
    kthMin(root->right,k,result);
}

void kthMax(struct node *root,int *k,int *result){
    if(root==NULL || *k<=0) return;
    kthMax(root->right,k,result);
    (*k)--;
    if(*k==0){
        *result=root->data;
        return;
    }
    kthMax(root->left,k,result);
}

struct node* giveMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node *delete(struct node *root,int data){
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
            struct node *temp=giveMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,data);
        }
    }
    return root;
}

void findMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    printf("\nMinimum Element: %d",root->data);
}

void findMax(struct node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    printf("\nMaximum Element: %d",root->data);
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    struct node *root=NULL;
    root=ins(root,arr,0,7);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\nLevelorder Traversal: ");
    levelOrder(root);
    printf("\nReverse Level Order Traversal: ");
    reverseLevelOrder(root);
    isBalanced(root);
    findMax(root);
    findMin(root);
    int kthminres=-1;
    int kthmini=3;
    int kthmaxres=-1;
    int kthmaxi=4;
    kthMin(root,&kthmini,&kthminres);
    printf("\n3rd Minimum is: %d",kthminres);
    kthMax(root,&kthmaxi,&kthmaxres);
    printf("\n4th Maximum is: %d",kthmaxres);
    delete(root,4);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\nLevelorder Traversal: ");
    levelOrder(root);
    return 0;
}