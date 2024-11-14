/*Problem Statement



Given a network of cities represented as an unweighted graph, find the shortest path between a source city and a destination city in terms of the minimum number of roads to be traversed. Implement a program that utilizes the Dijkstra algorithm to solve this problem.



The program should take the city network, source city, and destination city as inputs, and provide the shortest path length and the sequence of cities to be visited along the path as outputs.

Input format :
The first line contains an integer n, representing the number of cities in the network.

The second line contains an integer m, representing the number of roads in the city network.

The following m lines contain pairs of integers u and v, representing a road between cities u and v.

The next line contains an integer s, representing the source city.

The last line contains an integer d, representing the destination city.

Output format :
The first line displays "Shortest path length: " followed by the shortest path length between the source and destination cities.

The second line displays "Path: " followed by the sequence of indices of the cities separated by a space, representing the shortest path from the source to the destination.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 100

0 ≤ m ≤ n * (n - 1) / 2

0 ≤ u, v < n

0 ≤ s, d < n

Sample test cases :
Input 1 :
8
10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
0 
7
Output 1 :
Shortest path length: 2
Path: 0 3 7 
Input 2 :
8
10
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
2 
6
Output 2 :
Shortest path length: 5
Path: 2 1 0 3 4 6*/

#include<stdio.h>
#include<limits.h>

#define MAX 100

void djikstra(int graph[MAX][MAX], int n) {
    int src,dest;
    scanf("%d %d",&src,&dest);
    int visited[MAX], parent[MAX], key[MAX];

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        key[i] = INT_MAX;  // Use INT_MAX to represent infinity
    }
    key[src] = 0;

    // Dijkstra's algorithm (for unweighted graph, all edges have weight 1)
    for (int i = 0; i < n - 1; i++) {
        int min = INT_MAX, minindex;
        
        // Find the unvisited node with the smallest distance
        for (int j = 0; j < n; j++) {
            if (!visited[j] && key[j] < min) {
                min = key[j];
                minindex = j;
            }
        }

        visited[minindex] = 1;

        // Update distances for neighbors
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[minindex][j] && key[minindex] + 1 < key[j]) {
                key[j] = key[minindex] + 1;
                parent[j] = minindex;
            }
        }
    }

    // If destination is not reachable
    if (key[dest] == INT_MAX) {
        printf("Destination not found\n");
        return;
    }

    // Print the shortest path length
    printf("Shortest path length: %d\n", key[dest]);

    // Retrieve the path
    int path[MAX], pathlen = 0;
    for (int i = dest; i != -1; i = parent[i]) {
        path[pathlen++] = i;
    }

    // Print the path
    printf("Path: ");
    for (int i = pathlen - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int graph[MAX][MAX]={0};
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v]=graph[v][u]=1;
    }
    djikstra(graph,n);
}