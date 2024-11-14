#include<stdio.h>
#include<stdlib.h>

int compare(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),compare);
    int key=0;
    printf("Enter the Element to be Searched: ");
    scanf("%d",&key);
    
    return 0;
}  