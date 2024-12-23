#include <stdio.h>
#include <math.h>
float fun(float x)
{
    return (x * x * x - 9 * x + 1);
}
float df(float x)
{
    return (3 * x * x - 9);
}
int main()
{
    float lb, ub, x0, x, upto = 0.0001;
    do
    {
        printf("Enter the lower bound (lb): ");
        scanf("%f", &lb);
        printf("Enter the upper bound (ub): ");
        scanf("%f", &ub);
        if (fun(lb) * fun(ub) < 0)
        {

            printf("Roots exist in the interval [%.4f, %.4f]\n", lb, ub);
            break;
        }
        else
        {
            printf("Wrong interval. Please try again.\n");
        }
    } while (fun(lb) * fun(ub) >= 0);
    x = lb;
    printf("Initial guess: %.4f\n", x0);
    do
    {
        x0 = x;
        x = x0 - fun(x0) / df(x0);

        if (fabs(x - x0) < upto)
        {
            break;
        }
    }
        while (fabs(x - x0) > upto);
        printf("The root is: %.4f\n", x);
        return 0;
    }

//Output:
// Enter the lower bound (lb): 2 
// Enter the upper bound (ub): 5 
// Roots exist in the interval [2.0000, 5.0000] 
// Initial guess: 0.0000 
// The root is: 2.9428