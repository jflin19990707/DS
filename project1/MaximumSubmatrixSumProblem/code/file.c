#include "head.h"
/*
 *Description: read data from EXAMPLE.txt to the matrix
 *EXAMPLE is specified by manual input
 *-----------------------------------------------------
 *Input: a N*N integer matrix
 *Return: '-1' refers to a error of can't open the specified file
 *'1' refers to read file successfully
 */
int readfile()
{
    int i, j, **A;
    char fileName[20];
    FILE * fp;
    printf("input the filename to read: ");
    scanf("%s", fileName);
    if((fp = fopen(fileName, "r")) == NULL){
        printf("can't open file %s\n", fileName);
        return NULL;
    }

    fscanf(fp,"%d",&N);
    A=(int **)malloc(N*sizeof(int *));
    for(i = 0; i < N; i++)
        A[i]=(int *)malloc(N*sizeof(int));

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            fscanf(fp, "%d", &A[i][j]);
        }
        fscanf(fp, "\n");
    }
    fclose(fp);
    return A;
}
