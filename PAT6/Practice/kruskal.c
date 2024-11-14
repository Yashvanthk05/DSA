#include<stdio.h>
#include<limits.h>

#define MAX 100

int find(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    parent[i]=find(parent,parent[i]);
    return parent[i];
}

void unionSets(int parent[],int rank[],int u,int v){
    u=find(parent,u);
    v=find(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[u]>rank[v]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}

void sortEdges(int edges[MAX][3],int e){
    for(int i=0;i<e-1;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j][2]>edges[j+1][2]){
                for(int k=0;k<3;k++){
                    int temp=edges[j][k];
                    edges[j][k]=edges[j+1][k];
                    edges[j+1][k]=temp;
                }
            }
        }
    }
}

void kruskal(int edges[MAX][3],int n,int e){
    int mstwgt=0;
    int parent[MAX],rank[MAX];
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    sortEdges(edges,e);
    for(int i=0;i<e;i++){
        int src=edges[i][0];
        int dest=edges[i][1];
        int wgt=edges[i][2];
        int srcroot=find(parent,src);
        int destroot=find(parent,dest);
        if(srcroot!=destroot){
            mstwgt+=wgt;
            printf("%d - %d = %d\n",src,dest,wgt);
            unionSets(parent,rank,srcroot,destroot);
        }
    }
    printf("Minimum Spanning Tree: %d\n",mstwgt);
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int edges[MAX][3];
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&edges[i][0],&edges[i][1],&edges[i][2]);
    }
    kruskal(edges,n,e);
    return 0;
}

/*Input 1 :
4
5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
Output 1 :
Edges in the constructed MST:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Spanning Tree: 25
Input 2 :
5
6
0 1 2
1 2 1
2 3 3
3 4 4
4 0 5
0 2 6
Output 2 :
Edges in the constructed MST:
1 -- 2 == 1
0 -- 1 == 2
2 -- 3 == 3
3 -- 4 == 4
Minimum Spanning Tree: 15*/