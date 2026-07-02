#include<stdio.h>

int delete_from_array(int arr[], int n, int key){
    int pos=-1;
    for (int i=0; i<n; i++){
        if (arr[i]==key){
            pos=i;
            break;
        }
    }

    if (pos==-1){
        printf("Element not found");
        return n;
    }
    for (int i=pos; i<n; i++){
        arr[i]=arr[i+1];
    }
    return n-1;
}

int main(){
    int arr[] = {2, 3, 1, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key=0;

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");

    printf("Enter element you want to delete: ");
    scanf("%d", &key);
    
    n = delete_from_array(arr, n, key);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}