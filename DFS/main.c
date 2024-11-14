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

void DFS(int graph[max][max],int n,int src,int goal){
    int visited[max]={0};
    int parent[max];
    for(int i=0;i<max;i++) parent[i]=-1;
    Stack *stk=createStack();
    visited[src]=1;
    push(stk,src);
    while(!isEmpty(stk)){
        int current=pop(stk);
        if(current==goal){
            break;
        }
        for(int i=0;i<n;i++){
            if(graph[current][i]==1 && !visited[i]){
                visited[i]=1;
                parent[i]=current;
                push(stk,i);
            }
        }
    }
    if(!visited[goal]){
        printf("Not Found\n");
        return;
    }
    int path[max];
    int pathlen=0;
    for(int v=goal;v!=-1;v=parent[v]){
        path[pathlen++]=v;
    }
    printf("Length from Source to Goal Vertex: %d\n",pathlen-1);
    printf("Path Traversal: ");
    for(int i=pathlen-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the Number of Vertices: ");
    scanf("%d",&n);
    int graph[max][max] = {
                            {0, 1, 1, 0, 0, 0},
                            {1, 0, 1, 1, 1, 0},
                            {1, 1, 0, 0, 1, 1},
                            {0, 1, 0, 0, 0, 1},
                            {0, 1, 1, 0, 0, 1},
                            {0, 0, 1, 1, 1, 0}
                        };

    
    // printf("Enter the Adjacency Matrix:\n");
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         scanf("%d",&graph[i][j]);
    //     }
    // }
    int src,goal;
    printf("Enter the Goal and Source Vertex: ");
    scanf("%d %d",&src,&goal);
    DFS(graph,n,src,goal);
    return 0;
}