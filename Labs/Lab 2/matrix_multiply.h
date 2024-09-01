#ifndef MATRIX_MULTIPLY
#define MATRIX_MULTIPLY

int ** matrixMultiply(int** matrix1, int m, int n, int **matrix2, int x, int y){
    int **productMatrix = new int*[m];
    for(int i=0;i<m;i++){
        productMatrix[i] = new int[y];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<y;j++){
            int sum = 0;
            for(int k=0;k<x;k++){
                sum+= matrix1[i][k] * matrix2[k][j];
            }
            productMatrix[i][j] = sum;
        }
    }

    return productMatrix;
}

#endif