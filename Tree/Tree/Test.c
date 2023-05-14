#include"Heap.h"
void HedpTest()
{
	int a[] = { 27,19,18,15,74,12,15,48,79 };


	int size = sizeof(a) / sizeof(a[0]);
	//printf("%d", size);
	HP hp ;
	HeapInit(&hp);
	
	for (int i = 0; i <size-1 ; ++i)
	{
		HeapPush(&hp,a[i]);
	}
	HeapPrint(&hp);
	//HeapDestroy(&hp);

	//�����ӡ -- С��
	//�����ӡ -- ���

	//ȡ�Ѷ���Ԫ�� ���Դﵽ ��С��������
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);//ɾ���Ѷ���Ԫ�� 
	}
	
}

void HeapSort(int* a,int n )
{
	////���� ��ʽһ
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i); //���ϵ���

	//}
	//���� ��ʽ��  ������һ�� ��Ҷ�ӽڵ�  =  ����һ�����ĸ���� ��child-1��/2
	for (int i =( n-1-1)/2; i >=0; --i)
	{
		AdjustDown(a, n,i); //���ϵ���

	}
}

///////////////////////////////////////
// 
// 
//Top k ����
void PrintTopK(int* a, int n, int k)
{
	// 1. ����--��a��ǰk��Ԫ�ؽ���

	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻
	int* kMinHeap =(int*) malloc(sizeof(int) * k);
	assert(kMinHeap);
	for (int i = 0; i < k; ++i)
	{
		kMinHeap[i] = a[i];
	}

	//������
	for (int i = (k-1-1)/2; i >= 0; --i)
	{
		AdjustDown(kMinHeap, k, i);
	}

	// 2. ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�ؽ��������������滻

	for (int j = k; j < n; ++j)
	{
		if (a[j]>kMinHeap[0])
		{
			kMinHeap[0] = a[j];

			AdjustDown(kMinHeap, k, 0);

		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", kMinHeap[i]);
	}
	printf("\n");
}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand()%1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK( a, n, 10);
}



int main()
{
	//int a[] = { 27,19,18,15,74,12,15,48,79 };

	//HeapSort(a,sizeof(a)/sizeof(int));
	//HedpTest();


	TestTopk();
	return 0;
}