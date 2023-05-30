#include <iostream>
using namespace std;
//퀵정렬
int n, cnt, quick[10000001];

void quickSort(int i, int j)
{
	if (i >= j) return;

	int pivotValue = quick[(i + j) / 2];
	int leftIndex = i;
	int rightIndex = j;

	int LeftValue = 0;
	int RightValue = 0;

	while (leftIndex <= rightIndex)
	{
		while ((LeftValue = quick[leftIndex]) < pivotValue)
		{
			leftIndex++;
		}


		while ((RightValue = quick[rightIndex]) > pivotValue)
		{
			rightIndex--;
		}

		if (leftIndex <= rightIndex)
		{
			swap(quick[leftIndex], quick[rightIndex]);
			leftIndex++; rightIndex--;
		}
	}
	quickSort(i, rightIndex);
	quickSort(leftIndex, j);
}

int main()
{
	//scanf_s("%d", &n);
	//for (int i = 0; i < n; i++)
	//scanf_s("%d", &quick[i]);

	n = 10;
	quick[0] = 4;
	quick[1] = 8;
	quick[2] = 2;
	quick[3] = 3;
	quick[4] = 9;
	quick[5] = 7;
	quick[6] = 1;
	quick[7] = 6;
	quick[8] = 10;
	quick[9] = 5;

	quickSort(0, n - 1);

	for (int j = 0; j < n; j++) // 출력
		printf("%d\n", quick[j]);
}
