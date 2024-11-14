#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Union-Find functions
int parent[MAX], rank[MAX];

// Find function with path compression
int find(int i) {
    if (parent[i] == -1)
        return i;
    parent[i] = find(parent[i]);  // Path compression
    return parent[i];
}

// Union function by rank
void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        // Union by rank
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

// Sort edges by weight
void sortEdges(int edges[][3], int e) {
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

// Kruskal's algorithm to find MST
void kruskal(int edges[][3], int V, int E) {
    int mst_weight = 0;
    printf("Edges in the constructed MST:\n");

    // Initialize Union-Find structure
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    // Sort edges by weight
    sortEdges(edges, E);

    int mst_edges = 0;  // Count of edges in the MST
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        // If u and v are not connected, add the edge to the MST
        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, weight);
            mst_weight += weight;
            unionSets(u, v);
            mst_edges++;

            // If we have added V-1 edges, stop
            if (mst_edges == V - 1)
                break;
        }
    }

    printf("Minimum Spanning Tree: %d\n", mst_weight);
}

int main() {
    int V, E;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Read edges: each edge is represented as (u, v, weight)
    int edges[MAX][3];  // Edge format: [source, destination, weight]
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    // Call Kruskal's algorithm to find the MST
    kruskal(edges, V, E);

    return 0;
}
