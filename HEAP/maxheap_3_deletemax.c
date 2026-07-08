#include <stdio.h>
#include <stdio.h>
#define MAX 100

int heap[MAX];
int size=0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int i){
    int top=i;
    int left=(2*i) + 1;
    int right = (2*i) +2;

    if(left<size && heap[left]>heap[top])
        top = left;
    if(right<size && heap[right]>heap[top])
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

    while(i!=0 && heap[(i-1)/2]<heap[i]){
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deletemax(){
    if (size==0)
        return;
    printf("Deleted element: %d", heap[0]);
    heap[0] = heap[size-1];
    heapify(0);

}

int main(){
    int arr[] = {3, 4, 2, 5, 1, 6, 4, 7};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int j=0; j<n; j++)
        insertion(arr[j]);

    printf("Original tree  : ");
    for (int j=0; j<size; j++)
        printf("%d ", heap[j]);

    printf("\n");
    deletemax();
    printf("\n");

    printf("New tree       : ");
    for (int j=0; j<size; j++)
        printf("%d ", heap[j]);

    return 0;
}