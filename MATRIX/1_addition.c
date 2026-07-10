#include <stdio.h>
#include <stdlib.h>

void addition(int m1[][4], int m2[][4], int m3[][4], int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            m3[i][j] = m1[i][j]+m2[i][j];
        }
    }
}

int main(){
    int m1[2][4] = {{2, 3, 4, 5},{3, 2, 4, 2}};
    int m2[2][4] = {{2, 3, 1, 4},{3, 4, 1, 5}};
    int m3[2][4];

    printf("Matrix A: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Matrix B: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    addition(m1, m2, m3, 2, 4);

    printf("Sum Matrix: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
    return 0;
}