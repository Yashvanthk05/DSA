#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char* data;
    struct node *left,*right;
    int count;
};

struct node *createnode(char *data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    newnode->count = 1;  // Initialize count to 1
    return newnode;
}

struct node *insert(struct node *root, char data[], int *maxCount, char *maxWord){
    if(root == NULL) return createnode(data);
    int c = strcmp(data, root->data);
    if(c < 0){
        root->left = insert(root->left, data, maxCount, maxWord);
    } else if(c > 0){
        root->right = insert(root->right, data, maxCount, maxWord);
    } else if(c == 0){
        root->count++;
        if(root->count > *maxCount){
            *maxCount = root->count;
            strcpy(maxWord, root->data);  // Copy string to maxWord
        }
    }
    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char data[100];
    struct node *root = NULL;
    char maxWord[100];
    int maxCount = 0;
    for(int i = 0; i < n; i++){
        scanf("%s", data);  // Pass data array directly
        root = insert(root, data, &maxCount, maxWord);
    }
    inorder(root);
    printf("Max Word: %s, Count: %d\n", maxWord, maxCount);
}
