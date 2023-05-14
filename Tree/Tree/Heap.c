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

//���ϵ���  С���� //����ʱ
void AdjustUp(HPDataType* a,int child )//�����鵱�� �����ڵ�λ��   ����  �����Һ���-1��/2
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child]<a[parent])//С��
		//if (a[child] > a[parent])//���

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
		//����
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
	//���ϵ���
	AdjustUp(php->a, php->size-1);
}

//���µ���
void AdjustDown(HPDataType* a,int size,int parent)
{
	//if (size<2)
	//{
	//	return 0;
	//}
	int child = parent * 2 + 1;//����
	
	while (child<size)
	{
		if (child + 1 < size && a[child+1]<a[child])// С��  ���ڴ��������������ݣ��Һ��ӵ��������±�+1
		//if (child + 1 < size && a[child + 1] > a[child])//���
		{
			++child;
		}

		//�ߵ����� child������С�ĺ���
		if (a[child] < a[parent])//С��   ���ӱȸ��׶�С������
		//if (a[child] > a[parent])//���
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;//���ױ���С�ĺ��Ӷ�С�����㣬���˳�
		}
		

	}
}

//ɾ��
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	
	//����ͷ��β������
	Swap(&(php->a[0]),&(php->a[php->size-1]));
	//ɾ�����һ������
	php->size--;

	//���µ���
	AdjustDown(php->a,php->size,0);
}

//ȡ�Ѷ�������
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