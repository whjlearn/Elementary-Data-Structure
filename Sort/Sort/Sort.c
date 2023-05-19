#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


void ArryPrint(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//插入排序
void InsertSort(int* a, int n)//n 表示数组个数
{
	for (int i = 0; i < n-1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}

//希尔排序
//void ShellSort(int* a, int n)
//{
//	int gap = 3;
//	for (int  j = 0; j < gap; j++)
//	{
//		for (int i = j; i < n - gap; i += gap)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//				
//			}
// a[end + gap] = tmp;
//		}
//	}
//}


void ShellSort(int* a,int n)
{
	//gap > 1 时 是 预排序
	//gap 最后一次等于 1 ，是直接插入排序
	int gap = n;

	while (gap>1)
	{
		gap = gap / 3 + 1;//加个1 保证最后一次一定是 1
		for (size_t i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}

			}

			a[end + gap] = tmp;
		}
	}
	
	
	
	
}

	




void Insert(int* a,int n)
{
	for ( int i = 0; i < n; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
	
}
void Swap(int* a,int* b )
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//直接选择排序
void SelectSort(int* a, int n)
{
	assert(a);

	int begin = 0;
	int end = n - 1;
	while (begin<end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		
		Swap(&a[begin], &a[mini]);
		//如果begin 跟maxi重叠了，那么需要修正maxi 的位置
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
	
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	assert(a);
	for (int j = 0; j < n - 1; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n-j; ++i)
		{
			if (a[i-1] > a[i])
			{
				Swap(&a[i-1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
	
}

//快速排序
void QuickSort(int* a, int begin,int end)
{

	//区间不存在 或者  只有一个值  则不需要再处理
	if (begin>=end)
	{
		return;
	}
	
	int left = begin,right = end;
	int keyi = left;
	

	while (left<right)
	{
		//右边找小,右边先走，找小
		while (left<right && a[right] >= a[keyi])
		{
			--right;
		}

		//左边找大，左边后走，找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);//相等时left = right

	keyi = left;

	QuickSort(a, begin, keyi - 1);

	QuickSort(a, keyi+1, end);

	
	
}