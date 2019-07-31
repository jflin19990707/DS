#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
 * Global variable: int N
 * ----------------------
 * the scale of the matrix which we need to find the Maxinum Submatrix
 */
int N;

/*
 * Function: int algorithm1(int **A)
 * ---------------------------------
 * Time complexity: O(N^6)
 * -----------------------
 * A naive algrithm finding the answer by calculating all possible results
 */
int algorithm1(int **A);

/*
 * Function: int algorithm1(int **A)
 * ---------------------------------
 * Time complexity: O(N^4)
 * -----------------------
 * A little advanced algrithm which store the previous calculate result to
 * save time
 */
int algorithm2(int **A);

/*
 * Function: int algorithm1(int **A)
 * ---------------------------------
 * Time complexity: O(N^3)
 * -----------------------
 * A advanced algrithm which use a online technique and solve the problem of
 * can't traversing the whole matrix by divide the marix with two different rows
 */
int algorithm3(int **A);
int readfile();
