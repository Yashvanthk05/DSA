#include<stdio.h>
#include<limits.h>

#define MAX 100

void prim(int graph[MAX][MAX],int v){
    int visited[MAX]={0};
    int key[MAX],parent[MAX];
    for(int i=0;i<v;i++){
        key[i]=INT_MAX;
    }
    key[0]=0;
    parent[0]=-1;
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
            if(!visited[j] && graph[minindex][j] && graph[minindex][j]<key[j]){
                parent[j]=minindex;
                key[j]=graph[minindex][j];
            }
        }
    }
    printf("Edges\tWeight\n");
    for(int i=1;i<v;i++){
        printf("%d--%d==%d\n",parent[i],i,graph[parent[i]][i]);
    }
}

int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    int graph[MAX][MAX]={0};
    int src,dest;
    for(int i=0;i<e;i++){
        scanf("%d %d",&src,&dest);
        scanf("%d",&graph[src][dest]);
        graph[dest][src]=graph[src][dest];
    }
    prim(graph,v);
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