#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"
#include "test.h"

const static double NUMBER_GOOD_COEFF = 3;

int main()
{
    int FullResult = Test();

    if (!FullResult)
    {
        printf("Programm works bad, sry\n");
        return 0;
    }
    
    printf("# Programm works good\n");
    printf("# Enter factors\n");

    double a = NAN, b = NAN, c = NAN;

    int nCorrect = scanf("%lg %lg %lg", &a, &b, &c);

    if (nCorrect == NUMBER_GOOD_COEFF)
    {    
        double x1 = NAN, x2 = NAN;
        int nRoots = SquareSolver(a, b, c, &x1, &x2);
        
        PrintRoots(nRoots, x1, x2);
    }
    else
    {
        printf("ERROR: Enter correct numbers\n");
        return 1;
    }
    
    return 0;
}
