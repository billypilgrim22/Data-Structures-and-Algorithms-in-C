#include<stdio.h>
int main(){
    int len;
    printf("\nEnter Array size: ");
    scanf("%d",&len);
    int arr[len];
    printf("\nEnter Array elements: ");
    for(int i = 0 ; i < len ; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nOriginal Array: ");
    for(int i = 0 ; i < len ; i++){
        printf("%d\t",arr[i]);
    }
    for(int i = 1 ; i < len ; i++){
        int key = arr[i];
        int j=i-1;
        while(arr[j]>key && j>=0){
            arr[j+1]=arr[j]; 
            j--;
        }
        arr[j+1]=key;
    }
    printf("\nSorted Array: ");
    for(int i = 0 ; i < len ; i++){
        printf("%d\t",arr[i]);
    }
    return 0;

} 
