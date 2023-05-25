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


//�������� Ҫ�Ż� ����ȡ��

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

//�������� 
//void QuickSort(int* a, int begin,int end)
//{
//
//	//���䲻���� ����  ֻ��һ��ֵ  ����Ҫ�ٴ���
//	if (begin>=end)
//	{
//		return;
//	}
//	
//	//int keyi = PartSort1(a,begin,end);
//
//	//int keyi = PartSort2(a, begin, end);//�ڿӷ�
//
//	//ǰ��ָ�뷨
//	int keyi = PartSort3(a, begin, end);//�ڿӷ�
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


//С�����Ż�
void QuickSort(int* a, int begin, int end)
{

	//���䲻���� ����  ֻ��һ��ֵ  ����Ҫ�ٴ���
	if (begin >= end)
	{
		return;
	}
	if (end-begin>10)
	{
		int keyi = PartSort3(a, begin, end);//�ڿӷ�

		QuickSort(a, begin, keyi - 1);

		QuickSort(a, keyi + 1, end);
	}
	else
	{
		//������С��ʮ��ʱ�� ���ò�������
		InsertSort(a + begin, end - begin + 1);
	}

	//int keyi = PartSort1(a,begin,end);

	//int keyi = PartSort2(a, begin, end);//�ڿӷ�

	
	
}

//Hoare �ķ���
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


//�ڿӷ�

int PartSort2(int* a,int begin,int end )
{
	int key = a[begin];
	int piti = begin;//��λ
	while (begin<end)
	{
		//�ұ���С  
		while(begin<end&& a[end]>=key)
		{
			--end;
		}
		//�ҵ��ŵ���λ�� ���� ���¿�λ
		a[piti] = a[end];
		piti = end;

		//����Ҵ�
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

//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int keyi = begin;
	int prev = begin;
	int cur = begin + 1;
	
	
	//����ȡ���Ż�
	//GetMidIndex(a,begin,end)
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[midi], &a[keyi]);


	while (cur<=end)
	{
		//cur ��С �������ֱ��������  ��cur ��һֱ������
		if (a[cur] < a[keyi] && ++prev != cur)//cur�ҵ�С��keyi���ݵ�ֵ ++prev  Ȼ���жϴ�ʱ��prev�Ƿ��cur�ص� ��ֹ�Լ����Լ���  ����Ч�� ++prev!=cur ��ֹ�Լ����Լ��� 
			Swap(&a[cur],&a[prev]);
		++cur;
	}

	Swap(&a[prev],&a[keyi]);
	keyi = prev;
	return keyi;
}

//��ϰ��������

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

	//������
	_MergeSort(a, begin, mid, tmp);
	//������
	_MergeSort(a, mid + 1, end, tmp);
	//�ϰ�����ڽ��л���
///////////////////////////////////////////////////
	//�鲢
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1<=end1&&begin2<=end2)//�������� ��һ�����������
	{
		if (a[begin1]<a[begin2])
		{
			tmp[i++] = a[begin1++];//�������� ˭��ֵС �ͷŽ� tmp ���ú���������
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	//�ߵ����� ����һ�������Ѿ�������
	//������һ��û�н���������
	while (begin1<=end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//�ѹ鲢���� ������ԭ����
	//��������俽����ȥ
	//[begin][mid] [mid+1][end]
	//�鲢���Ƕ� �Ϳ���ȥ�Ķ�
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//�鲢���򣬷ֶ���֮
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