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
//��������
void InsertSort(int* a, int n)//n ��ʾ�������
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

//ϣ������
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
	//gap > 1 ʱ �� Ԥ����
	//gap ���һ�ε��� 1 ����ֱ�Ӳ�������
	int gap = n;

	while (gap>1)
	{
		gap = gap / 3 + 1;//�Ӹ�1 ��֤���һ��һ���� 1
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

//ֱ��ѡ������
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
		//���begin ��maxi�ص��ˣ���ô��Ҫ����maxi ��λ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
	
}

//ð������
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

//��������
void QuickSort(int* a, int begin,int end)
{

	//���䲻���� ����  ֻ��һ��ֵ  ����Ҫ�ٴ���
	if (begin>=end)
	{
		return;
	}
	
	int left = begin,right = end;
	int keyi = left;
	

	while (left<right)
	{
		//�ұ���С,�ұ����ߣ���С
		while (left<right && a[right] >= a[keyi])
		{
			--right;
		}

		//����Ҵ���ߺ��ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);//���ʱleft = right

	keyi = left;

	QuickSort(a, begin, keyi - 1);

	QuickSort(a, keyi+1, end);

	
	
}