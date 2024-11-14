#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node *root, int *arr, int i, int n) {
    if (i < n) {
        struct node *temp = createnode(arr[i]);
        root = temp;
        root->left = insert(root->left, arr, 2 * i + 1, n);
        root->right = insert(root->right, arr, 2 * i + 2, n);
    }
    return root;
}

int height(struct node *root) {
    if (root == NULL) return 0;
    else {
        int lh = height(root->left);
        int rh = height(root->right);
        return (lh > rh ? lh : rh) + 1;
    }
}

void printCurrentLevel(struct node *root, int level,int ltr) {
    if (root == NULL) return;

    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        if (ltr) {
            printCurrentLevel(root->left, level - 1, ltr);
            printCurrentLevel(root->right, level - 1, ltr);
        } else {
            printCurrentLevel(root->right, level - 1, ltr);
            printCurrentLevel(root->left, level - 1, ltr);
        }
    }
}

void levelOrder(struct node *root) {
    if (root != NULL) {
        int ltr=1;
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printCurrentLevel(root, i,ltr);
            ltr=!ltr;
        }
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    struct node *root = NULL;
    root = insert(root, arr, 0, 7);
    levelOrder(root);
    printf("\n");
    return 0;
}
