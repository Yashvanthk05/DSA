#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int n;
    int top;
    int *arr;
}stack;

void init(stack *s){
    printf("Enter the Size of the Stack: ");
    scanf("%d",&s->n);
    s->top=-1;
    s->arr=(int*)malloc(s->n*sizeof(int));
}

bool isEmpty(stack *s){
    return s->top==-1;
}

bool isFull(stack *s){
    return s->top==s->n-1;
}

int peek(stack *s){
    return s->arr[s->top];
}

void push(stack *s,int num){
    if(isFull(s)){
        printf("Overflow!!");
        return;
    }
    s->arr[++s->top]=num;
    printf("Pushed %d!!\n",num);
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Underflow!!");
        return -1;
    }
    return s->arr[s->top--];
}

int main(){
    stack s;
    init(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    printf("%d %d %d ",pop(&s),pop(&s),pop(&s));
    return 0;
}