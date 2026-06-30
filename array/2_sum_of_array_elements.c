#include <stdio.h>
#define MAX 5

int getsum(int arr[], int n){
    int sum=0;
    for (int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int arr[MAX] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum_arr = getsum(arr, n);
    printf("Sum of all the elements of the array = %d", sum_arr);
    return 0;
}