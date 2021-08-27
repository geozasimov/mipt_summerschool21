#include "main.hpp"


int main()
{
    int Full_result = test();
    if (Full_result == 1)
    {
        printf("# Programm works good\n");
        printf("# Enter factors\n");
        double a = NAN, b = NAN, c = NAN;
        int nCorrect = 0;
        nCorrect = scanf("%lg %lg %lg", &a, &b, &c);
        if (nCorrect == NUMBER_GOOD_COEFF)
        {
                
            double x1 = NAN, x2 = NAN;
            int nRoots = SquareSolver(a, b, c, &x1, &x2);
            
            switch(nRoots)
            {
                case NUMBER_NO_ROOTS: printf("No roots\n");
                        break;
                        
                case NUMBER_1_ROOT: printf("Number of roots is 1\n");
                        printf(" %lg \n", x1);
                        break;
                        
                case NUMBER_2_ROOTS: printf("Number of roots is 2\n");
                        printf(" %lg %lg \n", x1, x2);
                        break;
                        
                case NUMBER_INF_ROOTS: printf("Any number\n");
                        break;
                        
                default: printf ("main():ERROR: nRoots = %d\n", nRoots);
                        return 1;
            }
        }
        else
        {
            printf("ERROR: Enter correct numbers\n");
        }
    }
    else
    {
        printf("Programm works bad, sry\n");
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
    
    if (IsEqual_zero(a))
    {
        if (IsEqual_zero(b))
        {
            if (IsEqual_zero(c))
            {
                return NUMBER_INF_ROOTS;
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
        
        if (IsEqual_zero(discr))
        {
            *x1 = *x2 = -b / (2 * a);
            return 1;
        }
        else
        {
            if (discr > 0)
            {
                double sqrt_discr = sqrt(discr);
                
                *x1 = (-b - sqrt_discr) / (2 * a);
                *x2 = (-b + sqrt_discr) / (2 * a);
                return 2;
            }
            else
            {
                return 0;
            }
        }
    }
}

int IsEqual_zero(double number_check)
{
    if (IsEqual(number_check, 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsEqual(double a_number_check, double b_number_check)
{
    if (fabs(a_number_check - b_number_check) < eps)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int test()
{
    ///test
    FILE* fp = fopen("text.txt", "r");

    int a = NAN, b = NAN, c = NAN, nRoots = NAN;
    double x1_right = NAN, x2_right = NAN;
    int Full_result = 1;
    double x1 = 0, x2 = 0;
    int Result = 0;
    int index = 0;

    while (!feof(fp))
    {
        a = NAN, b = NAN, c = NAN, nRoots = NAN;
        x1_right = NAN, x2_right = NAN;
        x1 = 0, x2 = 0;
        fscanf(fp,"%d %d %d %d %lg %lg", &a, &b, &c, &nRoots, &x1_right, &x2_right);
        ///inf roots
        switch(nRoots)
        {
            case NUMBER_INF_ROOTS: 
                    Full_result = test_type_check(a, b, c, nRoots,x1_right,x2_right, &x1, &x2);
                    if (!Full_result)
                    {
                        printf("ERROR: inf roots test fail\n");
                    }
                    break;
            case NUMBER_NO_ROOTS:
                    Full_result = test_type_check(a, b, c, nRoots,x1_right,x2_right, &x1, &x2);
                    if (!Full_result)
                    {
                        printf("ERROR: 0 roots test fail\n");
                    }
                    break;
            case NUMBER_1_ROOT:
                    Full_result = test_type_check(a, b, c, nRoots,x1_right,x2_right, &x1, &x2);
                    if (!Full_result)
                    {
                        printf("ERROR: 1 roots test fail\n");
                    }
                    break;
            case NUMBER_2_ROOTS:
                    Full_result = test_type_check(a, b, c, nRoots,x1_right,x2_right, &x1, &x2);
                    if (!Full_result)
                    {
                        printf("ERROR: 2 roots test fail\n");
                    }
                    break;

            default: printf("ERROR: programm didn't go to any case :( \n");
        }
        
    }
    fclose(fp);
    return Full_result;
    ///----
    ///end of test
    
}



int test_type_check(int a, int b, int c, int nRoots, double x1_right, double x2_right, double *x1, double *x2)
{
    int Result_flag = 1;
    int Result = 0;
    Result = SquareSolver(a, b, c, x1, x2);
    double not_x1 = *x1, not_x2 = *x2;
    if (Result != nRoots && IsEqual(not_x1, x1_right) == 0 && IsEqual(not_x2, x2_right) == 0)
    {
        Result_flag = 0;
    }
    return Result_flag;
}
