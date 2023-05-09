#include"Stack.h"

void StackInit(ST* ps)
{//初始化
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
//进栈
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
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	//判断不为空再删除
	assert(!StackEmpty(ps));
	ps->top--;
}

//取栈顶的元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	//有元素才拿
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];//返回栈顶元素
}

//判断栈是否为空
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//栈里有多少数据
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}