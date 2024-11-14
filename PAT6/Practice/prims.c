#include<stdio.h>
#include<limits.h>

#define MAX 100

void prim(int graph[MAX][MAX],int n){
    int visited[MAX],key[MAX],parent[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        key[i]=INT_MAX;
        parent[i]=-1;
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
            if(!visited[j] && graph[minindex][j] && graph[minindex][j]<key[j]){
                parent[j]=minindex;
                key[j]=graph[minindex][j];
            }
        }
    }
    int totalcost=0;
    for(int i=1;i<n;i++){
        printf("%d-%d = %d\n",parent[i],i,graph[parent[i]][i]);
        totalcost+=graph[parent[i]][i];
    }
    printf("Total Cost: %d\n",totalcost);
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
/*Input 1 :
5
6
0 1 4
0 2 3
1 2 2
1 3 1
2 3 4
3 4 2
Output 1 :
8
Input 2 :
4
5
0 1 2
0 2 3
1 2 1
1 3 4
2 3 5
Output 2 :
7*/