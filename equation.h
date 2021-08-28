///@file equation.h

//comment enum
enum TypesSquareSolver
{
	NUMBER_INF_ROOTS = -1,  //!< tralala  3  rublya
	NUMBER_NO_ROOTS = 0,
	NUMBER_1_ROOT = 1,
	NUMBER_2_ROOTS = 2 
};

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
//! returns @ref NUMBER_INF_ROOTS.
//! Function changes x1 and x2, if Number of roots is not zero.
//! The variable x1 contains a root less than x2.
//------------------------------------------------

int SquareSolver(double a, double b, double c, double *x1, double *x2);

//------------------------------------------------
//! The function prints the result of the SquareSolver function.
//!
//! @param [in] TypeConstSS TypeConstSS- coefficient indicating the type of situation when solving a quadratic equation
//!
//! @return nothing
//!
//! @note Based on TypeRootsSS makes an inference for each situation.
//------------------------------------------------

void PrintRoots(int nRoots, double x1, double x2);

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

int IsEqual(double a, double b); 