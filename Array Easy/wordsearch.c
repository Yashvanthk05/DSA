#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char S[1000];
    char T[100];
    scanf("%[^\n]s",&S);
    getchar();
    scanf("%[^\n]s",&T);
    if(strstr(S,T)){
        printf("The word %s is present",T);
    }else{
        printf("The word %s is not present",T);
    }
    return 0;
}