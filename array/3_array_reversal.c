#include <stdio.h>
#define MAX 5

int array_reversal(int arr[], int n){
    int l=0, r=n-1;
    while (l<r){
        int temp = arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
        r--;
    }
    return 0;
}

int main(){
    int arr[MAX] = {1, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    array_reversal(arr, n);
    for (int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}