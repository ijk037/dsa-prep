#include <stdio.h>
#define MAX 5

int main(){
    int arr[MAX] = {2, 8, 30, 4, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxele = arr[0];

    for (int i=0; i<n; i++){
        if (maxele<arr[i])
            maxele=arr[i];
    }
    printf("%d", maxele);
}