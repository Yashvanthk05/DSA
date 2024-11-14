#include<stdio.h>
int main(){
    int arr[] = {3,4,3,2,1,6,4,3,7,8,4,1};
    int len = (sizeof(arr)/sizeof(arr[0]));
    int res[(sizeof(arr)/sizeof(arr[0]))] = {0};
    int res_it = 0;
    for(int i=0;i<len;i++){
        int flag = 0;
        for(int j=0;j<len;j++){
            if(arr[i]==res[j]){
                flag++;
            }
        }
        if(flag==0){
            res[res_it]=arr[i];
            res_it++;
        }
    }
    for(int i=0;i<res_it;i++){
        printf("%d ",res[i]);
    }
    return 0;
}