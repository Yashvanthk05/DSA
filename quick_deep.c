#include<stdio.h>
void countsort(int arr[],int n);
int main(){
    int n=5;
    int arr[]={5,4,3,2,1};
    countsort(arr,5);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}
void countsort(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    int c[max+1];
    for(int i=0;i<=max;i++) c[i]=0;
    for(int i=0;i<n;i++) c[arr[i]]++;
    for(int i=1;i<=max;i++) c[i]+=c[i-1];
    int out[n];
    for(int i=n-1;i>=0;i--){
        out[c[arr[i]]-1]=arr[i];
        c[arr[i]]--;
    }
    for(int i=0;i<n;i++) arr[i]=out[i];
}