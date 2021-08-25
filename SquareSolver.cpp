#include <stdio.h>
#include <math.h>
#include <assert.h>

const double eps = 1e-6;
const int SS_INF_ROOTS = -1;

int SquareSolver(double a, double b, double c, double *x1, double *x2);
int Comparison_zero(double a);

int main()
{
    printf("# Enter factors\n");
    double a = 0, b = 0, c = 0;
    int nCorrect = 0;
    nCorrect = scanf("%lg %lg %lg", &a, &b, &c);
    if (nCorrect == 3)
    {
            
        double x1 = 0, x2 = 0;
        int nRoots = SquareSolver(a, b, c, &x1, &x2);
        
        switch(nRoots)
        {
            case 0: printf("No roots\n");
                    break;
                    
            case 1: printf("Number of roots is 1\n");
                    printf(" %lg \n", x1);
                    break;
                    
            case 2: printf("Number of roots is 2\n");
                    printf(" %lg %lg \n", x1, x2);
                    break;
                    
            case SS_INF_ROOTS: printf("Any number\n");
                    break;
                    
            default: printf ("main():ERROR: nRoots = %d\n", nRoots);
                    return 1;
        }
    }
    else
    {
        printf("ERROR: Enter correct numbers");
    }
    return 0;
}
int SquareSolver(double a, double b, double c, double *x1, double *x2)
{
    assert (std :: isfinite (a));
    assert (std :: isfinite (b));
    assert (std :: isfinite (c));
    
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    
    if (Comparison_zero(a))
    {
        if (Comparison_zero(b))
        {
            if (Comparison_zero(c))
            {
                return SS_INF_ROOTS;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            *x1 = *x2 = -c / b;
            return 1;
        }
    
    }
    else
    {
        double discr = b * b - 4 * a * c;
        
        if (Comparison_zero(discr))
        {
            *x1 = *x2 = -b / (2 * a);
            return 1;
        }
        else
        {
            double sqrt_discr = sqrt(discr);
            
            *x1 = (-b - sqrt_discr) / (2 * a);
            *x2 = (-b + sqrt_discr) / (2 * a);
        }
    }
}
int Comparison_zero(double a)
{
    if (-eps < a && a < eps)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}