#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef struct stack{
    int n;
    char *arr;
    int top;
}stack;

void init(stack *s){
    printf("Enter the Maximum of the Stack: ");
    scanf("%d",&s->n);
    s->top=-1;
    s->arr=(char*)malloc(s->n*sizeof(char));
}

bool isEmpty(stack *s){
    return s->top==-1;
}

bool isFull(stack *s){
    return s->top==s->n;
}

char peek(stack *s){
    return s->arr[s->top];
}

void push(stack *s,char c){
    if(isFull(s)){
        return;
    }
    s->arr[++s->top]=c;
}

char pop(stack *s){
    if(isEmpty(s)){
        return '';
    }
    return s->arr[s->top--];
}

char peek(stack *s){
    return s->arr[s->top];
}

char* reverse(char *exp){
    int n=strlen(exp);
    for(int i=0;i<(n/2);i++){
        char temp=exp[n-i-1];
        exp[n-i-1]=exp[i];
        exp[i]=temp;
    }
    return exp;
}

bool isOperator(char c){
    return c=='+' || c=='-' || c=='/' || c=='*';
}

int precedence(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            return -1;
            break;
    }
}
void infixtoprefix(char *infix,char *prefix){
    int n=strlen(infix)
    char* postfix=reverse(prefix);
    int j=0;
    char res[n];
    stack s
    init(&s);
    for(int i=0;i<n;i++){
        char c=arr[i];
        if(isalnum(c)){
            res[j++]=c;
        }
        else if(c==")"){
            push(s,c);
        }
        else if(c=="("){
            while(!isEmpty(s) && c!=')'){
                res[j++]=pop(s);
            }
            pop(s);
        }
        else if(isOperator(c)){
            while(!isEmpty(s) && precendence(c)<precedence(peek(s))){
                res[j++]=pop(s);
            }
            push(s,c);
        }
    }
    while(!isEmpty(s)){
        res[j++]=pop(s);
    }
    prefix=reverse(res);
}

int main(){
    char *infix;
    scanf("%s",&infix);
    char *prefix;
    infixtoprefix(infix,prefix);
    printf("%s",prefix);
}