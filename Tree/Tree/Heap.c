#include"Heap.h"
#include<time.h>

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


void HeapPrint(HP* php)
{
	assert(php);
	for (int  i = 0; i < php->size; ++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}


void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

//向上调整  小堆序 //插入时
void AdjustUp(HPDataType* a,int child )//在数组当中 父亲在的位置   等于  （左右孩子-1）/2
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child]<a[parent])//小堆
		//if (a[child] > a[parent])//大堆

		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
		
	}
	
}
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size==php->capacity)
	{
		//扩容
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp =(HPDataType*) realloc(php->a,sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		php->a= tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;
	//向上调整
	AdjustUp(php->a, php->size-1);
}

//向下调整
void AdjustDown(HPDataType* a,int size,int parent)
{
	//if (size<2)
	//{
	//	return 0;
	//}
	int child = parent * 2 + 1;//左孩子
	
	while (child<size)
	{
		if (child + 1 < size && a[child+1]<a[child])// 小堆  在内存中是连续的数据，右孩子等于左孩子下标+1
		//if (child + 1 < size && a[child + 1] > a[child])//大堆
		{
			++child;
		}

		//走到这里 child就是最小的孩子
		if (a[child] < a[parent])//小堆   孩子比父亲都小，交换
		//if (a[child] > a[parent])//大堆
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//父亲比最小的孩子都小，满足，则退出
		}
		

	}
}

//删除
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	
	//交换头和尾的数据
	Swap(&(php->a[0]),&(php->a[php->size-1]));
	//删除最后一个数据
	php->size--;

	//向下调整
	AdjustDown(php->a,php->size,0);
}

//取堆顶的数据
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}