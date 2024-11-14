#include <stdio.h>
#include <limits.h>

#define MAX_NODES 8

// Function to find the minimum cost edge from a set of nodes not yet in MST
int minKey(int key[], int inMST[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int costMatrix[MAX_NODES][MAX_NODES], int n) {
    int parent[MAX_NODES];  // Array to store the parent of each node
    int key[MAX_NODES];     // Array to store the minimum weight edge for each node
    int inMST[MAX_NODES];   // Boolean array to mark nodes already included in MST
    int totalCost = 0;
    int edgeCount = 1;

    // Initialize key values to infinity, parent and inMST arrays
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
        parent[i] = -1;
    }

    // Start from the first node (0th index)
    key[0] = 0;

    // Find MST for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = minKey(key, inMST, n);
        inMST[u] = 1;  // Add the selected vertex to the MST

        // Update the key and parent values of the adjacent vertices
        for (int v = 0; v < n; v++) {
            // costMatrix[u][v] is the weight of the edge from u to v
            // Update the key only if v is not in MST and the edge weight is smaller
            if (costMatrix[u][v] && !inMST[v] && costMatrix[u][v] < key[v]) {
                key[v] = costMatrix[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the edges of the MST and calculate the total cost
    for (int i = 1; i < n; i++) {
        printf("Edge %d:(%d %d) cost:%d\n", edgeCount++, parent[i] + 1, i + 1, costMatrix[i][parent[i]]);
        totalCost += costMatrix[i][parent[i]];
    }

    // Print the minimum cost of the MST
    printf("Minimum cost = %d\n", totalCost);
}

int main() {
    int n;

    // Read the number of cities (nodes)
    scanf("%d", &n);

    int costMatrix[MAX_NODES][MAX_NODES];

    // Read the cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Call the Prim's MST algorithm
    primMST(costMatrix, n);

    return 0;
}
