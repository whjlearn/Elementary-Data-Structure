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

	//升序打印 -- 小堆
	//降序打印 -- 大堆

	//取堆顶的元素 可以达到 从小到大排序
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);//删除堆顶的元素 
	}
	
}

void HeapSort(int* a,int n )
{
	////建堆 方式一
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i); //向上调整

	//}
	//建堆 方式二  倒数第一个 非叶子节点  =  最有一个数的父结点 （child-1）/2
	for (int i =( n-1-1)/2; i >=0; --i)
	{
		AdjustDown(a, n,i); //向上调整

	}
}
int main()
{
	int a[] = { 27,19,18,15,74,12,15,48,79 };

	HeapSort(a,sizeof(a)/sizeof(int));
	//HedpTest();
	return 0;
}