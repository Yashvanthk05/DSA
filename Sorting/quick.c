#include<stdio.h>

int swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<=j){
        while(arr[i]<=pivot && i<=high){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quick(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quick(arr,low,pi);
        quick(arr,pi+1,high);
    }
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    quick(arr,0,n-1);
    printarr(arr,n);
    return 0;
}