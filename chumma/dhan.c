#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int flag=-1;
    for(int i=0;i<n;i++){
        for(int j=i+1;i<n;i++){
            flag=-1;
            if(arr[i]==arr[j]){
                flag=0;
            }
        }
        if(flag==-1){
            printf("%d",arr[i]);
            break;
        }
    }
    if(flag!=-1){
        printf("%d",-1);
    }
    return 0;
}