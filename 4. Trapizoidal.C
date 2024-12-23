#include <stdio.h>
float fun(float x)
{
    float c;
    c = 4 * x - 3 * x * x;
    return c;
}
int main()
{
    int n, lb, ub;
    float y[20], h, x[20], IT;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);
    printf("Enter the lower bound: ");
    scanf("%d", &lb);
    printf("Enter the upper bound: ");
    scanf("%d", &ub);
    h = (float)(ub - lb) / n;
    x[0] = lb;
    for (int i = 0; i <= n; i++)
    {
        y[i] = fun(x[i]);
        if (i < n)
            x[i + 1] = x[i] + h;
    }
    float sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += y[i];
    }
    IT = h / 2 * (y[0] + y[n] + 2 * sum);
    printf("The value of the integral is: %f\n", IT);
    return 0;
}

// //OUTPUT:
// Enter the number of intervals: 5  
// Enter the lower bound: 0 
//  Enter the upper bound: 5  
// The value of the integral is: 1.866667 