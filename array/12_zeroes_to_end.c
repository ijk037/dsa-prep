///////
#include <stdio.h>

void zeroes_to_end(int arr[], int n){
    for (int i=0; i<n; i++){
        if(arr[i]!=0)
            return;
        while(i<n){
            arr[i]=arr[i+1];
        }
    }
}

int main(){
    int arr[]={0, 0, 2, 3, 0, 4, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    zeroes_to_end(arr, n);

    printf("Array after moving all zeroes to the end:\n");
    for (int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

}