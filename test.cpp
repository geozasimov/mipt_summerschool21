#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "equation.h"
#include "test.h"

const static int NUMBER_GOOD_CHECK_SYMB = 6;

int Test()
{
    FILE* fp = fopen("text.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR: failed opening file with tests\n");
        return 0;
    }

    int a = NAN, b = NAN, c = NAN, n_roots = NAN;
    double x1_right = NAN, x2_right = NAN;

    double x1 = 0, x2 = 0;

    int FullResult = 1;
    int Result = 0;

    int TestId = 0;

    while (!feof(fp))
    {
        TestId += 1;

        a = NAN, b = NAN, c = NAN, n_roots = NAN;
        x1_right = NAN, x2_right = NAN;
        x1 = 0, x2 = 0;

        int NumberCheckSymb = 0;

        NumberCheckSymb = fscanf(fp,"%d %d %d %d %lg %lg", &a, &b, &c, &n_roots, &x1_right, &x2_right);

        if (NumberCheckSymb != NUMBER_GOOD_CHECK_SYMB)
        {
            printf("ERROR: failed scanf of test %d \n", TestId);
            return 0;
        }

        TestCheckSquareSolver(a, b, c, n_roots, x1_right, x2_right, &x1, & x2, &TestId);
    }

    fclose(fp);
    return FullResult;
}

void TestCheckSquareSolver(double a, double b, double c, int n_roots, double x1_right, double x2_right, double *x1, double * x2, int *TestId)
{
    int Result = TestTypeCheck(a, b, c, n_roots, x1_right, x2_right, x1, x2);
                    if (!Result)
                    {
                        if (n_roots == TypesSquareSolver :: NUMBER_INF_ROOTS)
                        {
                             printf("ERROR: inf roots failed of test %d \n", *TestId);
                        }
                        else
                        {
                            printf("ERROR: %d roots failed of test %d \n", n_roots, *TestId);
                        }
                    }
    return;
}



int TestTypeCheck(double a, double b, double c, int n_roots, double x1_right, double x2_right, double *x1, double *x2)
{
    int ResultFlag = 1;

    int Result = SquareSolver(a, b, c, x1, x2);

    double not_x1 = *x1, not_x2 = *x2;

    if (Result != n_roots && IsEqual(not_x1, x1_right) == 0 && IsEqual(not_x2, x2_right) == 0)
    {
        ResultFlag = 0;
    }
    return ResultFlag;
}
