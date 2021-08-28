#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"

const static double EPS = 1e-6;

int SquareSolver(double a, double b, double c, double *x1, double *x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    
    if (IsEqual(a, 0)) // solve linear equation
    {
        if (IsEqual(b, 0))
        {
            if (IsEqual(c, 0))
            {
                return TypesSquareSolver :: NUMBER_INF_ROOTS;
            }
            else
            {
                return TypesSquareSolver :: NUMBER_NO_ROOTS;
            }
        }
        else
        {
            *x1 = *x2 = -c / b;
            return TypesSquareSolver :: NUMBER_1_ROOT;
        }
    }
    else
    {
        double discr = b * b - 4 * a * c;
        
        if (IsEqual(discr, 0))
        {
            *x1 = *x2 = -b / (2 * a);
            return TypesSquareSolver :: NUMBER_1_ROOT;
        }
        else
        {
            if (discr > 0)
            {
                double sqrt_discr = sqrt(discr);
                
                *x1 = (-b - sqrt_discr) / (2 * a);
                *x2 = (-b + sqrt_discr) / (2 * a);
                return TypesSquareSolver :: NUMBER_2_ROOTS;
            }
            else
            {
                return TypesSquareSolver :: NUMBER_NO_ROOTS;
            }
        }
    }
}

void PrintRoots(int nRoots, double x1, double x2)
{
    switch(nRoots)
            {
                case TypesSquareSolver :: NUMBER_NO_ROOTS: 
                        printf("No roots\n");
                        break;
                        
                case TypesSquareSolver :: NUMBER_1_ROOT: 
                        printf("Number of roots is 1\n");
                        printf(" %lg \n", x1);
                        break;
                        
                case TypesSquareSolver :: NUMBER_2_ROOTS: 
                        printf("Number of roots is 2\n");
                        printf(" %lg %lg \n", x1, x2);
                        break;
                        
                case TypesSquareSolver :: NUMBER_INF_ROOTS: 
                        printf("Any number\n");
                        break;
                        
                default: 
                        printf ("main():ERROR: nRoots = %d\n", nRoots);
                        return;
            }
    return;
}

int IsEqual(double a, double b)
{
    if (fabs(a - b) < EPS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}