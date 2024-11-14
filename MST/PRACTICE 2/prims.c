#include<stdio.h>
#include<limits.h>

#define MAX 100

void prim(int graph[MAX][MAX],int n){
    int visited[MAX],parent[MAX],key[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
        key[i]=INT_MAX;
    }
    int src,dest;
    scanf("%d %d",&src,&dest);
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
            if(!visited[j] && graph[minindex][j] && graph[minindex][j]<key[j]){
                parent[j]=minindex;
                key[j]=graph[minindex][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(parent[i]!=-1) printf("%d - %d = %d\n",parent[i],i,graph[parent[i]][i]);
    }
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int graph[MAX][MAX]={0};
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=graph[v][u]=w;
    }
    prim(graph,n);
    return 0;
}