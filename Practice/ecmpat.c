#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Queue{
    int front;
    int rear;
    int n;
    int *arr;
}Queue;

Queue* createqueue(int n){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    if(q==NULL)return NULL;
    q->arr=(int*)malloc(n*sizeof(int));
    if(q->arr==NULL){
        free(q);
        return NULL;
    }
    q->front=0;
    q->rear=-1;
    q->n=n;
    return q;
}

bool isEmpty(Queue *q){
    return q->front>q->rear;
}

bool isFull(Queue *q){
    return q->rear==q->n-1;
}

void push(Queue *q,int num){
    if(isFull(q)) return;
    bool flag=false;
    for(int i=q->front;i<=q->rear;i++){
        if(num==q->arr[i]) flag=true;
    }
    if(!flag){
        q->arr[++q->rear]=num;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int num;
    Queue *q=createqueue(n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        push(q,num);
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    return 0;
}