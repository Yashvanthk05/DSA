#include<stdio.h>
#include<limits.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX],int n){
    int src,dest;
    scanf("%d %d",&src,&dest);
    int visited[MAX],parent[MAX],key[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
        key[i]=INT_MAX;
    }
    key[src]=0;
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
            if(!visited[j] && graph[minindex][j] && (key[minindex]+graph[minindex][j])<key[j]){
                key[j]=key[minindex]+graph[minindex][j];
                parent[j]=minindex;
            }
        }
    }
    if(key[dest]==INT_MAX){
        printf("No Destination Found\n");
        return;
    }
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    printf("Shortest path length: %d\nPath: ",key[dest]);
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("\n");
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int graph[MAX][MAX];
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v]=graph[v][u]=1;
    }
    dijkstra(graph,n);
    return 0;
}