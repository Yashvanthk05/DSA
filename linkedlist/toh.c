#include<stdio.h>

int toh(int n,char A,char C,char B){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",A,C);
        return 1;
    }
    int m1=toh(n-1,A,B,C);
    printf("Move disk %d from %c to %c\n",n,A,C);
    int m2=toh(n-1,B,C,A);
    return m1+1+m2;
}
int main(){
    int n=3;
    printf("No of disk to be Moved: %d\n",toh(n,'A','C','B'));
    return  0;
}