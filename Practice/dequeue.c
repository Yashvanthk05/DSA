#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef struct de{
    int front;
    int rear;
    int n;
    int *arr;
}de;

de* createde(int n){
    de *q=(de*)malloc(sizeof(de));
    if(q==NULL) return NULL;
    q->arr=(int*)malloc(n*sizeof(int));
    if(q->arr==NULL){
        free(q);
        return NULL;
    }
    q->n=n;
    q->front=-1;
    q->rear=-1;
    return q;
}

void fenqueue(de *q,int num){
    if((q->front==0&&q->rear==q->n-1)||(q->front==q->rear+1)){
        printf("Queue is Full\n");
        return;
    }else if(q->front==-1 && q->rear==-1){
        q->front=q->rear=0;
    }else if(q->front=0){
        q->front=q->n-1;
    }
    else{
        q->front--;
    }
    
    printf("Front Enqueued: %d\n",q->arr[q->front]);
}

void lenqueue(de *q,int num){
    if((q->front==0&&q->rear==q->n-1)||(q->front==q->rear+1)){
        printf("Queue is Full\n");
        return;
    }else if(q->front==-1 && q->rear==-1){
        q->rear=0;
    }else if(q->rear==q->n-1){
        q->rear=0;
    }else{
        q->rear++;
    }
    printf("Last Enqueued: %d\n",q->arr[q->rear]);
}

void fdequeue(de *q){
    if(q->front==-1&&q->rear==-1){
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Dequeued: %d\n",q->arr[q->front]);
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else if(q->front==q->n-1){
        q->front=0;
    }else{
        q->front++;
    }
}

void ldequeue(de *q){
    if(q->front==-1&&q->rear==-1){
        printf("Queue is Empty\n");
        return;
    }
    printf("Last Dequeued: %d\n",q->arr[q->rear]);
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else if(q->rear==0){
        q->rear=q->n-1;
    }else{
        q->rear--;
    }
}

int main(){
    de *q=createde(2);
    lenqueue(q,1);
    lenqueue(q,2);
    fdequeue(q);
    return 0;
}