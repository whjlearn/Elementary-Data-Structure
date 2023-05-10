#include"Heap.h"

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

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size==php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp =(HPDataType*) malloc(sizeof(HPDataType) * newCapacity);
	}
	php->a[php->size] = x;
	php->size++;
}
void HeapPop(HP* php);

//取堆顶的数据
HPDataType HeapTop(HP* php);

bool HeapEmpty(HP* php);
int HeapSize(HP* php);