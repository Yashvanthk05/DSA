#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
    int parent[MAX],visited[MAX];
    for(int i=0;i<n;i++){
        parent[i]=-1;
        visited[i]=0;
    }
    Stack *stk=(Stack*)malloc(sizeof(Stack));
    stk->top=-1;
    push(stk,0);
    visited[0]=1;
    while(!isEmpty(stk)){
        int current=pop(stk);
        printf("%d\n",current);
        for(int i=0;i<n;i++){
            if(!visited[i] && graph[current][i]){
                visited[i]=1;
                parent[i]=current;
                push(stk,i);
            }
        }
    }
}

int main(){
    int n;
    int graph[MAX][MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    dfs(graph,n);
    return 0;
}