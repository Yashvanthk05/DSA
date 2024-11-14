#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    parent[i] = find(parent, parent[i]);
    return parent[i];
}

void sortEdges(int edges[MAX][3], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                for (int k = 0; k < 3; k++) {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
}

void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}

void kruskal(int edges[MAX][3], int v, int e) {
    int mstwgt = 0;
    int parent[MAX];
    for (int i = 0; i < v; i++) {
        parent[i] = -1;
    }

    sortEdges(edges, e);
    printf("Edges in the constructed MST:\n");
    
    for (int i = 0; i < e; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        int wgt = edges[i][2];
        int srcroot = find(parent, src);
        int destroot = find(parent, dest);
        
        if (srcroot != destroot) {
            mstwgt += wgt;
            printf("%d -- %d == %d\n", src, dest, wgt);
            unionSets(parent, srcroot, destroot);
        }
    }
    
    printf("Minimum Spanning Tree Weight: %d\n", mstwgt);
}

int main() {
    int v, e;
    int edges[MAX][3];
    scanf("%d %d", &v, &e);
    
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    
    kruskal(edges, v, e);
    return 0;
}
