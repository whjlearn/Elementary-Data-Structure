#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//打印
void SLPrint(SL* ps)
{
	assert(ps != NULL);
	int i = 0;
	for ( i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//初始化
void SLInit(SL* ps)
{
	assert(ps != NULL);

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//检查
void SLCheckCapacity(SL* ps)
{
	assert(ps != NULL);

	//检查容量空间，满了扩容
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));//newCapacity是数据的个数 sizeof(SLDataType)每一个数据的大小
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//结束程序
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	/*assert(ps != NULL);

	SLCheckCapacity(ps);*/
	//ps->a[ps->size] = x;
	//ps->size++;

	SLInsert(ps, ps->size, x);
}

//尾删 --size
void SLPopBack(SL* ps)
{
	/*assert(ps != NULL);

	assert(ps->size>0);

	ps-> size--;*/

	SLErase(ps,ps->size-1);
}

//头插
void SLPushFront(SL* ps,SLDataType x)
{
	/*assert(ps != NULL);

	SLCheckCapacity(ps); */
	//挪动数据
	/*int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;*/

	SLInsert(ps,0,x);
	

 }


//头删
void SLPopFront(SL* ps)
{
	/*assert(ps != NULL);

	assert(ps->size>0);*/
	//int i = 0;
	//for (i = 0; i < ps->size-1; i++)
	//{
	//	ps->a[i] = ps->a[i + 1];
	//}
	/*int begin = 1;
	while (begin< ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;*/

	SLErase(ps,0);
}

//任意位置插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps!=NULL);
	assert(pos >=0 && pos <= ps->size);
	SLCheckCapacity(ps);

	int end = ps->size - 1;
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

//任意位置删除
void SLErase(SL* ps, int pos)
{
	assert(ps != NULL);
	assert(pos >= 0 && pos < ps->size);
	
	/*int begin = pos;
	while (begin < ps->size-1)
	{
		ps->a[begin] = ps->a[begin + 1];
		++begin;
	}*/

	int begin = pos+1;
	while (begin < ps->size )
	{
		ps->a[begin-1] = ps->a[begin];
		++begin;
	}

	ps->size--;

}

//查找
int SLFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		assert(ps);
		if (ps->a[i]==x)
		{
			return i;
		}
	}
	return -1;
}
//修改
void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos>=0&&pos< ps->size);
	ps->a[pos] = x;
}