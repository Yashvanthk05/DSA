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
    int src;
    scanf("%d %d",&src);
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
        printf("%d ",current);
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                visited[i]=1;
                parent[i]=current;
                enqueue(q,i);
            }
        }
    }
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
    bfs(graph,n);
}