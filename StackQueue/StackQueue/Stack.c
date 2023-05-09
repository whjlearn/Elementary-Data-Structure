#include"Stack.h"

void StackInit(ST* ps)
{//��ʼ��
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//��ջ
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top==ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4:ps->capacity*2 ;
		//******
		STDataType* tmp =(STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc is fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	//�жϲ�Ϊ����ɾ��
	assert(!StackEmpty(ps));
	ps->top--;
}

//ȡջ����Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	//��Ԫ�ز���
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];//����ջ��Ԫ��
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//ջ���ж�������
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}