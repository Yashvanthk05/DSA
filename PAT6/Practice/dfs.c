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

void dfs(int graph[MAX][MAX],int n){
    int src,dest;
    scanf("%d %d",&src,&dest);
    int visited[MAX],parent[MAX];
    for(int i=0;i<n;i++){
        visited[i]=0;
        parent[i]=-1;
    }
    visited[src]=1;
    Stack *stk=createStack();
    push(stk,src);
    while(!isEmpty(stk)){
        int current=pop(stk);
        if(current==dest){
            break;
        }
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                parent[i]=current;
                visited[i]=1;
                push(stk,i);
            }
        }
    }
    if(!visited[dest]){
        printf("Destination can't be Reached");
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
    int n;
    scanf("%d",&n);
    int graph[MAX][MAX]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    dfs(graph,n);
}