#include<stdio.h>
#include<limits.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX],int n){
    int visited[MAX],parent[MAX],key[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
        key[i]=INT_MAX;
    }
    key[0]=0;
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
    for(int i=0;i<n;i++){
        printf("%d %d\n",i,key[i]);
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
    dijkstra(graph,n);
    return 0;
}