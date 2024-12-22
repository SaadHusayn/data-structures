#include<stdio.h>
#include<stdlib.h>


void matrixMultiplication(int **ans,int **a,int **b, int m, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j] = 0;
            for(int k=0;k<n;k++){
                ans[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int **a = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        *(a+i) = (int *)malloc(m*(sizeof(int)));
    }

    int **b = (int **)malloc(m*sizeof(int *));
    for(int i=0;i<m;i++){
        *(b+i) = (int *)malloc(n*(sizeof(int)));
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &b[i][j]);
        }
    }


    int **ans = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        *(ans+i) = (int *)malloc(n*(sizeof(int)));
    }

    matrixMultiplication(ans, a, b, m, n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}