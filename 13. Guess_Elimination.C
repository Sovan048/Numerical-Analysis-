#include <stdio.h>
#include <math.h>

double guessEliminationSquareRoot(double number, double precision) {
    if (number < 0) {
        printf("Negative input! Square root undefined.\n");
        return -1;
    }

    double low = 0, high = number, mid;
    while (high - low > precision) {
        mid = (low + high) / 2.0;
        if (mid * mid > number) {
            high = mid; // Eliminate the upper half
        } else {
            low = mid; // Eliminate the lower half
        }
    }
    return (low + high) / 2.0; // Final approximation
}

int main() {
    double number, precision;

    // Input number and desired precision
    printf("Enter the number to find the square root of: ");
    scanf("%lf", &number);

    printf("Enter the desired precision (e.g., 0.0001): ");
    scanf("%lf", &precision);

    // Compute the square root
    double result = guessEliminationSquareRoot(number, precision);

    if (result != -1) {
        printf("Square root of %.6lf is approximately %.6lf\n", number, result);
    }

    return 0;
}
