#include <stdio.h>
float definefunction(float x, float y)
{
    return x * y;
}
int main()
{
    float x0, y0, h, xn;

    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0): ");
    scanf("%f", &y0);

    printf("Enter step size (h): ");
    scanf("%f", &h);

    printf("Enter target value of x (xn): ");
    scanf("%f", &xn);

    float x = x0;
    float y = y0;

    while (x <= xn)
    {
        y = y + h * definefunction(x, y);
        x = x + h;
    }
    printf("The value of y at x = %.2f is %.4f\n", xn, y);
    return 0;
}

// OUTPUT 
// Enter initial value of x (x0): 0 
//  Enter initial value of y (y0): 1  
// Enter step size (h): 0.2  
// Enter target value of x (xn): 1  
// value of y at x = 1.00 is 1.7511