#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define max 7

typedef struct Stack{
    int items[max];
    int top;
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

bool dfs(int graph[max][max],int n,int src,int visited[],int parent){
    visited[src]=1;
    for(int i=0;i<n;i++){
        if(graph[src][i]==1){
            if(!visited[i]){
                if(dfs(graph,n,i,visited,src)){
                    return true;
                }
            }
        }else if(i!=parent){
            return true;
        }
    }
    return false;
}

bool hasCycle(int graph[max][max],int n){
    int visited[max]={0};
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(graph,n,i,visited,-1)){
                return true;
            }
        }
    }
    return false;
}


int main(){
    return 0;
}