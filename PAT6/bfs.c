#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct Queue{
    int front,rear;
    int items[MAX];
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
    int src,dest;
    scanf("%d %d",&src,&dest);
    int visited[MAX]={0},parent[MAX]={-1};
    visited[src]=1;
    Queue *q=createQueue();
    enqueue(q,src);
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
        printf("No such Destination\n");
        return;
    }
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    printf("Length of BFS Traversal: %d\n",pathlen-1);
    printf("BFS Traversal: ");
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("\n");
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

