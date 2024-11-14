#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct Stack{
    int top;
    int n;
    int *arr;
}Stack;

Stack* createstack(int n){
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

void push(Stack *s,int num){
    if(isFull(s)) return;
    s->arr[++s->top]=num;
}

int pop(Stack *s){
    if(isEmpty(s)) return -1;
    return s->arr[s->top--];
}

int evaluatePostfix(char *postfix){
    Stack *s=createstack(strlen(postfix));
    if(s==NULL) return -1;
    int i=0;
    char symbol;
    while((symbol=postfix[i++])!='\0'){
        if(isdigit(symbol)){
            push(s,symbol-'0');
        }else if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'){
            int val2=pop(s);
            int val1=pop(s);
            switch(symbol){
                case '+':
                    push(s,val1+val2);
                    break;
                case '-':
                    push(s,val1-val2);
                    break;
                case '*':
                    push(s,val1*val2);
                    break;
                case '/': 
                    push(s,val1/val2);
                    break;
            }
        }
    }
    return pop(s);
}

int main(){
    char postfix[100];
    fgets(postfix,100,stdin);
    postfix[strcspn(postfix,"\n")]='\0';
    printf("Evaluation of Posfix: %d",evaluatePostfix(postfix));
    return 0;
}