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
	bool swapped;
	int last = 6;
	do
	{
		swapped = false;
		for(int i = 1; i < last; ++i)
		{
			int *left = &arrA[i - 1];
			int *right = &arrA[i];
			if(*left > *right)
			{
				swap(left,right);
				swapped = true;
			}
		}
		last--;
	}
	while(swapped);
	printArr(arrA,6);
		
}
