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


//快速排序 要优化 三数取中

int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin]<a[mid])
	{
		if (a[mid]<a[end])
		{
			return mid;
		}
		else if (a[end]>a[begin])
		{
			return end;
		}
		else
		{
			return begin;
		} 
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}else if (a[begin]<a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

//快速排序 
//void QuickSort(int* a, int begin,int end)
//{
//
//	//区间不存在 或者  只有一个值  则不需要再处理
//	if (begin>=end)
//	{
//		return;
//	}
//	
//	//int keyi = PartSort1(a,begin,end);
//
//	//int keyi = PartSort2(a, begin, end);//挖坑法
//
//	//前后指针法
//	int keyi = PartSort3(a, begin, end);//挖坑法
//
//	QuickSort(a, begin, keyi - 1);
//
//	QuickSort(a, keyi+1, end);
//
//
//	
//
//	
//}


//小区间优化
void QuickSort(int* a, int begin, int end)
{

	//区间不存在 或者  只有一个值  则不需要再处理
	if (begin >= end)
	{
		return;
	}
	if (end-begin>10)
	{
		int keyi = PartSort3(a, begin, end);//挖坑法

		QuickSort(a, begin, keyi - 1);

		QuickSort(a, keyi + 1, end);
	}
	else
	{
		//当区间小于十的时候 次用插入排序
		InsertSort(a + begin, end - begin + 1);
	}

	//int keyi = PartSort1(a,begin,end);

	//int keyi = PartSort2(a, begin, end);//挖坑法

	
	
}

//Hoare 的方法
int  PartSort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int key = left;
	while(left<right)
	{
		while (left<right&&a[right]>=a[key])
		{
			--right;
		}
		while(left <right&&a[left]<=a[key])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return	key = left;
}


//挖坑法

int PartSort2(int* a,int begin,int end )
{
	int key = a[begin];
	int piti = begin;//坑位
	while (begin<end)
	{
		//右边找小  
		while(begin<end&& a[end]>=key)
		{
			--end;
		}
		//找到放到坑位里 并且 更新坑位
		a[piti] = a[end];
		piti = end;

		//左边找大
		while(begin<end&&a[begin]<=key)
		{
			++begin;
		}
		a[piti] = a[begin];
		piti = begin;
	}
	a[piti] = key;
	
	return piti;

}

//前后指针法
int PartSort3(int* a, int begin, int end)
{
	int keyi = begin;
	int prev = begin;
	int cur = begin + 1;
	
	
	//三数取中优化
	//GetMidIndex(a,begin,end)
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[midi], &a[keyi]);


	while (cur<=end)
	{
		//cur 找小 遇到大的直接往后走  ：cur 会一直往后走
		if (a[cur] < a[keyi] && ++prev != cur)//cur找到小于keyi内容的值 ++prev  然后判断此时的prev是否跟cur重叠 防止自己跟自己换  降低效率 ++prev!=cur 防止自己跟自己换 
			Swap(&a[cur],&a[prev]);
		++cur;
	}

	Swap(&a[prev],&a[keyi]);
	keyi = prev;
	return keyi;
}

//复习快速排序

//void QuickSort(int* a,int begin,int end )
//{
//	if (begin>=end)
//	{
//		return;
//	}
//	int left = begin;
//	int keyi = left;
//	int right = end;
//	while (left<right)
//	{
//		while (left<right&&a[right]>a[keyi])
//		{
//			--right;
//		}
//
//		while (left<right && a[left]<a[keyi])
//		{
//			++left;
//		}
//
//		Swap(&a[left], &a[right]);
//	}
//
//	Swap(&a[left], &a[keyi]);
//	keyi = left;
//	QuickSort( a, begin, keyi - 1);
//	QuickSort(a, keyi + 1, end);
//}

void _MergeSort(int* a,int begin,int end,int* tmp )
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;

	//左区间
	_MergeSort(a, begin, mid, tmp);
	//右区间
	_MergeSort(a, mid + 1, end, tmp);
	//上半边是在进行划分
///////////////////////////////////////////////////
	//归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1<=end1&&begin2<=end2)//两个区间 有一个结束则结束
	{
		if (a[begin1]<a[begin2])
		{
			tmp[i++] = a[begin1++];//两个区间 谁的值小 就放进 tmp 中让后各自向后走
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//走到这里 则有一个区间已经结束了
	//处理另一个没有结束的区间
	while (begin1<=end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//把归并数据 拷贝回原数组
	//把这段区间拷贝回去
	//[begin][mid] [mid+1][end]
	//归并的那段 就拷回去哪段
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//归并排序，分而治之
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp==NULL)
	{
		perror("malloc is fail\n");
		exit(-1);
	}
	_MergeSort(a,0,n-1,tmp);
	free(tmp);
	
}