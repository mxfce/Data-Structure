#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;
void swap(int *x ,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void printArr(int *pItr, int size)
{
	for(int i = 0; i < size; ++i)
	{
		printf("%d ",*(pItr + i));
	}
	printf("\n");
}
int main()
{
	int arrA[] = {1,6,2,8,1,2};
	int size = 6;
	for(int i = 0; i < size - 1; ++i)
	{
		int *min = &arrA[i];
		for(int j = i + 1; j < size; ++j)
		{
			if(arrA[j] < *min)
				swap(min, &arrA[j]);
		}
	}
	printArr(arrA,size);
}
