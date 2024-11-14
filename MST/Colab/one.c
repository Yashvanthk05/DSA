/*Single File Programming Question
Problem Statement



You are given a set of cities and the cost of connecting each pair of cities. Your task is to find the minimum cost to connect all the cities using Prim's Algorithm and the minimum spanning tree.



Example



Input: 

5

6

0 1 4

0 2 3

1 2 2

1 3 1

2 3 4

3 4 2



Output: 

8



Explanation:

The minimum spanning tree for this input is as follows:

City 0 is connected to City 2 at a cost of 3.

City 2 is connected to City 1 at a cost of 2.

City 1 is connected to City 3 at a cost of 1.

City 3 is connected to City 4 at a cost of 2.



The total cost of these connections is 3 + 2 + 1 +2 = 8, which is printed as the output.

Input format :
The first line of input contains an integer numCities, representing the number of cities (vertices)

The second line contains an integer numConnections, representing the number of connections (edges) between the cities.

The next numConnections lines contain three space-separated integers: source, destination, and cost, representing a connection between a city's source and destination with the given cost.

Output format :
The output prints the minimum cost required to connect all the cities.

Code constraints :
1 ≤ numCities ≤ 105

Sample test cases :
Input 1 :
5
6
0 1 4
0 2 3
1 2 2
1 3 1
2 3 4
3 4 2
Output 1 :
8
Input 2 :
4
5
0 1 2
0 2 3
1 2 1
1 3 4
2 3 5
Output 2 :
7*/

#include<stdio.h>
#include<limits.h>

#define MAX 105

void prims(int graph[MAX][MAX],int n){
    int parent[MAX],visited[MAX],key[MAX];
    for(int i=0;i<n;i++){
        parent[i]=-1;
        visited[i]=0;
        key[i]=INT_MAX;
    }
    key[0]=0;
    for(int i=0;i<n-1;i++){
        int min=INT_MAX,minindex;
        for(int j=0;j<n;j++){
            if(!visited[j] && key[j]<min){
                min=key[j];
                minindex=j;
            }
        }
        visited[minindex]=1;
        for(int j=0;j<n;j++){
            if(!visited[j] && graph[minindex][j] && graph[minindex][j]<key[j]){
                key[j]=graph[minindex][j];
                parent[j]=minindex;
            }
        }
    }
    int cost=0;
    for(int i=1;i<n;i++){
        cost+=graph[parent[i]][i];
    }
    printf("Total Cost: %d\n",cost);
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int graph[MAX][MAX];
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=graph[v][u]=w;
    }
    prims(graph,n);
}