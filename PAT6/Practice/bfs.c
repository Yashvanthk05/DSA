#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct Queue{
    int items[MAX];
    int front,rear;
}Queue;

Queue *createQueue(){
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
    int src,dest;
    scanf("%d %d",&src,&dest);
    int visited[MAX],parent[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    visited[src]=1;
    Queue *q=createQueue();
    enqueue(q,src);
    while(!isEmpty(q)){
        int current=dequeue(q);
        if(current==dest) break;
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                parent[i]=current;
                visited[i]=1;
                enqueue(q,i);
            }
        }
    }
    if(!visited[dest]){
        printf("Destination is Not Reached from the Source");
        return;
    }
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
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
    return 0;
}