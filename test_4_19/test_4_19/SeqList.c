#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//��ӡ
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
//��ʼ��
void SLInit(SL* ps)
{
	assert(ps != NULL);

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//���
void SLCheckCapacity(SL* ps)
{
	assert(ps != NULL);

	//��������ռ䣬��������
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));//newCapacity�����ݵĸ��� sizeof(SLDataType)ÿһ�����ݵĴ�С
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//��������
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
}

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	/*assert(ps != NULL);

	SLCheckCapacity(ps);*/
	//ps->a[ps->size] = x;
	//ps->size++;

	SLInsert(ps, ps->size, x);
}

//βɾ --size
void SLPopBack(SL* ps)
{
	/*assert(ps != NULL);

	assert(ps->size>0);

	ps-> size--;*/

	SLErase(ps,ps->size-1);
}

//ͷ��
void SLPushFront(SL* ps,SLDataType x)
{
	/*assert(ps != NULL);

	SLCheckCapacity(ps); */
	//Ų������
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


//ͷɾ
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

//����λ�ò���
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

//����λ��ɾ��
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

//����
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
//�޸�
void SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos>=0&&pos< ps->size);
	ps->a[pos] = x;
}