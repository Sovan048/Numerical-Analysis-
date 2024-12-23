#include <stdio.h>
float fun(float x)
{
    return x / (1 + x);
}
int main()
{
    int n, lb, ub;
    float y[20], h, x[20], IS = 0.0;
    printf("Enter the number of intervals : ");
    scanf("%d", &n);
    if (n % 2 != 0)
    {
        printf("Error: Number of intervals for Simpson's 3/8 rule.\n");
        return 1;
    }
    printf("Enter the lower bound: ");
    scanf("%d", &lb);
    printf("Enter the upper bound: ");
    scanf("%d", &ub);
    h = (float)(ub - lb) / n;
    for (int i = 0; i <= n; i++)
    {
        x[i] = lb + i * h;
        y[i] = fun(x[i]);
    }
    float es = 0.0, os = 0.0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            es += y[i];
        }
        else
        {
            os += y[i];
        }
    }
    IS = (3 * h / 8) * (y[0] + y[n] + 2 * es + 3 * os);
    printf("The value of the integral using simpsons3/8  is: %f\n", IS);
    return 0;
}

//Output: 
// Enter the number of intervals : 2 
// Enter the lower bound: 1 
// Enter the upper bound: 10 
// The value of the integral using simpsons3/8  is: 6.661495 