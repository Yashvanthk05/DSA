#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}

int bs(int arr[],int n,int target){
    int low=0;
    int high = n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    int arr[]={10,2,4,7,3,6,9,1,5,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    qsort(arr,n,sizeof(arr[0]),compare);

    int target;
    printf("Enter the Target: ");
    scanf("%d",&target);
    int flag=bs(arr,n,target);
    if(flag==-1){
        printf("Element Not found");
    }else{
        printf("Element Found");
    }
    return 0;
}