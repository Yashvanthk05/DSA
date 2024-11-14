#include<stdio.h>
#include<limits.h>

#define MAX 100

int find(int parent[],int i){
    if(parent[i]==i){
        return i;
    }
    parent[i]=find(parent,parent[i]);
    return parent[i];
}

void union(int parent[],int rank[],int u,int v){
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

void kruskal(int edges[MAX][3],int n){
    int mstwgt=0;
    int parent[MAX],rank[MAX];
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
    sortEdges(edges,e);`
    for(int i=0;i<e;i++){
        int src=edges[i][0];
        int dest=edges[i][1];
        int wgt=edges[i][2];
        int srcroot=find(parent,src);
        int destroot=find(parent,dest);
        if(srcroot!=destroot){
            mstwgt+=wgt;
            printf("%d - %d = %d\n",src,des,wgt);
            union(parent,rank,srcroot,destroot);
        }
    }
}

int main(){
    int n,e;
    scanf("%d %d",&n,&e);
    int graph[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    return 0;
}