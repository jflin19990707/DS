#include "head.h"
#include "file.c"
int main()
{
    int MaxSum, i, times, ticks, flag;
    int **fileMatrix;
    double duration,total;
    clock_t start,stop;
    FILE *output = fopen("result.txt","w");

    printf("input 1 to continue or 0 to exit: ");
    scanf("%d",&flag);
    while(flag!=0)
    {
        /*get matrix from EXAMPLE.txt file*/
        do{
            fileMatrix = readfile();
        }while(fileMatrix == NULL);
        /*get iteration times*/
        printf("input the iteration times: ");
        scanf("%d",&times);
        fprintf(output,"size: %d\n", N);
        /*record runtime of algorithms*/
        /*algorithm1*/
        start = clock();
        for(i = 0; i < times; i++){
            MaxSum = algorithm1(fileMatrix);
        }
        stop = clock();
        ticks = stop-start;
        total = (double)(ticks)/CLK_TCK;
        duration = total/times;
        fprintf(output,"<algorithm1> result: %d ",MaxSum);
        fprintf(output,"iteration: %d,ticks: %d,total time:%.6f,duration:%.10f\n", times, ticks, total, duration);

        /*algorithm2*/
        start = clock();
        for(i = 0; i < times; i++){
            MaxSum = algorithm2(fileMatrix);
        }
        stop = clock();
        ticks = stop-start;
        total = (double)ticks/CLK_TCK;
        duration = total/times;
        fprintf(output,"<algorithm2> result: %d ",MaxSum);
        fprintf(output,"iteration: %d,ticks: %d,total time:%.6f,duration:%.10f\n", times, ticks, total, duration);

        /*algorithm3*/
        start = clock();
        for(i = 0; i < times; i++){
            MaxSum = algorithm3(fileMatrix);
        }
        stop = clock();
        ticks = stop-start;
        total = (double)ticks/CLK_TCK;
        duration = total/times;
        fprintf(output,"<algorithm3> result: %d ",MaxSum);
        fprintf(output,"iteration: %d,ticks: %d,total time:%.6f,duration:%.10f\n\n", times, ticks, total, duration);

        /*free the allocated memory*/
        for(i = 0;i < N; i++)
            free(fileMatrix[i]);
        free(fileMatrix);

        printf("input 1 to continue or 0 to exit: ");
        scanf("%d",&flag);
    }

    fclose(output);
    system("pause");
    return 0;
}
/*
 * Description: use traversing method with the time complexity N^6
 * calculate every possible result to find the biggest sum
 * ---------------------------------------------------------------
 * Input: a N*N integer matrix
 * Return: the maximum subsequence sum
 */
int algorithm1(int **A)
{
    /*Submatrix head*/
    int i, j;
    /*Submatrix end*/
    int x, y;
    /*Traversal tool*/
    int a, b;
    int MaxSum = 0, TempSum;
    /*Move the position of head*/
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            /*Move the position of end*/
            for(x = i; x < N; x++){
                for(y = j; y < N; y++){
                    TempSum = 0;
                    /*Traverse addition*/
                    for(a = i; a <= x; a++){
                        for(b = j; b <= y; b++){
                            TempSum += A[a][b];
                        }
                        if(TempSum > MaxSum){
                        MaxSum = TempSum;
                        }
                    }
                }
             }
        }
    }
    return MaxSum;
}
/*
 * Description: avoid part of repetitive calculate work to realize
 * a faster algorithm with the time complexity N^4
 * ---------------------------------------------------------------
 * Input: a N*N integer matrix
 * Return: the maximum subsequence sum
 */
int algorithm2(int **A)
{
    int i, j;
    int x, y;
    int MaxSum = 0, TempSum[N], CurrentSum[N];
    /*Move the position of head*/
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            memset(TempSum, 0, N * sizeof(int));
            /*Traverse the matrix*/
            for(x = i; x < N; x++){
                memset(CurrentSum, 0, N * sizeof(int));
                for(y = j; y < N; y++){
                    CurrentSum[y] += A[x][y];
                    /*After the fist line*/
                    if(y > j){
                        CurrentSum[y] += CurrentSum[y-1];
                    }
                    if(x == i){
                        TempSum[y] = CurrentSum[y];
                    }
                    if(x > i){
                        TempSum[y] += CurrentSum[y];
                    }
                    if(TempSum[y] > MaxSum){
                        MaxSum = TempSum[y];
                    }
                }
            }
        }
    }
    return MaxSum;
}
/*
 * Description: store the middle calculating result of the process
 * to save time of repeated calculate
 * ---------------------------------------------------------------
 * Input: a N*N integer matrix
 * Return: the maximum subsequence sum
 */
int algorithm3(int **A)
{
    int i, j, k;
    int MaxSum = 0, TempSum[N], CurrentSum[N];
    memset(TempSum, 0, N * sizeof(int));
    memset(CurrentSum, 0, N * sizeof(int));
    /*The start row*/
    for(i = 0; i < N; i++){
        memset(TempSum, 0, N * sizeof(int));
        /*The end row*/
        for(k = 0; k < N; k++){
            memset(CurrentSum, 0, N * sizeof(int));
            /*Use a online algrithm by moving the fist column*/
            for(j = i; j < N; j++){
                CurrentSum[j] += A[j][k];
                if(j > i){
                    CurrentSum[j] += CurrentSum[j - 1];
                }
                if(k == 0){
                    TempSum[j] = CurrentSum[j];
                }
                if(k > 0){
                    TempSum[j] += CurrentSum[j];
                }
                if(TempSum[j] > MaxSum){
                    MaxSum = TempSum[j];
                }else if(TempSum[j] < 0){
                    TempSum[j] = 0;
                }
            }
        }
    }
    return MaxSum;
}
