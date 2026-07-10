#include <stdio.h>
#include <stdlib.h>

void multiplication(int m1[2][4], int m2[4][2], int m3[2][2], int r1, int c1, int r2, int c2){
    if(c1!=r2)
        return;
    
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            m3[i][j]=0;
            for(int k=0; k<c1; k++)
                m3[i][j]+=m1[i][k] * m2[k][j];
        }
    }
}


int main(){
    int m1[2][4] = {{2, 3, 4, 5}, {3, 2, 4, 2}};
    int m2[4][2] = {{2, 3}, {3, 4}, {2, 4}, {1, 2}};
    int m3[2][2];

    printf("Matrix A: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Matrix B: \n");
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    multiplication(m1, m2, m3, 2, 4, 4, 2);

    printf("Sum Matrix: \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
    return 0;
}