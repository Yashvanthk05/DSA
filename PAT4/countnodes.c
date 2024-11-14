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
    if(level==1 && root->data==data){
        printf("%d ",root->data);
    }else if(level>1){
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

struct node* parent(struct node *root, int d){
    if(root==NULL) return root;
    if (root->left->data == d || root->right->data == d){
        
        printf("%d ", root->data);
        return root;
    }
    else{
        root->left=parent(root->left, d);
        root->right=parent(root->right, d);
    }
    return root;
}

void levelorder(struct node *root){
    if(root!=NULL){
        int h=height(root);
        struct node *temp=NULL;
        for(int i=1;i<=h;i++){
            printCurrentLevel(root,i,temp);
        }
    }
}

void level(struct node *root){
    if(root==NULL);
    struct node **queue=(struct node**)malloc(10*sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front < rear){
        int size = rear - front;
        printf("Level %d count: %d\n", front, size);
        
        for(int i = 0; i < size; i++){
            struct node *temp = queue[front++];
            
            if(temp->left != NULL)
                queue[rear++] = temp->left;
            
            if(temp->right != NULL)
                queue[rear++] = temp->right;
        }
    }
}


int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    struct node *root=NULL;
    root=insert(root,arr,0,10);
    parent(root,7);
}