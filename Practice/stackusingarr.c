#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack{
    int n;
    int top;
    int *arr;
}Stack;

Stack* createstack(int n){
    Stack *s =(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return NULL;
    s->arr=(int*)malloc(sizeof(int));
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

void push(Stack *s,int num){
    if(isFull(s)){
        printf("Overflow\n");
        return;
    }
    s->arr[++s->top]=num;
    printf("Pushed: %d\n",s->arr[s->top]);
}

void pop(Stack *s){
    if(isEmpty(s)){
        printf("Underflow\n");
        return;
    }
    printf("Popped: %d\n",s->arr[s->top--]);
}

void peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
        return;
    }
    printf("Top of the Stack: %d\n",s->arr[s->top]);
}

void display(Stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty\n");
    }
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}

int main(){
    Stack *s=createstack(4);
    push(s,1);
    pop(s);
    display(s);
    peek(s);
    push(s,2);
    push(s,3);
    display(s);
    peek(s);
    return 0;
}