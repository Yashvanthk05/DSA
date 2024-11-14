#include<stdio.h>
int main(){
    int arr[] = {10,2,4,7,3,6,9,1,5,8};
    int largest = arr[0];
    int slargest = -999999;
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++){
        if(largest<arr[i]){
            largest = arr[i];
        }
    }
    for(int i=0;i<len;i++){
        if(slargest<arr[i] && arr[i]!=largest){
            slargest = arr[i];
        }
    }
    printf("Second Largest: %d",slargest);
    return 0;
}