#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct DSQueue{
    int front;
    int rear;
    int n;
    int *arr;
}DSQueue;

DSQueue* createdsqueue(int n){
    DSQueue *q=(DSQueue*)malloc(sizeof(DSQueue));
    if(q==NULL) return NULL;
    q->arr=(int*)malloc(n*sizeof(int));
    if(q->arr==NULL){
        return NULL;
    }
    q->front=0;
    q->rear=-1;
    q->n=n;
}

void lenqueue(DSQueue *q,int num){
    if(q->rear==q->n-1){
        printf("Queue is Full\n");
        return;
    }
    q->arr[++q->rear]=num;
    printf("Last Enqueued: %d\n",q->arr[q->rear]);
}

void fdequeue(DSQueue *q){
    if(q->front>q->rear){
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Dequeued: %d\n",q->arr[q->front++]);
}

void fenqueue(DSQueue *q,int num){
    if(q->front==0){
        printf("Queue is Full\n");
        return;
    }
    q->arr[--q->front]=num;
    printf("Front Enqueued: %d\n",q->arr[q->front]);
}

void ldequeue(DSQueue *q){
    if(q->front>q->rear){
        printf("Queue is Empty\n");
        return;
    }
    printf("Last Dequeued: %d\n",q->arr[q->rear--]);
    if(q->front>q->rear){
        q->front=0;
        q->rear=-1;
    }
}

void printqueue(DSQueue *q){
    if(q->front>q->rear){
        printf("Queue is Empty\n");
        return;
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main(){
    DSQueue *q = createdsqueue(5);
    if(q==NULL){
        printf("Circular Queue Memory is not Allocated!!\n");
        return -1;
    }
    lenqueue(q, 10);
    lenqueue(q, 20);
    lenqueue(q, 30);
    lenqueue(q, 40);
    lenqueue(q, 50);

    printqueue(q);

    fdequeue(q);
    fdequeue(q);

    fenqueue(q, 5); // Test front enqueue

    printqueue(q);

    ldequeue(q); // Test rear dequeue

    printqueue(q);
    return 0;
}