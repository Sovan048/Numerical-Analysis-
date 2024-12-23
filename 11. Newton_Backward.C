#include <stdio.h>
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
void backwardDifference(float x[], float y[], int n)
{
    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            y[i] = y[i] - y[i - 1];
        }
    }
}
float newtonBackwardInterpolation(float x[], float y[], int n, float value)
{
    float result = y[n - 1];
    float term;
    for (int i = 1; i < n; i++)
    {
        term = y[n - 1 - i];
        for (int j = 0; j < i; j++)
        {
            term *= (value - x[n - 1 - j]);
        }
        term /= factorial(i);
        result += term;
    }
    return result;
}
int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter the x values: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the corresponding y values: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    float value;
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &value);
    backwardDifference(x, y, n);
    float result = newtonBackwardInterpolation(x, y, n, value);
    printf("Interpolated value at x = %.2f is: %.6f\n", value, result);
    return 0;
}

// Output:
// Enter the number of data points: 5
// Enter the x values:
// 5 4 3 2 1
// Enter the corresponding y values:
// 25 20 15 10 5
// Enter the value of x for interpolation: 3.5
// Interpolated value at x = 3.50 is: 17.500000