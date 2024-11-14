#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

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
    int visited[MAX]={0},parent[MAX]={-1};
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front=0,q->rear=-1;
    q->items[++q->rear]=src;
    while(!isEmpty(q)){
        int current=dequeue(q);
        printf("%d ",current);
        if(current==dest) break;
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                visited[i]=1;
                parent[i]=current;
                enqueue(q,i);
            }
        }
    }
    printf("\n");
    int totalcost=0;
    for(int i=1;i<n;i++){
        printf("%d-%d == %d\n",parent[i],i,graph[parent[i]][i]);
    }
    printf("\n");
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    printf("Total Path length: %d\n",pathlen-1);
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int graph[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    bfs(graph,n);
    return 0;
}