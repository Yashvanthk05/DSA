#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX],int v,int src){
    int key[MAX],visited[MAX]={0};
    for(int i=0;i<v;i++){
        key[i]=INT_MAX;
    }
    key[0]=0;
    for(int i=0;i<v-1;i++){
        int min=INT_MAX,minindex;
        for(int j=0;j<v;j++){
            if(!visited[j] && key[j]<min){
                min=key[j];
                minindex=j;
            }
        }
        visited[minindex]=1;
        for(int j=0;j<v;j++){
            if(!visited[j] && graph[minindex][j] && key[j]!=INT_MAX && distance[minindex]+graph[minindex][j]<distance[j]){
                distance[j]=distance[minindex]+graph[minindex][j];
            }
        }
    }
    for(int i=0;i<v;i++){
        printf("%d ",distance[i]);
    }
}

int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    int graph[MAX][MAX];
    int src,dest;
    for(int i=0;i<e;i++){
        scanf("%d %d",&src,&dest);
        scanf("%d",&graph[src][dest]);
    }
    scanf("%d",&src);
    dijkstra(graph,v,src);
    return 0;
}