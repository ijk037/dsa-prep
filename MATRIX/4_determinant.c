#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void cofactor(int m[][MAX], int temp[][MAX], int p, int q, int n){
    int i=0, j=0;

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(row!=p && col!=q){
                temp[i][j++] = m[row][col];
                if(j==n-1){
                    j=0;
                    i++;
                }
            }
        }
    }
}

int determinant(int m[][MAX], int n){
    if(n==1)
        return m[0][0];
    
    if(n==2)
        return m[0][0]*m[1][1] - m[0][1]*m[1][0];

    int temp[MAX][MAX];
    int det=0;
    int sign=1;

    for(int col=0; col<n; col++){
        cofactor(m, temp, 0, col, n);
        det += sign * m[0][col] * determinant(temp, n-1);
        sign=-sign;
    }
    return det;
}

int main(){
    int m[MAX][MAX] = {{2, 3, 4, 5},{3, 2, 4, 2},{1, 2, 3, 4},{3, 4, 5, 1}};

    printf("Matrix A: \n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Determinant of the Matrix = %d", determinant(m, 4));
    return 0;
}