#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define FORI(start,end,k) for(int i = start; i < end; i += k)
#define FORJ(start,end,k) for(int j = start; j < end; j += k)
#define RFORI(start,end,k) for(int i = start; i >= end; i += k)
#define RFORJ(start,end,k) for(int j = start; j >= end; j += k)
using namespace std;
class Sort
{
	private:
		const int INF = numeric_limits<int>::max() - 1;
	public:
		//utility
		void swap(int *a,int *b)
		{
			int tmp = *a;
			*a = *b;
			*b = tmp;
		}
		void array_to_string(int A[],int n)
		{
			FORI(0,n,1)
			{
				printf("%d ",A[i]);
			}
			printf("\n");
		}
		//sorting
		void selective_sort(int A[],int n)
		{

			FORI(0,n,1)
			{
				int lowest = INF;
				int lowest_pos = -1;
				FORJ(i,n,1)
				{
					if(A[j] < lowest)
					{

						lowest = A[j];
						lowest_pos = j;
					}
				}
				//printf("lowest = %d\n",lowest);
				//printf("swap %d %d\n",i,lowest_pos);
				swap(&A[i],&A[lowest_pos]);
			}
		}
		void bubble_sort(int A[],int n)
		{
			RFORI(n-2,0,-1)
			{
				FORJ(0,i+1,1)
				{

					if(A[j] > A[j+1])
					{
						//printf("%d > %d\n",A[j],A[j+1]);
						swap(&A[j],&A[j+1]);
					}
				}
			}
		}
		void insertion_sort(int A[],int n)
		{
			FORI(1,n,1)
			{
				int curr = A[i];
				int j = i - 1;
				//printf("sorted pos : %d\n",j);
				while(j > 0 && curr < A[j])
				{
					//printf("swap %d %d\n",A[j],A[j+1]);
					A[j+1] = A[j];
					j--;
				}
				A[j+1] = curr;
			}

		}
		void merge(int A[],int start,int mid,int end)
		{
			int B[100000] = {0};
			int left = start;
			int right = mid+1;
			int k = 0;
			while(left <= mid && right <= end)
			{
				if(A[left] < A[right])
				{
					B[k] = A[left];
					left++;
				}
				else
				{
					B[k] = A[right];
					right++;
				}
				k++;
			}
			while(left <= mid)
			{
				B[k] = A[left];
				left++;
				k++;
			}
			while(right <= end)
			{
				B[k] = A[right];
				right++;
				k++;
			}
			//array_to_string(B,10);
			for(int i = 0; i < k; ++i)
			{
				A[start] = B[i];
				start++;
			}
		}
		void merge_sort(int A[],int start,int end)
		{
			int mid = (start+end) / 2;
			//printf("start :%d ,mid : %d, end %d \n\n\n",start,mid,end);
			if(start < end)
			{
				merge_sort(A,start,mid);
				merge_sort(A,mid+1,end);
				merge(A,start,mid,end);
			}
		}
		int qs_merge(int A[],int start,int end)
		{
			int pivot = start;
			int store_index = pivot + 1;
			for(int i = store_index; i <= end; ++i)
			{
				if(A[i] < A[pivot])
				{
					swap(&A[i],&A[store_index]);
					store_index++;
				}
			}
			swap(&A[pivot],&A[store_index-1]);
			//printf("%d\n",store_index);
			return store_index-1;
		}
		void quick_sort(int A[],int start,int end)
		{

			if(start < end)
			{
				int pivot = qs_merge(A,start,end);
				quick_sort(A,start,pivot-1);
				quick_sort(A,pivot+1,end);

			}
		}

};
//display array

int main()
{
	Sort sort;
	int A[] = {8, 16, 6, 17, 12, 14, 4, 20, 11, 9};
	sort.quick_sort(A,0,9);
	sort.array_to_string(A,10);
    return 0;
}
