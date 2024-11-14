#include<stdio.h>

int main(){
    char name[9] = "yashvanth";
    int hash[26] = {0};
    for(int i=0;i<9;i++){
        hash[name[i]-97]++;
    }
    printf("Duplicate Characters: \n");
    for(int i=0;i<26;i++){
        if(hash[i]>1){
            printf("%c ",(i+97));
        }
    }
    return 0;
}