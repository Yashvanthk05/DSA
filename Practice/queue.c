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
    if(q==NULL) return NULL;
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
        printf("Queue is Full!\n");
        return;
    } 
    q->arr[++q->rear]=num;
    printf("Enqueued: %d\n",q->arr[q->rear]);
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        q->front=0;
        q->rear=-1;
        printf("Queue is Empty!!\n");
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
}

void peek(Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!!\n");
        return;
    }
    printf("Top of the Queue is: %d\n",q->arr[q->front]);
}

int main(){
    Queue *q=createqueue(4);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    peek(q);
    return 0;
}