#include <stdio.h>
#include <stdlib.h>

void transpose(int m[][4], int t[][2], int rows, int cols){
    for (int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            t[j][i]=m[i][j];
        }
    }
}

int main(){
    int m[2][4] = {{2, 3, 4, 5},{3, 2, 4, 2}};
    int t[4][2];

    printf("Matrix A: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    transpose(m, t, 2, 4);

    printf("Transpose Matrix: \n");
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}