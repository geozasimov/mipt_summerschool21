///@file main.cpp
#include <cstdio>
#include <cmath>
#include <cassert>


 
const double eps = 1e-6;
const int SS_INF_ROOTS = -1;
const int number_good_coefficient = 3;
const int number_inf_roots = -1;
const int number_no_roots = 0;
const int number_1_root = 1;
const int number_2_roots = 2;

 
int SquareSolver(double a, double b, double c, double *x1, double *x2);
int IsEqual_zero(double number_check);
int IsEqual(double a_number_check, double b_number_check);
int test();
int test_type_check(int a, int b, int c, int nRoots, double x1_right, double x2_right, double *x1, double *x2);


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
        if (nCorrect == number_good_coefficient)
        {
                
            double x1 = NAN, x2 = NAN;
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
            printf("ERROR: Enter correct numbers\n");
        }
    }
    else
    {
        printf("Programm works bad, sry\n");
    }
    return 0;
}

//------------------------------------------------
//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//! returns SS_INF_ROOTS.
//! Function changes x1 and x2, if Number of roots is not zero.
//------------------------------------------------

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

//------------------------------------------------
//! Function checks if numbers are equal to zero.
//!
//! @param [in] number_check number_check - number to check if it is equal to zero
//!
//! @return True or False, if equal or not equal to zero
//!
//! @note Is a special case of the IsEqual function.
//------------------------------------------------

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

//! Function checks if numbers are equal.
//!
//! @param [in] a_number_check a_number_check - one of the comparison numbers with the other
//! @param [in] b_number_check b_number_check - one of the comparison numbers with the other
//!
//! @return True or False, if the numbers are equal or not equal to each other
//!
//! @note Checks if the difference between numbers is in the neighborhood of epsilon,
//! that is, compares the modulus of the difference of two numbers with epsilon.
//------------------------------------------------

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

//------------------------------------------------
//! The function checks the program for correctness 
//! and doesn't allow the user to use the program, if it is played incorrectly.
//!
//!
//! @return True or False if the program passed all the tests from the file correctly
//!
//! @note The function accesses the file and checks all tests from it for correctness.
//! There are 4 types of tests in total: no roots, 1 root, 2 roots, an infinite number of roots.
//------------------------------------------------

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
            case number_inf_roots: 
                    Full_result = test_type_check(a, b, c, nRoots,x1_right,x2_right, &x1, &x2);
                    if (!Full_result)
                    {
                        printf("ERROR: inf roots test fail\n");
                    }
                    break;
            case number_no_roots:
                    Full_result = test_type_check(a, b, c, nRoots,x1_right,x2_right, &x1, &x2);
                    if (!Full_result)
                    {
                        printf("ERROR: 0 roots test fail\n");
                    }
                    break;
            case number_1_root:
                    Full_result = test_type_check(a, b, c, nRoots,x1_right,x2_right, &x1, &x2);
                    if (!Full_result)
                    {
                        printf("ERROR: 1 roots test fail\n");
                    }
                    break;
            case number_2_roots:
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

//------------------------------------------------
//! The function is a helper for the test () function.
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [in] x1_right x1_right-correct answer for the first root x1
//! @param [in] x2_right x2_right-correct answer for the second root x2
//! @param [in] x1 Pointer to the 1st root
//! @param [in] x2 Pointer to the 2nd root
//!
//!
//! @return True or False if one of the examples in the equation passes the test correctly
//!
//! @note The function checks the example by checking the number of roots and comparing the resulting roots with the correct roots.
//------------------------------------------------

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
