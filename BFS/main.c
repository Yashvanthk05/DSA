#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 7

typedef struct Queue{
    int matrix[max];
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
    q->matrix[++q->rear]=data;
}

int dequeue(Queue *q){
    return q->matrix[q->front++];
}

void bfs(int graph[max][max],int n,int src,int goal){
    int visited[max]={0};
    int parent[max]={-1};
    visited[src]=1;
    Queue *q=createQueue();
    enqueue(q,src);
    while(!isEmpty(q)){
        int current=dequeue(q);
        if(current==goal){
            break;
        }
        for(int i=0;i<n;i++){
            if(graph[current][i]==1 && !visited[i]){
                visited[i]=1;
                parent[i]=current;
                enqueue(q,i);
            }
        }
    }
    if(!visited[goal]){
        printf("Not Found\n");
        return;
    }
    int path[max];
    int pathlen=0;
    for(int v=goal;v!=-1;v=parent[v]){
        path[pathlen++]=v;
    }
    printf("Length from Source to the Goal Vertice: %d\n",pathlen-1);
    printf("BFS Path Traversal: ");
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the Number of Vertices: ");
    scanf("%d",&n);
    int graph[max][max];
    printf("Enter the Adjacency Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    int src,goal;
    printf("Enter the Source and Goal Vertices:\n");
    scanf("%d %d",&src,&goal);
    bfs(graph,n,src,goal);
    return 0;
}