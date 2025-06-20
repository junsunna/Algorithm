#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int masic_squares[8][9] = {
	{8, 3, 4, 1, 5, 9, 6, 7, 2},
	{4, 9, 2, 3, 5, 7, 8, 1, 6},
	{2, 7, 6, 9, 5, 1, 4, 3, 8},
	{6, 1, 8, 7, 5, 3, 2, 9, 4},
	{4, 3, 8, 9, 5, 1, 2, 7, 6},
	{2, 9, 4, 7, 5, 3, 6, 1, 8},
	{6, 7, 2, 1, 5, 9, 8, 3, 4},
	{8, 1, 6, 3, 5, 7, 4, 9, 2},
};
/*
8 3 4
1 5 9
6 7 2

4 3 8
9 5 1
2 7 6

4 9 2
3 5 7
8 1 6

2 9 4
7 5 3
6 1 8

2 7 6
9 5 1
4 3 8

6 7 2
1 5 9
8 3 4

6 1 8
7 5 3
2 9 4

8 1 6
3 5 7 
4 9 2 
*/

int main(void)
{
	int grid[3][3];
	int n = 3;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}
	int MinCost = 55;
	int c = 8;
	while (c--)
	{
		int cost = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++) {
				cost += abs(grid[i][j] - masic_squares[c][(i * n) + j]);
			}
		}
		if (cost < MinCost) {
			MinCost = cost;
		}
	}
	printf("%d", MinCost);



	return 0;
}