#include "BinarySearchTree.h"

void ReadFile(const int N, int *input, Tree *Array, FILE *fp)
{
    int i;
    int left_child, right_child;

	/*Progress the input message which contain the position information of tree nodes*/
	for(i = 0; i < N; i++)
	{
		fscanf(fp, "%d %d", &left_child, &right_child);
		Array[i]->rank = i; /*Record the Depth-First-Search order of the Tree*/

		/*To initialize the pointer in each nodes*/
		if(left_child > 0){ /*If the left_child is not empty*/
		    Array[i]->left = Array[left_child];
	    }else{
			Array[i]->left = NULL;
		}
		if(right_child > 0){ /*If the right_child is not empty*/
		    Array[i]->right = Array[right_child];
		}else{
			Array[i]->right = NULL;
		}
	}
	/*Get key nodes from keyboard and sort it from small to big*/
	for(i = 0; i < N; i++){
		fscanf(fp, "%d ",&input[i]);
	}
}

