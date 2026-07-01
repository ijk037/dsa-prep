#include <stdio.h>

int firstoccur(int arr[], int n, int key){
    int pos=0;
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            pos=i;
            return pos;
        }
    }
}


int main(){
    int arr[]={1, 2, 3, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }

    int key;
    printf("\nEnter the value of which you want to find the first occurence: ");
    scanf("%d", &key);

    int result;
    result = firstoccur(arr, n, key);
    printf("First occurence = %d", result);

    return 0;
}