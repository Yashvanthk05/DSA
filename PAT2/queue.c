#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Queue{
    int n;
    int front;
    int rear;
    int *arr;
}Queue;

Queue* createqueue(int n){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    if(q==NULL){
        return NULL;
    }
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

void enqueue(Queue *q,int num){
    if(isFull(q)){
        printf("Queue is Full!!\n");
        return;
    }
    q->arr[++q->rear]=num;
    printf("Enqueued: %d\n",q->arr[q->rear]);
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Underflow!!\n");
        return;
    }
    printf("Dequeued: %d\n",q->arr[q->front++]);
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!!\n");
        return;
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

void peek(Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    printf("Peek of the Queue: %d\n",q->arr[q->front]);
}

int main(){
    Queue *q=createqueue(4);
    if(q==NULL){
        printf("Queue memory not allocated\n");
    }
    enqueue(q,1);
    enqueue(q,10);
    dequeue(q);
    enqueue(q,11);
    enqueue(q,12);
    enqueue(q,13);
    peek(q);
    display(q);
    return 0;
}