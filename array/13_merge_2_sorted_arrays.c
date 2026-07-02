///////
#include<stdio.h>

void sorting(int arr[], int n){
    int temp;
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void merge_2_arrays(int arr_1[], int n_1, int arr_2[], int n_2, int result[], int n){
    for(int i=0; i<n; i++){
        result[i]=arr_1[i];
    }
    for(int i=0;i<n; i++){
        result[n_1+i]=arr_2[i];
    }
    sorting(result, n);
}

void display_arr(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr_1[]={1, 3, 2, 4};
    int n_1=sizeof(arr_1)/sizeof(arr_1[0]);
    int arr_2[]={3, 4, 6, 2};
    int n_2 = sizeof(arr_2)/sizeof(arr_2[0]);
    int n=n_1+n_2;
    int result[n];

    printf("\nFirst array : ");
    display_arr(arr_1, n_1);
    printf("\nSecond array: ");
    display_arr(arr_2, n_2);

    merge_2_arrays(arr_1, n_1, arr_2, n_2, result, n);

    printf("\nResult array: ");
    display_arr(result, n);
}