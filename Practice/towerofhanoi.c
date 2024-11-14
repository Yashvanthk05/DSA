#include<stdio.h>

int TOH(int n,char A,char C,char B){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",A,C);
        return 1;
    }
    int moves1=TOH(n-1,A,B,C);
    printf("Move disk %d from %c to %c\n",n,A,C);
    int moves2=TOH(n-1,B,C,A);
    return moves1+1+moves2;
}

int main(){
    int n=5;
    printf("No. of Moves: %d\n",TOH(n,'A','C','B'));
    return 0;
}