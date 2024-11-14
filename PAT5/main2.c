#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *createnode(int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root,int data){
    if(root==NULL) return createnode(data);
    else if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

struct node *findMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node *findMax(struct node *root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

void findKthMin(struct node *root,int *k){
    if(root==NULL || *k<=0) return;
    findKthMin(root->left,k);
    (*k)--;
    if(*k==0){
        printf("Kth Minimum Element: %d\n",root->data);
        return;
    }
    findKthMin(root->right,k);
}

void findKthMax(struct node *root,int *k){
    if(root==NULL || *k<=0) return;
    findKthMax(root->right,k);
    (*k)--;
    if(*k==0){
        printf("Kth Maximum Element: %d\n",root->data);
        return;
    }
    findKthMax(root->left,k);
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
    }else{
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
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
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
struct node *lca(struct node *root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data>n1 && root->data>n2){
        return lca(root->left,n1,n2);
    }else if(root->data<n1 && root->data<n2){
        return lca(root->right,n1,n2);
    }
    return root;
}
int findDistanceFromRoot(struct node *root,int n){
    int distance=0;
    while(root!=NULL){
        if(root->data<n){
            root=root->right;
        }else if(root->data>n){
            root=root->left;
        }
        else{
            return distance;
        }
        distance++;
    }
    return -1;
}
int distanceBetweenTwoNode(struct node *root,int n1,int n2){
    struct node *ca=lca(root,n1,n2);
    int d1=findDistanceFromRoot(ca,n1);
    int d2=findDistanceFromRoot(ca,n2);
    return d1+d2;
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
            struct node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,data);
        }
    }
    return root;
}
void noOfNodes(struct node *root,int *count){
    if(root==NULL) return;
    (*count)++;
    noOfNodes(root->left,count);
    noOfNodes(root->right,count);
}
void sumOfNodes(struct node *root,int *sum){
    if(root==NULL) return;
    (*sum)+=root->data;
    sumOfNodes(root->left,sum);
    sumOfNodes(root->right,sum);
}
void calculateSumAndNodes(struct node *root){
    int sum=0;
    int nonodes=0;
    noOfNodes(root,&nonodes);
    sumOfNodes(root,&sum);
    printf("No of Nodes: %d\n",nonodes);
    printf("Sum of all the Nodes: %d\n",sum);
}
int isBSTUtil(struct node *root,int min,int max){
    if(root==NULL) return 0;
    if(root->data<min || root->data>max) return 0;
    return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);
}
int isBST(struct node *root){
    return isBSTUtil(root,INT_MIN,INT_MAX);
}
int main(){
    int n;
    scanf("%d",&n);
    struct node *root=NULL;
    int data;
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root,data);
    }
    levelOrder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    calculateSumAndNodes(root);
    int minindex,maxindex;
    scanf("%d %d",&minindex,&maxindex);
    findKthMin(root,&minindex);
    findKthMax(root,&maxindex);
    printf("\n%d\n",distanceBetweenTwoNode(root,2,7));
    root=delete(root,5);
    levelOrder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    calculateSumAndNodes(root);
    if(isBST(root)){
        printf("The Given Tree is a BST");
    }else{
        printf("The Given Tree is not a BST");
    }
}