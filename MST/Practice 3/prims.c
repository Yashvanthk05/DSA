#include<stdio.h>
#include<limits.h>

#define MAX 100

void prims(int graph[MAX][MAX],int n){
    int visited[MAX],parent[MAX],key[MAX];
    for(int i=0;i<n;i++){
        parent[i]=-1;
        visited[i]=0;
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
            if(!visited[i] && graph[minindex][j] && graph[minindex][j]<key[j]){
                parent[j]=minindex;
                key[j]=graph[minindex][j];
            }
        }
    }
    for(int i=1;i<n;i++){
        printf("%d %d = %d\n",parent[i],i,graph[parent[i]][i]);
    }
}

int main(){
    int n;
    int graph[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    return 0;
}