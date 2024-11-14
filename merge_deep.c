#include<stdio.h>

void merge(int arr[],int low,int mid,int high);
void mergesort(int arr[],int low,int high);

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}
void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid=low +(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void merge(int arr[],int low,int mid,int high){
    int i=low,j=mid+1;
    int k=low;
    int b[high-low+1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k]=arr[i];
            k++;
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k]=arr[j];
        j++;
        k++;
    }
    for(int i=low;i<high-low+1;i++){
        arr[i]=b[i];
    }
}