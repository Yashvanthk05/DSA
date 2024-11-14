/*Single File Programming Question
Problem Statement



Given an adjacency matrix representation of a graph, compute the shortest path from a source vertex to a goal vertex using breadth-first search.



In the case of a tie, a smaller indexed vertex should be preferred to a larger one.



Example



Input:

5

0 1 1 0 0 

1 0 1 0 0 

1 1 0 1 0

0 0 1 0 1

0 0 0 1 0

0 4

Output:

3

0 2 3 4

Explanation:

The program outputs the length of the path, which is 3. It then prints the vertices in the path in order, starting from the starting vertex and ending at the ending vertex. The shortest path from the starting vertex to the ending vertex is of length 3 and includes vertices 0 (starting vertex), 2, 3, and 4 (ending vertex).

Input format :
The first line of input is N, the number of vertices in the graph.

Then N lines of inputs have N integers each, separated by a space, denoting the adjacency matrix.

The last line of input is the index of the source and goal separated by space; the indexing starts from 0.

Output format :
The first line of output is the length of the shortest path from the source to the goal vertex.

The second line is the path from the source to the goal (including both the source and goal).

Print "Not found" for an invalid index of the source and the goal is given.



Refer to the sample output for formatting specifications.

Code constraints :
2 ≤ N ≤ 7

0 ≤ source, goal < N

Sample test cases :
Input 1 :
5
0 1 1 0 0 
1 0 1 0 0 
1 1 0 1 0
0 0 1 0 1
0 0 0 1 0
0 4
Output 1 :
3
0 2 3 4
Input 2 :
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
0 4
Output 2 :
Not found*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct Queue{
    int front,rear;
    int items[MAX];
}Queue;

bool isEmpty(Queue *q){
    return q->front>q->rear;
}

void enqueue(Queue *q,int data){
    q->items[++q->rear]=data;
}

int dequeue(Queue *q){
    return q->items[q->front++];
}

void bfs(int graph[MAX][MAX],int n){
    int src,dest;
    scanf("%d %d",&src,&dest);
    int parent[MAX],visited[MAX];
    for(int i=0;i<n;i++){
        parent[i]=-1;
        visited[i]=0;
    }
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=0,q->rear=-1;
    enqueue(q,src);
    visited[src]=1;
    while(!isEmpty(q)){
        int current=dequeue(q);
        if(current==dest) break;
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                visited[i]=1;
                parent[i]=current;
                enqueue(q,i);
            }
        }
    }
    if(!visited[dest]){
        printf("Not Found\n");
        return;
    }
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    printf("%d\n",pathlen-1);
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    int graph[MAX][MAX]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    bfs(graph,n);
}