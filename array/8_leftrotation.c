#include <stdio.h>

void leftrotation(int arr[], int n){
    int temp = arr[0];
    int i=0;
    while(i!=n-1){
        arr[i]=arr[i+1];
        i++;
    }
    arr[n-1] = temp;
}


int main(){
    int arr[]={0, 3, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before LEFT ROTATION:\n");
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    leftrotation(arr, n);

    printf("Array after LEFT ROTATION:\n");
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}