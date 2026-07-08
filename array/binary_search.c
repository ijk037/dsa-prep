#include <stdio.h>
#include<stdlib.h>

int binary_search(int arr[], int key, int low, int high){
    int mid = (low+high)/2;
    if(low>high)
        return 0;
    if (arr[mid]==key)
        return 1;
    else if(key<arr[mid])
        return binary_search(arr, key, low, mid-1);
    else if(key>arr[mid])
        return binary_search(arr, key, mid+1, high);
    else
        return 0;
    return 0;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int low=0, high=sizeof(arr)/sizeof(arr[0])-1;
    int key = 2;
    if (binary_search(arr, key, low, high))
        printf("Key found!");
    else
        printf("Key not found.");
    return 0;
}