#include <stdio.h>

int findHeight(int parent[], int n) {
    int height[n];
    for (int i = 0; i < n; i++) {
        height[i] = -1;
    }
    
    int maxHeight = 0;

    for (int i = 0; i < n; i++) {
        int currentHeight = 0;
        int node = i;

        while (node != -1 && height[node] == -1) {
            currentHeight++;
            node = parent[node];
        }

        if (node != -1) {
            currentHeight += height[node];
        }

        height[i] = currentHeight;
        if (currentHeight > maxHeight) {
            maxHeight = currentHeight;
        }
    }

    return maxHeight-1;
}

int main() {
    int n;
    scanf("%d", &n);

    int parent[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
    }

    int treeHeight = findHeight(parent, n);
    printf("%d\n", treeHeight);

    return 0;
}