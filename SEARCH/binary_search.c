#include <stdio.h>

int binary_search(int arr[], int key, int low, int high){
    int mid=(low+high)/2;
    if(low>high)
        return -1;
    
    if(arr[mid]==key){
            return mid;
    } else if(key<arr[mid])
        return binary_search(arr, key, low, mid-1);
    else
        return binary_search(arr, key, mid+1, high);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 5;

    int low=0, high=n;

    int key=2;
    int pos = binary_search(arr, key, low, high);

    if(pos)
        printf("Key found at %d.", pos);
    else
        printf("Key not found.");

    return 0;
}