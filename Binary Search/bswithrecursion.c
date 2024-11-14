#include<stdio.h>

int bs(int arr[],int low,int high,int target){
    if(low<=high){
        int mid = low + ((high-low)/2);
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) bs(arr,low,mid-1,target);
        else bs(arr,mid+1,high,target);
    }
    else return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int target;
    printf("Enter the Target: ");
    scanf("%d",&target);
    int n=sizeof(arr)/sizeof(arr[0]);
    int value = bs(arr,0,n-1,target);
    if(value==-1) printf("Element not Found");
    else printf("Element found at %d",value);
    return 0;
}