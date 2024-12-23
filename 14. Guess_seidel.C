#include <stdio.h>
#include <math.h>

#define MAX 10 // Maximum number of equations
#define EPSILON 0.001 // Convergence tolerance

void gaussSeidel(int n, double a[MAX][MAX], double b[MAX], double x[MAX]) {
    double temp[MAX];
    int i, j;
    double error;

    // Initialize x to 0
    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    int iterations = 0;
    do {
        error = 0;
        for (i = 0; i < n; i++) {
            temp[i] = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    temp[i] -= a[i][j] * x[j];
                }
            }
            temp[i] /= a[i][i];
            
            // Calculate error
            error += fabs(temp[i] - x[i]);
            
            // Update x[i]
            x[i] = temp[i];
        }
        iterations++;
    } while (error > EPSILON);

    printf("Converged in %d iterations.\n", iterations);
}

int main() {
    int n, i, j;
    double a[MAX][MAX], b[MAX], x[MAX];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the matrix (row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the constants of the equations:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    gaussSeidel(n, a, b, x);

    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

    return 0;
}
