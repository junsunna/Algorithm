#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, a, b;
	int* arr;
	int i, tmp;
	scanf("%d%d", &N, &M);
	// 메모리 할당 및 0 초기화
	arr = (int*)malloc(N * sizeof(int));
	// memset(arr, 0, sizeof(int) * 10);
	//할당 실패 시 리턴
	if (arr == NULL) 
		return -1;
	for (i = 0; i < N; ++i) 
		arr[i] = i+1;
	for (i = 0; i < M; ++i) {
		scanf("%d%d", &a, &b);
		a--, b--;
		for (;  a < b; --b, ++a) {
			tmp = arr[a];
			arr[a] = arr[b];
			arr[b] = tmp;
		}
	}
	for (i = 0; i < N; ++i)
		printf("%d ", arr[i]);
	
	
	free(arr);

	return 0; 
}