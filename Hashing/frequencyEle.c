#include<stdio.h>

int main(){
    int arr[10]; //count the frequnecy of elements of array of size 10
    //Let us assume the elements in the array are from 0 to 50
    for(int i=0;i<10;i++){
        printf("Enter the Element of the Array: ");
        scanf("%d",&arr[i]);
    }

    int hash[50] = {0};
    for(int i=0;i<10;i++){
        hash[arr[i]]++;
    }
    printf("Duplicate Elements of the Array are:\n");
    for(int i=0;i<50;i++){
        if(hash[i]>1){
            printf("%d ",i);
        }
    }
    return 0;
}