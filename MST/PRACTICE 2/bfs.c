#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct Queue{
    int items[MAX];
    int front,rear;
}Queue;

Queue* createQueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=0,q->rear=-1;
    return q;
}

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
    int visited[MAX],parent[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    int src,dest;
    scanf("%d %d",&src,&dest);
    Queue *q=createQueue();
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
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=graph[v][u]=w;
    }

    return 0;
}