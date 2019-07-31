#include "BinarySearchTree.h"

/*
 * Global data: int p = 0
 * ----------------------
 * Description: record the position of array In_order
 */
int p = 0;

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
