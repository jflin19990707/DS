#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

/*
 *Project Requirement:
 *
 *  Input:
 *  1.A positive integer N.
 *  2.N lines each contains the left and the right children of a node in the format left_index right_index.
 *  3.N distinct integer keys.
 *  Attention:
 *  1.The nodes are numbered from 0 to N-1, and 0 is always the root.
 *  2.If one child is missing, then -1 will represent the NULL child pointer.
 *
 *  Output:
 *  1.Print the level order traversal sequence of the tree in one line.
 *  Attention:
 *  1.All the numbers must be separated by a space, with no extra space at the end of the line.
 *
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Type definition: typedef struct Node * Tree
 * --------------------------------------
 * Description: Define the type struct Node * to Tree so we can use the pointer easily
 * and if we want to modify the data type it will be much easier
 */
typedef struct Node * Tree;

/*
 * Data Type: struct Node
 * ----------------------
 * Description: standard ADT with attribute rank to record the rank message of node
 */
struct Node{
	int key;
	int rank; /*Rank refers to the sequence of nodes in the array*/
	Tree left;
	Tree right;
};


/*
 * Function: int comp(const void *a, const void *b)
 * ------------------------------------------------
 * Call: void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
 * Description: determine the sort order is from small to big
 */
int comp(const void *a, const void *b);

/*
 * Function: void In_order(Tree ptr, int *inorder)
 * -----------------------------------------------
 * Description: Traverse the tree with in-order traverse recursively
 */
void In_order(Tree ptr,int * inorder);

/*
 * Function: void Level_order(Tree ptr,int number)
 * -----------------------------------------------
 * Description: Use Level_order to output to satisfy the requirement
 */
void Level_order(Tree ptr,int number);

/*

 */
void ReadFile(const int N, int *input, Tree *Array, FILE *fp);
#endif // BINARYSEARCHTREE_H_INCLUDED
