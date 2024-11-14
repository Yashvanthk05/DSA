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
    if(q==NULL){
        return NULL;
    }
    q->arr=(int*)malloc(n*sizeof(int));
    if(q->arr==NULL){
        free(q);
        return NULL;
    }
    q->front=-1;
    q->rear=-1;
    q->n=n;
    return q;
}

bool isEmpty(cq *q){
    return q->front==-1;
}

bool isFull(cq *q){
    return (q->rear+1)%(q->n)==q->front;
}

void enqueue(cq *q,int num){
    if(isFull(q)){
        printf("Queue is Full\n");
        return;
    }
    else if(isEmpty(q)){
        q->front=q->rear=0;
    }else{
        q->rear=(q->rear+1)%(q->n);
    }
    q->arr[q->rear]=num;
    printf("Enqueued: %d\n",q->arr[q->rear]);
}

void dequeue(cq *q){
    if(isEmpty(q)){
        printf("Queue is Empty!!\n");
        return;
    }
    printf("Dequeued: %d\n",q->arr[q->front]);
    else if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
        q->front=(q->front+1)%(q->n);
    }
}

void display(cq *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    else{
        int i=q->front;
        while(i!=q->rear){
            printf("%d ",q->arr[i]);
            i=(i+1)%(q->n);
        }
        printf("%d\n",q->arr[q->rear]);
    }
}
void peek(cq *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    else{
        printf("Top of the Queue: %d\n",q->arr[q->front]);
    }
}

int main(){
    cq *q=createcq(4);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    display(q);
    dequeue(q);
    peek(q);
    display(q);
    return 0;
}