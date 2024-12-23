#include <stdio.h>
float definefunction(float x, float y)
{
    return x * y;
}
int main()
{
    float x0, y0, h, xn, yn;
    float k1, k2, k3, k4;
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
        k1 = h * definefunction(x, y);
        k2 = h * definefunction(x + h / 2, y + k1 / 2);
        k3 = h * definefunction(x + h / 2, y + k2 / 2);
        k4 = h * definefunction(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
    }
    printf("The value of y at x = %.2f is %.4f\n", xn, y);
    return 0;
}

// OUTPUT:
// Enter initial value of x (x0): 0  
// Enter initial value of y (y0): 1 
//  Enter step size (h): 0.1 
//  Enter target value of x (xn): 0.4  
// The value of y at x = 0.40 is 0.71306 