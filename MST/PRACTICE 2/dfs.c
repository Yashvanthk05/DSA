#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct Stack{
    int top;
    int items[MAX];
}Stack;

Stack *createStack(){
    Stack *stk=(Stack*)malloc(sizeof(Stack));
    stk->top=-1;
    return stk;
}

bool isEmpty(Stack *stk){
    return stk->top==-1;
}

void push(Stack *stk,int data){
    stk->items[++stk->top]=data;
}

int pop(Stack *stk){
    return stk->items[stk->top--];
}

bool dfsCycleDetection(int graph[MAX][MAX],int n){
    int visited[MAX]={0};
    int parent[MAX]={-1};
    for(int i=0;i<n;i++){
        if(!visited[i]){
            Stack *stk=(Stack*)malloc(sizeof(Stack));
            push(stk,i);
            visited[i]=1;
            while(!isEmpty(stk)){
                int current=pop(stk);
                for(int j=0;j<n;j++){
                    if(graph[current][j]){
                        if(visited[j] && parent[current]!=j){
                            free(stk);
                            return true;
                        }else if(!visited[j]){
                            visited[j]=1;
                            parent[j]=current;
                            push(stk,j);
                        }
                    }
                }
            }
            free(stk);
        }
    }
    return false;
}

void dfs(int graph[MAX][MAX],int n){
    int visited[MAX],parent[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    int src,dest;
    scanf("%d %d",&src,&dest);
    visited[src]=1;
    Stack *stk=(Stack*)malloc(sizeof(Stack));
    push(stk,src);
    while(!isEmpty(stk)){
        int current=pop(stk);
        if(current==dest) break;
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                visited[i]=1;
                parent[i]=current;
                push(stk,i);
            }
        }
    }
    if(!visited[dest]){
        printf("Destination is not Reached");
        return;
    }
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
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

}