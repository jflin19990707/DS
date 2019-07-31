#include <stdio.h>
#include <stdlib.h> 
#define MAX 1005
 
/* ELement structure, record the information of every element in the slot */
typedef struct {
	int start; /* initial insert position */
	int end;   /* finial  insert position  */
	int value; /* element value */
	int count; /* the number of other elements that is already 
	              in the hashtable with position between start and end */
	int flag;  /* if it has inserted to heap or it is a empty element, flag==1, otherwise flag==0 */
} Element; 

/* min-heap structure */
typedef struct{
	Element array[MAX];  /* heap array */
	int size;            /* heap size */
} Heap;


/* name:     percDown
   input:    Heap structure pointer, a specified starting position
   output:   none  
   function: adjust the subheap with specified position as top satisfy the properties of min-heap
*/
void percDown(Heap *heap,int pos)
{
	int parent,child;
	Element temp=heap->array[pos];
	
	for(parent=pos;parent*2+1<heap->size;parent=child)
	{
		child=parent*2+1; /* assume the minimum child is left child */
		if(child+1<heap->size&&heap->array[child].value>heap->array[child+1].value) 
			child++; /* if right child exists and its value less than left child's, adjust minimum child */
		if(heap->array[child].value>temp.value)
			break;  /* if the child with minimum value is larger than parent's value */
		else
			heap->array[parent]=heap->array[child]; /* move downward and continue finding position */
	}
	
	heap->array[parent]=temp; /* if the position is found, insert the initial top element */
}


/* name:     initial
   input:    Heap structure pointer
   output:   none
   function: initial the heap
*/
void initial(Heap *heap)
{
	heap->size=0;
}


/* name:     build
   input:    Heap structure pointer
   output:   none
   function: adjust a mixed array, rebuild it as a min-heap
*/
void build(Heap *heap)
{
	int pos;
	for(pos=heap->size/2-1;pos>=0;pos--)
		percDown(heap,pos); /* adjust every subheap form first interior node to top*/
}


/* name:     insert
   input:    Heap structure pointer, an elements to be inserted
   output:   none
   function: insert an element to the min-heap, adjust itself to keep the properties 
*/
void insert(Heap *heap,Element element)
{
	int child;
	Element temp=element;
	
	for(child=heap->size;child>0;child=(child-1)>>1)  /* find position start from buttom */
	{
		if(temp.value>heap->array[(child-1)>>1].value) /* if the element is less than its parents, then position is found */
			break;
		else
			heap->array[child]=heap->array[(child-1)>>1]; /* if not, move upward and continue finding position */
	}
	
	heap->array[child]=temp; /* insert the elemens to found position */
	heap->size++; 
}


/* name: 	 remove
   input:    Heap structure pointer
   output:   the least element of the initial min-heap
   function: remove the least element of initial min-heap and adjust it to a min-heap
*/
Element removal(Heap *heap)
{
	Element temp=heap->array[0]; /* get the least element of min-heap*/
	
	heap->array[0]=heap->array[heap->size-1]; /* move the last elements to top*/
	heap->size--; 
	
	percDown(heap,0);  /* adjust the heap */
	return temp;
}


int main()
{
	Heap heap;
	Element slot[MAX],temp;
	int seq[MAX],num,index;        
	int scount=0,dcount=0;	/* dcount: number of currently processed solts (empty slot or solt that has inserted to heap) */
	 						/* scount: number of current sequence elements */ 
	 						 
	initial(&heap); /* initial the heap */
	
	scanf("%d",&num);
	if(num<=0||num>1000) /* illegal size number */
	{
		fprintf(stderr,"Illegal size number\n");	
		system("pause");
		exit(1);
	}
	
	for(index=0;index<num;index++) /* read the elements in each slot of hashtable */
	{
		scanf("%d",&(slot[index].value));
		if(slot[index].value<0)  /* if it's a empty slot */
		{
			slot[index].flag=1;
			dcount++;
		}
		else
		{
			slot[index].start=slot[index].value%num; /* caculate the initial insert position */
			slot[index].end=index;  /* assign the finial insert position */
			slot[index].count=0;
			if(slot[index].start==slot[index].end) /* if it has no coliision when it fisrt insert to slot */
			{
				slot[index].flag=1;
				heap.array[heap.size]=slot[index]; /* insert it to heap, which means that it can insert to slot */
				heap.size++;
				dcount++;
			}
			else
				slot[index].flag=0;
		}
	}
	
	if(heap.size==0&&dcount!=num) /* no element can be firstly inserted to slot and the sequence is not empty, which represents an illgel input. */
	{
		fprintf(stderr,"No Solution\n");	
		system("pause");
		exit(1);
	}
	else
		build(&heap); /* build the min-heap */
		
	while(dcount!=num) /* simulate the insertion process until all elements are inserted to heap */
	{
		if(heap.size!=0)
			temp=removal(&heap);  /* get the least elements in heap, insert it to slot */
		else /* if there is no element in the heap but remains untreated elements, it means none of rest elements can insert to slot. No solution */
		{
			fprintf(stderr,"No Solution\n");	
			system("pause");
			exit(1);
		}
		for(index=0;index<num;index++) /* adjust other elements */
		{
			if(slot[index].flag==0) /* if the slot is not empty and the element hasn't inserted to heap */
			{
				if(slot[index].start<slot[index].end)
				{
					if(temp.end>=slot[index].start&&temp.end<slot[index].end) /* if the insert position is in the collision sequence of current element */
						slot[index].count++;
				}
				else /* the collision sequence go throungh the tail */ 
				{
					if(temp.end>=slot[index].start||temp.end<slot[index].end) /* if the insert position is in the collision sequence of current element */
						slot[index].count++;
				}
				if(slot[index].count==(slot[index].end-slot[index].start+num)%num) /* if the slot form initial position to end position is all full */
				{
					slot[index].flag=1; /* insert current element to heap, which means that it can insert to slot */
					insert(&heap,slot[index]);
					dcount++;	
				}
			}
		}
		seq[scount++]=temp.value; /* add the current element into insertion sequence */			
	}
	
	while(heap.size!=0) /* if all elements is in the heap, then only insert elements to slot in order from small to large */
	{
		temp=removal(&heap); /* get the least element and simulately insert it to slot */
		seq[scount++]=temp.value; /* add the current element into insertion sequence */			
	}
	
	for(index=0;index<scount;index++) /* print the element in insertion sequence */ 
	{
		if(index==0) 
			printf("%d",seq[index]);
		else
			printf(" %d",seq[index]);
	}

	system("pause"); /* pause the program to see the result */
	return 0;
}
