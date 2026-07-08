#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arrisheap(int arr[], int n){
    for(int i=0; i<=(n-2)/2; i++){
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<n && arr[i]<arr[left])
            return 0;
        if(right<n && arr[i]<arr[right])
            return 0;
    }
    return 1;
}

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i){
    int top=i;
    int left=(2*i) + 1;
    int right = (2*i) +2;

    if(left<n && arr[left]>arr[top])
        top = left;
    if(right<n && arr[right]>arr[top])
        top = right;
    if(top!=i){
        swap(&arr[i], &arr[top]);
        heapify(arr, n, top);
    }
}

void buildmaxheap(int arr[], int n){
    for(int i=(n/2)-1; i>=0; i--)
        heapify(arr, n, i);
}

int main(){
    int arr[] = {8, 7, 6, 3, 4, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    if(arrisheap(arr, n))
        printf("Array is a Heap.\n");
    else{
        printf("Array is not a Heap.\n");
        buildmaxheap(arr, n);
        printf("Heapified array: ");
        for (int j=0; j<n; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
    return 0;
}