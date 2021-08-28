///@file test.h

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

int Test(); 

//------------------------------------------------
//! The function checks the program for correctness. 
//! If any of the tests fails, the function prints the test number and does not allow the user to access the program.
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
//! @return nothing
//!
//------------------------------------------------

void TestCheckSquareSolver(double a, double b, double c, int n_roots, double x1_right, double x2_right, double *x1, double * x2, int *TestId);
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

int TestTypeCheck(double a, double b, double c, int n_roots, double x1_right, double x2_right, double *x1, double *x2);