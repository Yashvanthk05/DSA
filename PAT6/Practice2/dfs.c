#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define MAX 100

typedef struct Stack{
    int top;
    int items[MAX];
}Stack;

bool isEmpty(Stack *stk){
    return stk->top==-1;
}

void push(Stack *stk,int data){
    stk->items[++stk->top]=data;
}

int pop(Stack *stk){
    return stk->items[stk->top--];
}

void dfs(int graph[MAX][MAX],int n){
    int src,dest;
    scanf("%d %d",&src,&dest);
    int visited[MAX]={0},parent[MAX]={-1};
    Stack *stk = (Stack*)malloc(sizeof(Stack));
    visited[src]=1;
    push(stk,src);
    while(!isEmpty(stk)){
        int current=pop(stk);
        printf("%d ",current);
        if(current==dest) break;
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                visited[i]=1;
                parent[i]=current;
                push(stk,i);
            }
        }
    }
    printf("\n");
    for(int i=1;i<n;i++){
        printf("%d - %d == %d\n",parent[i],i,graph[parent[i]][i]);
    }
    printf("\n");
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
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
    dfs(graph,n);
    return 0;
}