#include <stdio.h>

//FINDING THE FIRST, SECOND and THIRD LARGEST NUMBER BY SORTING THE ARRAY
void largests_sorting(int arr[], int n){
    int temp=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i]>arr[j]){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}


//FINDING THE FIRST, SECOND and THIRD LARGEST NUMBER BY WITHOUT SORTING
void largests_wo_sorting(int arr[], int n){
    if (n<3){
        printf("Should at least have 3 numbers");
        return;
    }

    int first=0, second=0, third=0;

    for (int i=0; i<n; i++){
        if (arr[i]<first);
        if (arr[i]>first){
            third=second;
            second=first;
            first=arr[i];
        }
        else if (arr[i]>second && arr[i]!=first){
            third=second;
            second=arr[i];
        }
        else if (arr[i]>third && arr[i]!=second && arr[i]!=first){
            third=arr[i];
        }
    }
    printf("\nLargest numbers = %d, %d, %d", first, second, third);
}


int main(){
    int arr[]={3, 4, 2, 3, 1, 5, 2, 4, 6, 7, 8, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    largests_wo_sorting(arr, n);

    printf("\nOR");

    largests_sorting(arr, n);
    printf("\nLargest numbers = %d, %d, %d", arr[0], arr[1], arr[2]);

    return 0;
}