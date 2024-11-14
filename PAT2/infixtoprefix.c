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
    if(n<0) return NULL;
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return NULL;
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

char peek(Stack *s){
    return s->arr[s->top];
}

void push(Stack *s,char c){
    if(isFull(s)) return;
    s->arr[++s->top]=c;
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

void reverse(char* exp){
    int n = strlen(exp);
    for(int i = 0; i < n/2; i++){
        char temp = exp[i];
        exp[i] = exp[n-i-1];
        exp[n-i-1] = temp;
    }
}

void infixtoprefix(char *infix, char *prefix){
    Stack *s = createstack(strlen(infix));
    if(s == NULL){
        printf("Stack Memory is not allocated!\n");
        return;
    }
    int i = 0, k = 0;
    char symbol;
    reverse(infix);
    while((symbol = infix[i++]) != '\0'){
        if(symbol == '\n') continue;
        if(isalnum(symbol)){
            prefix[k++] = symbol;
        }
        else if(symbol == ')'){
            push(s, symbol);
        }
        else if(symbol == '('){
            while(!isEmpty(s) && peek(s) != ')'){
                prefix[k++] = pop(s);
            }
            pop(s);
        }
        else{
            while(!isEmpty(s) && precedence(symbol) <= precedence(peek(s))){
                prefix[k++] = pop(s);
            }
            push(s, symbol);
        }
    }
    while(!isEmpty(s)){
        prefix[k++] = pop(s);
    }
    prefix[k] = '\0';
    reverse(prefix);
}

int main(){
    char infix[100], prefix[100];
    fgets(infix, 100, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixtoprefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
