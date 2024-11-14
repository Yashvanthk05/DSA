#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct Stack{
    int top;
    int items[MAX];
}Stack;

Stack* createStack(){
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
    int parent[MAX],visited[MAX];
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
    if(!visited[dest]) printf("No such Destination\n");
    int path[MAX],pathlen=0;
    for(int i=dest;i!=-1;i=parent[i]){
        path[pathlen++]=i;
    }
    printf("DFS Length: %d\n",pathlen-1);
    printf("DFS Traversal: ");
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("\n");
}

int main(){
    return 0;
}