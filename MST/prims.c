#include<stdio.h>
#include<limits.h>

#define max 10

int minKey(int key[],int visited[],int n){
    int min=INT_MAX,minIndex;
    for(int i=0;i<n;i++){
        if(!visited[i] && key[i]<min){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void primeMst(int graph[max][max],int n){
    int key[max],visited[max],parent[max];
    for(int i=0;i<n;i++){
        visited[i]=0;
        key[i]=INT_MAX;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++){
        int k=minKey(key,visited,n);
        visited[k]=1;
        for(int j=0;j<n;j++){
            if(graph[k][j] && !visited[j] && graph[k][j]<key[j]){
                parent[j]=k;
                key[j]=graph[k][j];
            }
        }
    }
    printf("Edge \tWeight\n");
    for(int i=1;i<n;i++){
        printf("%d - %d \t%d\n",parent[i],i,graph[parent[i]][i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int graph[max][max];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    primeMst(graph,n);
    return 0;
}