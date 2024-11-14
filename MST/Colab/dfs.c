/*Problem Statement



Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. The graph is in the form of an adjacency list where adj[i] contains all the nodes ith node is having edge with.

Input format :
The first line of the input consists of an integer V, representing the number of vertices.

The second line of the input consists of an integer E, representing the number of edges.

The next E lines of input consist of a pair of integers representing the start and end nodes for each m edge.

Output format :
The output prints "1" if the graph contains a cycle.

Otherwise, the output prints "0" if the graph does not contain a cycle.



Refer to the sample output for the formatting specifications.

Sample test cases :
Input 1 :
5
5
1 0
0 2
2 1
0 3
3 4
Output 1 :
1
Input 2 :
3
2
0 1
1 2
Output 2 :
0*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct Stack{
    int top;
    int items[MAX];
}Stack;

bool isEmpty(Stack *stk){
    return stk->top==-1;
}

void push(Stack *stk,int data){
    stk->items[++stk->top]=data;
}

int pop(Stack *stk){
    return stk->items[stk->top--];
}

bool dfsCycleDetection(int graph[MAX][MAX],int n){
    int visited[MAX]={0};
    int parent[MAX]={-1};
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            Stack *stk=(Stack*)malloc(Stack);
            stk->top=-1;
            push(stk,i);
            while(!isEmpty(stk)){
                int current=stk.pop();
                for(int j=0;j<n;j++){
                    if(graph[cuurent][j]){
                        if(visited[j] && parent[current]!=j){
                            free(stk);
                            return true;
                        }else if(!visited[j]){
                            visited[j]=1;
                            parent[j]=current;
                            push(stk,j);
                        }
                    }
                }
            }
        free(stk);
        }
    }
    return false;
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
    bool flag = dfsCycleDetection(graph,n);
    if(flag) printf("Cycle is formed\n");
    else printf("No cycle is Formed");
    return 0;
}