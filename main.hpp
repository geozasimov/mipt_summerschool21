///@file main.hpp
#include <cstdio>
#include <cmath>
#include <cassert>


 
const double eps = 1e-6;
const int NUMBER_GOOD_COEFF = 3;
const int NUMBER_INF_ROOTS = -1;
const int NUMBER_NO_ROOTS = 0;
const int NUMBER_1_ROOT = 1;
const int NUMBER_2_ROOTS = 2;


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
//! The variable x1 contains a root less than x2.
//------------------------------------------------

int SquareSolver(double a, double b, double c, double *x1, double *x2);

//------------------------------------------------
//! Function checks if numbers are equal to zero.
//!
//! @param [in] number_check number_check - number to check if it is equal to zero
//!
//! @return True or False, if equal or not equal to zero
//!
//! @note Is a special case of the IsEqual function.
//------------------------------------------------

int IsEqual_zero(double number_check);

//------------------------------------------------
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

int IsEqual(double a_number_check, double b_number_check);

//------------------------------------------------
//! The function checks the program for correctness 
//! and doesn't allow the user to use the program, if it is played incorrectly.
//!
//!
//! @return True or False if the program passed all the tests from the file correctly
//!
//! @note The function accesses the file and checks all tests from it for correctness.
//! There are 4 types of tests in total: no roots, 1 root, 2 roots, an infinite number of roots.
//! The variable x1 contains a root less than x2 and the variable x1_right contains a root less than x2_right.
//------------------------------------------------

int test();

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
//! The variable x1 contains a root less than x2 and the variable x1_right contains a root less than x2_right.
//------------------------------------------------

int test_type_check(int a, int b, int c, int nRoots, double x1_right, double x2_right, double *x1, double *x2);

