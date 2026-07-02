#include <stdio.h>
#define MAX 10

void insert_in_array(int arr[], int *n, int element, int position){
    for(int i=*n; i>position; i--){
            arr[i]=arr[i-1];
    }
    arr[position]=element;
    (*n)++;
}

int main(){
    int arr[MAX] = {2, 3, 1, 5, 3, 6, 4};
    int n=sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    int element, position;
    printf("\n");
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the position you want to insert at: ");
    scanf("%d", &position);

    insert_in_array(arr, &n, element, position);

    printf("\n");

    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}