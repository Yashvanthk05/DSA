#include<stdio.h>
#includekstdlib.h>
int comparator (corist void a,const void b){
return ((int*)a-(int)b);
}
int main(){
int n;
scanf("%d",&n);
int arr1[n], arr2[n];
for(int i=0;i<n;i++){
scanf("%d",&arr1[i]);
}
I for(int i=0;i<n;i++){
scanf("%d",&arr2[i]);
} qsort(arr1,n,sizeof(int),comparator); qsort(arr2, n, sizeof(int), comparator);
int common[n];
int res[2*n]={0};
int res_i=0;
int com_i=0;
for(int i=0;i<n;i++){
int flag=0;
for(int j=0;j<n;j++){
if(arr1[i]==arr2[j]){
flag++;
}
}
if(flag>0){
1
common[com_i] arr1[i]; res[res_i] arr1[i];
res_i++;
2
3
com_i++;