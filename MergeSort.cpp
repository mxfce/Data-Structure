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
void merge_arr(int arr[], int low, int mid, int high)
{
	int l = low;
	int h = mid + 1;
	int temp[1000];
	int index = low;
	while(l <= mid && h <= high)
	{
		if(arr[l] < arr[h])
		{
			temp[index] = arr[l];
			l++;
		}
		else
		{
			temp[index] = arr[h];
			h++;
		}
		index++;
	}
	if(l > mid)
	{
		for(int i = h; i <= high; ++i)
		{
			temp[index] = arr[i];
			index++;
		}
	}

	else
	{
		for(int i = l; i <= mid; ++i)
		{
			temp[index] = arr[i];
			index++;
		}
	}
	for(int i = low; i <= high; ++i)
	{
		arr[i] = temp[i];
	}
}
void partition(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		partition(arr, low, mid);
		partition(arr, mid + 1, high);
		merge_arr(arr, low, mid, high);
	}
}
void mergeSort(int arr[], int low, int high)
{
	partition(arr, low, high);
}
int main()
{
	int arr[] = {1,5,2,2,7};
	mergeSort(arr,0,4);
	printArr(arr,5);
}
