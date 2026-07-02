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

void merge_2_sorted_arrays(int arr_1[], int n_1, int arr_2[], int n_2, int result[], int n){
    sorting(arr_1, n_1);
    sorting(arr_2, n_2);

    int i=0, j=0, k=0;

    while (i<n_1 && j<n_2){
        if (arr_1[i]<=arr_2[j])
            result[k++]=arr_1[i++];
        else
            result[k++]=arr_1[i++];
    }
    while (i<n_1) result[k++]=arr_1[i++];
    while (j<n_2) result[k++]=arr_2[j++];
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

    display_arr(arr_1, n_1);
    display_arr(arr_2, n_2);

    merge_2_sorted_arrays(arr_1, n_1, arr_2, n_2, result, n);

    display_arr(result, n);
}