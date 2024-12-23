#include <stdio.h>
float lagrangeInterpolation(float x[], float y[], int n, float value)
{
    float result = 0.0;
    for (int i = 0; i < n; i++)
    {
        float term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term *= (value - x[j]) / (x[i] - x[j]);
            }
        }
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
    float result = lagrangeInterpolation(x, y, n, value);
    printf("Interpolated value at x = %.2f is: %.6f\n", value, result);
    return 0;
}

// Output:
//  Enter the number of data points: 4
// Enter the x values:
// 1 2 3 4
// Enter the corresponding y values:
// 1 4 9 16
// Enter the value of x for interpolation: 2.5
// Interpolated value at x = 2.50 is: 6.250000