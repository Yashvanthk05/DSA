#include<stdio.h>
#include<limits.h>

#define MAX 

void dijkstra(int graph[MAX][MAX],int n){
    int src;
    scanf("%d",&src);
    int visited[MAX],key[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        key[i]=INT_MAX;
    }
    visited[src]=1;
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
            if(!visited[j] && graph[minindex][j] && key[j]!=INT_MAX && key[minindex]+graph[minindex][j]<key[j]){
                key[j]=key[minindex]+graph[minindex][j];
            }
        }
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
    return 0;
}