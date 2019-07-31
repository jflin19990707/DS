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
typedef struct Node * Tree;//The pointer of Struct Node
struct Node{
	int key;
	int rank;//Rank refers to the sequence of nodes in the array
	Tree left;
	Tree right;
};
int p = 0;
int comp(const void *a, const void *b)//The pointer points to function to determine sorting order (for qsort)
{
	return *(int *)a - *(int *)b;
}
void In_order(Tree ptr,int * inorder)//The Inorder Traverse
{
    if(ptr==NULL)return;//Avoid pointer error
    if(ptr->left!= NULL)
    {
    	In_order(ptr->left,inorder);
	}
    inorder[p++]=ptr->rank;//Add the rank in the array into inorder so that each node can be visited by array[inoder[i]]
    if(ptr->right!= NULL)
    {
    	In_order(ptr->right,inorder);
	}
}
void Level_order(Tree ptr,int number)//Use Level_order to output to satisfy the requirement
{
    Tree Queue[number];
    int head=0,next=0;
    if(ptr==NULL) return;//Avoid visiting unintialized pointer
    Queue[0]=ptr;
    while(head<=next)
    {
    	if(Queue[head]->left!=NULL)
    	{
		    Queue[++next]=Queue[head]->left;
		}
    	if(Queue[head]->right!=NULL)
		{
			Queue[++next]=Queue[head]->right;
		}
    	if(head==0)
		{
		    printf("%d",Queue[head]->key);//First output with no space
		}
		else
		{
		    printf(" %d",Queue[head]->key);//The output behind first output will output a space before it
		}
		head++;
	}
}


#endif // BINARYSEARCHTREE_H_INCLUDED
