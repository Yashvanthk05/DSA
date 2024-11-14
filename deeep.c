#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        int sum=arr[i];
        for(int j=i+1;j<=n;j++){
            if(sum==target){
                printf("%d %d",i-1,j-1);
            }
            if(j<n){
               sum+=arr[j]; 
            }
            
        }
    }
    return 0;
}