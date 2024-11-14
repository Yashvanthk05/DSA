#include<stdio.h>
int main(){
    int arr[] = {2,4,7,3,6,9,1,5,8};
    int largest_element = arr[0];
    int i=0;
    while(arr[i]!='\0'){
        if(largest_element<arr[i]){
            largest_element = arr[i];
        }
        i++;
    }
    printf("Largest Element in the Array is: %d",largest_element);
    return 0;
}