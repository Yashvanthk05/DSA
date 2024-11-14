#include<stdio.h>
#include<limits.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX],int n){
    int visited[MAX],parent[MAX],key[MAX];
    int src;
    scanf("%d",&src);
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
                minindex[j]=-1;
            }
        }
        visited[minindex]=1;
        for(int j=0;j<n;j++){
            if(!visited[j] && graph[minindex][j] && (graph[minindex][j]+key[minindex])<key[j]){
                key[j]=key[minindex]+graph[minindex][j];
            }
        }
    }
    printf("Cost from Source to Other Vertices:\n");
    for(int i=0;i<n;i++){
        printf("%d %d\n",i,key[i]);
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
    return 0;
}