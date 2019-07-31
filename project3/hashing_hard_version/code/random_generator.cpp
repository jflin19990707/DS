#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(int argc ,char **argv){
	//generating a random hash table
	srand(time(0));
	int N, M;
	if(argc == 1)
		scanf("%d", &N);
	else
		N = atoi(argv[1]);
	M = rand() % (N / 2) + N / 2; //to guarantee the hash table isn't too emptys
	int *T = (int*)malloc(sizeof(int) * N);
	printf("%d\n", N);
	for(int i = 0; i < N; i ++) T[i] = -1;
	for(int i = 0; i < M; i ++){
		int K = rand() % N;
		K = K < N / 2 ? K : K + N / 2; //to enlarge the chance to make collision
		int j = K % N;
		for(; T[j] != -1 && T[j] != K; j = (j + 1) % N); //build a hash table
		T[j] = K;
	}
	for(int i = 0; i < N; i ++) printf("%d ", T[i]); //print the hash table
}
