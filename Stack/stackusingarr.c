#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack{
    int capacity;
    int *arr;
    int top;
}Stack;

Stack* createstack(int capacity){
    if(capacity<=0) return NULL;
    Stack *stack=malloc(sizeof(Stack));
    if(stack==NULL) return NULL;
    stack->arr=malloc(sizeof(int)*capacity);
    if(stack->arr==NULL){
        free(stack);
        return NULL;
    }
    stack->capacity=capacity;
    stack->top=-1;
    return stack;
}

void destroystack(Stack *s){
    free(s->arr);
    free(s);
}

bool isEmpty(Stack *s){
    return s->top==-1;
}

bool isFull(Stack *s){
    return s->top==s->capacity-1;
}

bool push(Stack *s,int num){
    if(isFull(s)){
        printf("Overflow!!\n");
        return false;
    }
    s->arr[++s->top]=num;
    printf("Pushed: %d\n",s->arr[s->top]);
    return true;
}

bool pop(Stack *s){
    if(isEmpty(s)){
        printf("Underflow!!\n");
        return false;
    }
    printf("Popped: %d\n",s->arr[s->top--]);
    return true;
}

int main(){
    Stack *s=createstack(4);
    push(s,1);
    push(s,2);
    push(s,3);
    pop(s);
    push(s,4);
    pop(s);
    push(s,6);
    push(s,8);
    pop(s);
    destroystack(s);
    return 0;
}