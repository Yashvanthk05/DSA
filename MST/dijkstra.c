#include<stdio.h>
#include<limits.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX],int n,int src){
    int distance[MAX],visited[MAX];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        visited[i]=0;
    }
    distance[src]=0;
    for(int i=0;i<n-1;i++){
        int minDis=INT_MAX,minindex;
        for(int v=0;v<n;v++){
            if(!visited[v] && distance[v]<minDis){
                minDis=distance[v];
                minindex=v;
            }
        }
        visited[minindex]=1;
        for(int v=0;v<n;v++){
            if(!visited[v] && graph[minindex][v] && distance[minindex]!=INT_MAX && distance[minindex]+graph[minindex][v]<distance[v]){
                distance[v]=distance[minindex]+graph[minindex][v];
            }
        }
    }
    printf("Vertices Distance from %d\n",src);
    for(int i=0;i<n;i++){
        printf("%d - %d = %d\n",src,i,dista)
    }
}

int main(){
    int n:
    scanf("%d",&n);
    int graph[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    int src;
    scanf("%d",&src);
    dijkstra(graph,v,src);
    return 0;
}