#include<stdio.h>
#include<string.h>
int main(){
    char S[1000];
    char T[100];
    scanf("%[^\n]",S);
    getchar();
    scanf("%[^\n]",T);
    if(strstr(S,T)){
        printf("The word %s is present",T);
    }else{
        printf("The word is not present");
    }
}