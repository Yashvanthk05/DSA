#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack{
    int n;
    int top;
    int *arr;
}Stack;

Stack* createstack(int n){
    if(n<0) return NULL;
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return NULL;
    s->arr=(int*)malloc(n*sizeof(int));
    if(s->arr==NULL){
        free(s);
        return NULL;
    }
    s->top=-1;
    s->n=n;
    return s;
}

bool isEmpty(Stack *s){
    return s->top==-1;
}

bool isFull(Stack *s){
    return s->top==s->n-1;
}

void peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack Empty!!\n");
        return;
    }
    printf("Top Element: %d\n",s->arr[s->top]);
}

void push(Stack *s,int num){
    if(isFull(s)){
        printf("Overflow!!\n");
        return;
    } 
    s->arr[++s->top]=num;
    printf("Pushed: %d\n",s->arr[s->top]);
}

void pop(Stack *s){
    if(isEmpty(s)){
        printf("Underflow!!\n");
        return;
    } 
    printf("Popped: %d\n",s->arr[s->top--]);
}

int main(){
    Stack *s = createstack(5);
    push(s,10);
    push(s,11);
    push(s,12);
    push(s,13);
    push(s,14);
    pop(s);
    peek(s);
    push(s,15);
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    return 0;
}