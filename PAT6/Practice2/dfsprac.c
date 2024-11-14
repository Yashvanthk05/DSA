#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 7

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;
Stack *createStack() {
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    stk->top = -1;
    return stk;
}
bool isEmpty(Stack *stk) {
    return stk->top == -1;
}
void push(Stack *stk, int data) {
    stk->items[++stk->top] = data;
}
int pop(Stack *stk) {
    return stk->items[stk->top--];
}
int DFS(int graph[MAX][MAX], int n, int src, int goal, int parent[MAX], int visited[MAX]) {
    Stack *stk = createStack();
    visited[src] = 1;
    push(stk, src);
    while (!isEmpty(stk)) {
        int current = pop(stk);
        if (current == goal) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                parent[i] = current;
                push(stk, i);
            }
        }
    }
    if (!visited[goal]) {
        printf("Path not found from %d to %d\n", src, goal);
        return -1;
    }
    int pathLen = 0;
    for (int v = goal; v != -1; v = parent[v]) {
        pathLen++;
    }
    return pathLen - 1;
}
void findMaxPath(int graph[MAX][MAX], int n, int src) {
    int maxLen = -1;
    int visited[MAX], parent[MAX];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (i != src) {
            int len = DFS(graph, n, src, i, parent, visited);
            if (len > maxLen) maxLen = len;
            for (int j = 0; j < n; j++) {
                visited[j] = 0;
            }
        }
    }
    printf("Longest Path Length from Source %d is: %d\n", src, maxLen);
}
int main() {
    int n;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0},
        {1, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 1, 1, 0}
    };
    int src;
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);
    findMaxPath(graph, n, src);
    return 0;
}
