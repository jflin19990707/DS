#include"BinarySearchTree.h"
int main()
{
	int N;//N is the number of nodes
	int i,left_child,right_child;
	printf("Please input the nodes of the tree N:\n");
	scanf("%d",&N);
	if(N==0) return 0;//Break if N is 0
	int inorder[N],input[N];
	Tree Array[N];//This struct array is used to record the Input
	for(i=0;i<N;i++)
	{
		Array[i] = (Tree)malloc(sizeof(struct Node));//Set space for Tree Array
	}
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&left_child,&right_child);
		Array[i]->rank=i;//Record the Depth-First-Search order of the Tree

		/**To initialize the pointer in each nodes**/
		if(left_child>0) //If the left_child is not empty
		{
		    Array[i]->left=Array[left_child];
	    }
		else
		{
			Array[i]->left=NULL;
		}
		if(right_child>0)//If the right_child is not empty
		{
		    Array[i]->right=Array[right_child];
		}
		else
		{
			Array[i]->right=NULL;
		}
	}
	printf("Please input the key of each nodes:\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&input[i]);
	}
	qsort(input,N,sizeof(int),comp);/*Use the qsort to sort input from min to max,
	                                  which is the same order of Inorder Travrese*/
	In_order(Array[0],inorder);
	for(i=0;i<N;i++)
	{
		Array[inorder[i]]->key=input[i];
	}
	Level_order(Array[0],N);
}
