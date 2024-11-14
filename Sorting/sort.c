#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]) min=j;
        }
        swap(&arr[min],&arr[i]);
    }
    printarr(arr,n);
}

void bubble(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) swap(&arr[i],&arr[j]);
        }
    }
    printarr(arr,n);
}

void insertion(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(&arr[j],&arr[j-1]);
            j--;
        }
    }
    printarr(arr,n);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    insertion(arr,n);
}