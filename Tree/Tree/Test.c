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
int main()
{
	int a[] = { 27,19,18,15,74,12,15,48,79 };

	HeapSort(a,sizeof(a)/sizeof(int));
	//HedpTest();
	return 0;
}