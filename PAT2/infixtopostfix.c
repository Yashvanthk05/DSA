#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

typedef struct Stack{
    int n;
    int top;
    char *arr;
}Stack;

Stack* createstack(int n){
    if(n<0) return NULL;
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return NULL;
    s->arr=(char*)malloc(n*sizeof(char));
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

char peek(Stack *s){
    return s->arr[s->top];
}

void push(Stack *s,char c){
    if(isFull(s)){
        return;
    }
    s->arr[++(s->top)]=c;
}

char pop(Stack *s){
    if(isEmpty(s)){
        return '\0';
    }
    return s->arr[s->top--];
}

int precedence(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixtopostfix(char *infix,char *postfix){
    Stack *s=createstack(strlen(infix));
    if(!s){
        printf("Stack Memory not Allocated!!\n");
        return;
    }
    int i=0,k=0;
    char symbol;
    while((symbol=infix[i++])!='\0'){
        if(symbol=='('){
            push(s,symbol);
        }
        else if(symbol==')'){
            while(!isEmpty(s) && peek(s)!='('){
                postfix[k++]=pop(s);
            }
            pop(s);
        }
        else if(isalnum(symbol)){
            postfix[k++]=symbol;
        }
        else{
            while(!isEmpty(s) && precedence(symbol)<=precedence(peek(s))){
                postfix[k++]=pop(s);
            }
            push(s,symbol);
        }
    }
    while(!isEmpty(s)){
        postfix[k++]=pop(s);
    }
    postfix[k]='\0';
    free(s->arr);
    free(s);
}

int main(){
    char infix[100],postfix[100];
    fgets(infix,100,stdin);
    infixtopostfix(infix,postfix);
    printf("%s ",postfix);
    return 0;
}