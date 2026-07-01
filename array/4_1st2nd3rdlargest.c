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
int largests_wo_sorting(int arr[], int n){
    if (n<3);

    int first=arr[0], second=arr[1], third=arr[2];
    int temp=0;

    largests_sorting(arr, 3);

    for (int i=3; i<n; i++){
        if (arr[i]>first){
            temp=arr[i];
        }
        else if (arr[i]>second && arr[i]!=first){
            temp = arr[i];
        }
        else{
            temp = arr[i];
        }
    }
    return temp;
}


int main(){
    int arr[]={1, 3, 0, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    largests_sorting(arr, n);
    printf("\nLargest numbers = %d, %d, %d", arr[0], arr[1], arr[2]);

    printf("\nOR");

    int result_2 = largests_wo_sorting(arr, n);
    printf("\nLargest numbers = %d, %d, %d", result_2, result_2, result_2);

    return 0;
}