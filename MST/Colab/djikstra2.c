#include<stdio.h>
#include<limits.h>

#define MAX 100

void djikstra(int graph[MAX][MAX],int n){
    int src;
    scanf("%d",&src);
    int parent[MAX],visited[MAX],key[MAX];
    for(int i=0;i<n;i++){
        parent[i]=-1;
        visited[i]=0;
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
    printf("Shortest Distance from vertex %d to all vertices\n",src);
    for(int i=0;i<n;i++){
        printf("%d ",key[i]);
    }
    printf("\n");
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int graph[MAX][MAX];
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=graph[v][u]=w;
    }
    djikstra(graph,n);
    return 0;
}