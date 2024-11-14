#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct cq{
    int front;
    int rear;
    int n;
    int *arr;
}cq;

cq* createcq(int n){
    cq *q=(cq*)malloc(sizeof(cq));
    if(q==NULL) return NULL;
    q->arr=(int*)malloc(n*sizeof(int));
    if(q->arr==NULL) return NULL;
    q->front=-1;
    q->rear=-1;
    q->n=n;
}

bool isEmpty(cq *q){
    return q->front==-1||q->rear==-1;
}
bool isFull(cq *q){
    return (q->rear+1)%(q->n)==q->front;
}

void enqueue(cq *q,int num){
    if(isFull(q)){
        printf("Queue is Full\n");
        return;
    }
    else if(q->front==-1 && q->rear==-1){
        q->front=q->rear=0;
        q->arr[q->rear]=num;
    }
    else{
        q->rear=(q->rear+1)%(q->n);
        q->arr[q->rear]=num;
    }
    printf("Enqueued: %d\n",q->arr[q->rear]);
}

void dequeue(cq *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    else if(q->front==q->rear){
        printf("Dequeued: %d\n",q->arr[q->front]);
        q->front=q->rear=-1;
    }
    else{
        printf("Dequeued: %d\n",q->arr[q->front]);
        q->front=(q->front+1)%(q->n);
    }
}

int main(){
    cq *q=createcq(4);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    dequeue(q);
    enqueue(q,5);
    return 0;
}