#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int heap[MAX];
int size=0;

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i){
    int top = i;
    int left = (2*i) + 1;
    int right = (2*i) + 2;

    if(left<size && heap[left]<heap[top])
        top = left;
    if(right<size && heap[right]<heap[top])
        top = right;
    if(top!=i){
        swap(&heap[i], &heap[top]);
        heapify(top);
    }
}

void insertion(int value){
    if(size==MAX)
        return;
    
    int i=size;
    heap[size++]=value;

    while(i!=0 && heap[(i-1)/2]>heap[i]){
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int j=0; j<n; j++)
        insertion(arr[j]);

    for (int j=0; j<size; j++)
        printf("%d ", heap[j]);
}