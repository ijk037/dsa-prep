#include <stdio.h>

int count_even_and_odd(int arr[], int n){
    int count_even=0, count_odd=0;
    for (int i=0; i<n; i++){
        if (arr[i]%2==0)
            count_even++;
        else
            count_odd++;
    }
    printf("\nNo. of even numbers = %d", count_even);
    printf("\nNo. of odd numbers = %d", count_odd);
}


int main(){
    int arr[]={1, 3, 0, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    count_even_and_odd(arr, n);

    return 0;
}