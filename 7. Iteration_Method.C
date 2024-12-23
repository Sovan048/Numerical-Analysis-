 #include <stdio.h> 
#include <math.h> 
float phi(float x) { 
    return (pow((9+4*x),1/3.0)); 
} 
float fun(float x) { 
    return (x * x * x-4*x - 9); 
} 
int main() { 
    float lb, ub, x0, x, upto = 0.0001; 
    do { 
        printf("Enter the lower bound (lb): "); 
 scanf("%f", &lb); 
        printf("Enter the upper bound (ub): "); 
        scanf("%f", &ub); 
        if (fun(lb) * fun(ub) < 0) { 
            printf("Roots exist in the interval [%.4f, %.4f]\n", lb, ub); 
            break; 
        } else { 
            printf("Wrong interval. Please try again.\n"); 
        } 
    } while (fun(lb) * fun(ub) >= 0); 
   x= lb;   
    printf("Initial guess: %.4f\n", x); 
    int i=0; 
    printf("Number of iteration :\t\t  Nearest Root\n", x); 
    do { 
     x0 = x; 
        x =  phi(x0);   
    printf("%d\t \t------>>>>%.4f\n",i, x); 
    i++; 
        if (fabs(x - x0) < upto) {   
            break; 
        }  
    } 
 while (fabs(x - x0) > upto); 
    printf("The root is: %.4f\n", x); 
    return 0; 
} 

//Output:
// Enter the lower bound (lb): 2 
// Enter the upper bound (ub): 3 
// Roots exist in the interval [2.0000, 3.0000]
// Initial guess: 2.0000 
// Number of iteration :             Nearest Root 
// 0               ------>>>>2.5713 
// 1               ------>>>>2.6817 
// 2               ------>>>>2.7020 
// 3               ------>>>>2.7057 
// 4               ------>>>>2.7064 
// 5               ------>>>>2.7065 
// 6               ------>>>>2.7065 
// The root is: 2.7065 