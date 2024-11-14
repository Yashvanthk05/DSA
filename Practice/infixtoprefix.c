#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef struct Stack{
    int top;
    int n;
    char *arr;
}Stack;

Stack* createstack(int n){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL){
        return NULL;
    }
    s->arr=(char*)malloc(n*sizeof(char));
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

void push(Stack *s,char c){
    if(isFull(s)){
        return;
    }
    s->arr[++s->top]=c;
}

char pop(Stack *s){
    if(isEmpty(s)) return '\0';
    return s->arr[s->top--];
}

char peek(Stack *s){
    return s->arr[s->top];
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
            return -1;
    }
}

void reverse(char *exp){
    int n=strlen(exp);
    for(int i=0;i<(n/2);i++){
        char temp=exp[i];
        exp[i]=exp[n-i-1];
        exp[n-i-1]=temp;
    }
}

bool isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

void infixtoprefix(char* infix,char* postfix){
    Stack *s=createstack(strlen(infix));
    if(s==NULL) return;
    reverse(infix);
    int i=0,k=0;
    char symbol;
    while((symbol=infix[i++])!='\0'){
        if(symbol==')'){
            push(s,symbol);
        }
        else if(symbol=='('){
            while(!isEmpty(s) && peek(s)!=')'){
                postfix[k++]=pop(s);
            }
            pop(s);
        }
        else if(isalnum(symbol)){
            postfix[k++]=symbol;
        }
        else if(isOperator(symbol)){
            while(!isEmpty(s) && precedence(symbol)<precedence(peek(s))){
                postfix[k++]=pop(s);
            }
            push(s,symbol);
        }
    }
    while(!isEmpty(s)){
        postfix[k++]=pop(s);
    }
    postfix[k]='\0';
    reverse(postfix);
}

int main(){
    char infix[100],prefix[100];
    fgets(infix,100,stdin);
    infix[strcspn(infix,"\n")]='\0';
    infixtoprefix(infix,prefix);
    printf("%s",prefix);
    return 0;
}