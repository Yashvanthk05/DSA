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
    int visited[MAX],parent[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=0,q->rear=-1;
    enqueue(q,0);
    visited[0]=1;
    while(!isEmpty(q)){
        int current=dequeue(q);
        printf("%d\n",current);
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
    int n;
    int graph[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d %d",&graph[i][j],&graph[i][j]);
        }
    }
    bfs(graph,n);
    return 0;
}