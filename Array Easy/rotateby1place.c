#include<stdio.h>

int main(){
    int arr[]={10,1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    int temp=arr[0];
    for(int i=1;i<len;i++){
        arr[i-1]=arr[i];
    }
    arr[len-1]=temp;
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}