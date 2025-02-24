#include <stdio.h>
#define N 3

void gauss(float A[N][N+1], float x[N]) {
    int i, j, k;
    
    for (i = 0; i < N; i++) {

        for (k = i + 1; k < N; k++) {
            float fator = A[k][i] / A[i][i];
            for (j = i; j <= N; j++) {
                A[k][j] -= fator * A[i][j];
            }
        }
    }

    printf("\nMatriz após a eliminação de Gauss:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j <= N; j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = N - 1; i >= 0; i--) {
        x[i] = A[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

int main() {
    float A[N][N+1] = {
        {2, -1, 1, 3},  // 2x - y + z = 3
        {1, 3, 2, 12},  // x + 3y + 2z = 12
        {1, -1, 2, 0}   // x - y + 2z = 0
    };
    float x[N];
    
    gauss(A, x);
    
    // Exibir solução
    printf("Soluções:\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }
    
    return 0;
}
