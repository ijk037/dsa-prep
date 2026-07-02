#include <stdio.h>

int find_missing_number(int arr[], int n){
    for (int i=0; i<n-1; i++){
        if (arr[i+1]!=arr[i]+1)
            return arr[i]+1;
    }
    return arr[n-1]+1;
}

int main(){
    int arr[]= {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    n = find_missing_number(arr, n);
    printf("\nMissing number = %d", n);

    return 0;
}