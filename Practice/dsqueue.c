#include<stdio.h>
#include<stdlib.h>

typedef struct DSQueue{
    int front;
    int rear;
    int *arr;
    int n;
}DSQueue;

DSQueue* createdsqueue(int n){
    DSQueue *q=(DSQueue*)malloc(sizeof(DSQueue));
    if(q==NULL)return NULL;
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

void lenqueue(DSQueue *q,int num){
    if(q->rear==q->n-1){
        printf("Queue is Full\n");
        return;
    }
    q->arr[++q->rear]=num;
    if(s->front==-1){
        q->front=0;
    }
    printf("Last Enqueued: %d\n",q->arr[q->rear]);
}

void fdequeue(DSQueue *q){
    if(q->front>q->rear || q->front==-1){
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Dequeued: %d\n",q->arr[q->front++]);
    if(q->front>q->rear){
        q->front=q->rear=-1;
    }
}

void fenqueue(DSQueue *q,int num){
    if(q->front==0){
        printf("Queue is Full\n");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=-1;
    }
    for(int i=q->rear;i>=q->front;i++){
        q->arr[i+1]=q->arr[i];
    }
    q->arr[++q->front]=num;
    printf("Front Enqueued: %d\n",q->arr[q->front]);
}

void ldequeue(DSQueue *q,int num){
    if(q->front>q->rear){
        printf("Queue is Empty\n");
        q->front=0;
        q->rear=-1;
        return;
    }
    printf("Last Dequeued: %d\n",q->arr[q->rear++]);
}

int main(){
    DSQueue *q=createdsqueue(5);

    return 0;
}