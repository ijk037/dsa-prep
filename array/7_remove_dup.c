#include <stdio.h>

int remove_dup(int arr[], int n){
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (arr[i]==arr[j]){
                //for(int k=j; k<n-1; k++){
                //    arr[k]=arr[k+1];
                //}
                arr[j]=arr[j+1];
                if (j==n-1) return;
                //n--;
                //j--;
            }
        }
    }
    return n;
}


int main(){
    int arr[]={1, 1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    n = remove_dup(arr, n);

    printf("Array after removing duplicate values:\n");

    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}