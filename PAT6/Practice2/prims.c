#include<stdio.h>
#include<limits.h>

#define MAX 10

void prims(int graph[MAX][MAX],int n){
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
            if(!visited[j] && key[j]<minindex){
                min=key[j];
                minindex=j;
            }
        }
        visited[minindex]=1;
        for(int j=0;j<n;j++){
            if(!ivisited[j] && graph[minindex][j]<key[j]){
                key[j]=graph[minindex][j];
                parent[j]=minindex;
            }
        }
    }
    for(int i=1;i<n;i++){
        printf("%d-%d == %d\n",parent[i],i,graph[parent[i]][i]);
    }
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

}