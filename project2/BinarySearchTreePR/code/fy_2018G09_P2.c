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
 * Global data: int p = 0
 * ----------------------
 * Description: record the position of array In_order
 */
int p = 0;

/*
 * Function: void ReadFile(const int N, int *input, Tree *Array, FILE *fp)
 * -----------------------------------------------------------------------
 * Description: Read file and get the test case, note that the number in file must
 * follow the same form with PTA and readme.txt
 */
void ReadFile(const int N, int *input, Tree *Array, FILE *fp);

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

int main()
{
	int N; /*N is the number of nodes*/
	int i;
	int *inorder;
	int *input;
	char *filename;
	FILE *fpointer;
	Tree *Array; /*This struct array is used to record the Input*/

    filename = (char *)malloc(100 * sizeof(char));
    do{
        printf("Please Input The filename: \n");
        scanf("%s", filename);
        fpointer = fopen(filename, "r");
        if(fpointer == NULL)
            printf("Please input valid filename!\n\n");
    }while(fpointer == NULL);

	fscanf(fpointer,"%d", &N);
	fscanf(fpointer, "\n");
	/*Exit the program with error message if N was assigned 0*/
	if(N == 0){
	    exit(0);
	}
	inorder = (int *)malloc(N * sizeof(int));
	input = (int *)malloc(N * sizeof(int));
	Array = (Tree *)malloc(N * sizeof(struct Node));
	for(i = 0; i < N; i++){
		Array[i] = (Tree)malloc(sizeof(struct Node)); /*Set space for Tree Array*/
	}
    ReadFile(N, input, Array, fpointer);

    qsort(input, N, sizeof(int) ,comp);/*Use the qsort to sort input from min to max which is the same order of Inorder Travrese*/
	In_order(Array[0],inorder);
	for(i = 0; i < N; i++){
		Array[inorder[i]]->key = input[i];
	}
	/*Print the tree by level order*/
	Level_order(Array[0],N);
	system("pause");

	return 0;
}

/*The pointer points to function to determine sorting order (for qsort)*/
int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b; /*The pointer points to function to determine sorting order for qsort*/
}

/*The Inorder Traverse*/
void In_order(Tree ptr, int *inorder)
{
    if(ptr == NULL){
        exit(0); /*Avoid pointer error*/
    }
    if(ptr->left != NULL){
    	In_order(ptr->left, inorder);
	}
    inorder[p++] = ptr->rank; /*Add the rank in the array into inorder so that each node can be visited by array[inoder[i]]*/
    if(ptr->right != NULL){
    	In_order(ptr->right, inorder);
	}
}

/*Use Level_order to output to satisfy the requirement*/
void Level_order(Tree ptr, int number)
{
    Tree * Queue;
	Queue = (Tree *)malloc(sizeof(Tree *));
    int head = 0, next = 0;

    if(ptr == NULL){
        exit(0); /*Avoid visiting unintialized pointer and exit with error message*/
    }
    Queue[0] = ptr;
    while(head <= next){
    	if(Queue[head]->left != NULL){
		    Queue[++next] = Queue[head]->left;
		}
    	if(Queue[head]->right != NULL){
			Queue[++next] = Queue[head]->right;
		}
    	if(head == 0){
		    printf("%d", Queue[head]->key); /*First output with no space*/
		}else{
		    printf(" %d", Queue[head]->key); /*The output behind first output will output a space before it*/
		}
		head++;
	}
}

/*Read file and get the text case*/
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