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

struct node *findMin(struct node *root){
    while(root->left){
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
            struct node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,data);
        }
    }
    return root;
}

struct node *lca(struct node *root,int n1,int n2){
    if(root==NULL) return NULL;
    else if(root->data>n1 && root->data>n2){
        return lca(root->left,n1,n2);
    }else if(root->data<n1 && root->data<n2){
        return lca(root->right,n1,n2);
    }
    return root;
}

int distanceFromRoot(struct node *root,int n){
    int distance=0;
    while(root!=NULL){
        if(n<root->data){
            root=root->left;
        }else if(n>root->data){
            root=root->right;
        }else{
            return distance;
        }
        distance++;
    }
    return -1;
}

int distanceBetweenTwoNodes(struct node *root,int n1,int n2){
    struct node *ca=lca(root,n1,n2);
    int d1=distanceFromRoot(ca,n1);
    int d2=distanceFromRoot(ca,n2);
    return d1+d2;
}

void noOfNodes(struct node *root,int *count){
    if(root==NULL) return;
    (*count)++;
    noOfNodes(root->left,count);
    noOfNodes(root->right,count);
}

void nodesSum(struct node *root,int *sum){
    if(root==NULL) return;
    (*sum)+=root->data;
    nodesSum(root->left,sum);
    nodesSum(root->right,sum);
}

void calculateSumandNumber(struct node *root){
    int sum=0,count=0;
    noOfNodes(root,&count);
    nodesSum(root,&sum);
    printf("Number of Nodes: %d\n",count);
    printf("Sum of all the nodes: %d\n",sum);
}

int isBSTUtil(struct node *root,int min,int max){
    if(root==NULL) return 1;
    if(root->data<min || root->data>max) return 0;
    return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);
}

int isBST(struct node *root){
    return isBSTUtil(root,INT_MIN,INT_MAX);
}

void levelOrder2(struct node *root){
    if(root==NULL) return;
    struct node **queue = (struct node**)malloc(sizeof(struct node));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp->data%2==0) printf("%d ",temp->data);
        if(temp->left!=NULL){
            queue[rear++]=temp->left;
        }
        if(temp->right!=NULL){
            queue[rear++]=temp->right;
        }
    }
}

int main(){
    struct node *root=NULL;
    int n;
    scanf("%d",&n);
    int data;
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root=insert(root,data);
    }
    levelOrder2(root);
    
    return 0;
}