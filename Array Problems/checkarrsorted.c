#include<stdio.h>
#include<stdbool.h>

bool checkSorted(int arr[]){
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]))-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    int arr[] = {10,2,4,7,3,6,9,1,5,8};
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    printf("Array 1 is Sorted? %s\n",checkSorted(arr)?"Yes":"No");
    printf("Array 2 is Sorted? %s",checkSorted(arr1)?"Yes":"No");
    return 0;
}