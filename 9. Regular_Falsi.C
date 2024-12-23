#include <stdio.h>
#include <math.h>
float fun(float x)
{
    return (x * x * x - 9 * x + 1);
}
int main()
{
    float lb, ub, x, upto = 0.0001;
    do
    {
        printf("Enter the lower bound (lb): ");
        scanf("%f", &lb);
        printf("Enter the upper bound (ub): ");
        scanf("%f", &ub);
        if (fun(lb) * fun(ub) < 0)
        {
            printf("Roots exist in the interval [%.4f, %.4f]\n", lb,
                   ub);
            break;
        }
        else
        {
            printf("Wrong interval. Please try again.\n");
        }
    } while (fun(lb) * fun(ub) >= 0);
    int i = 0;
    do
    {
        x = lb - (fun(lb) * (ub - lb)) / (fun(ub) - fun(lb));
        printf("%d\t \t------>>>>%.4f\n", i, x);
        i++;
        if (fun(x) == 0)
        {
            break;
        }
        else if (fun(x) * fun(lb) < 0)
        {
            ub = x;
        }
        else
        {
            lb = x;
        }
    } while (fabs(ub - lb) > upto);
    printf("The root is approximately: %.4f\n", x);
    return 0;
}

//Output:
// Enter the lower bound (lb): 1 
// Enter the upper bound (ub): 3 
// Roots exist in the interval [1.0000, 3.0000] 
// 0               ------>>>>2.7500 
// 1               ------>>>>2.9368 
// 2               ------>>>>2.9426 
// 3               ------>>>>2.9428 
// 4               ------>>>>2.9428 
// 5               ------>>>>2.9428 
// The root is approximately: 2.9428