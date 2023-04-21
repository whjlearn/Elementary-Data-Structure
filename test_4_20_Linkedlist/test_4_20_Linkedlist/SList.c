#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur!=NULL)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BySListNode(SLTDataType x)
{

	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);

	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


//尾插1.找到尾巴
void SListPushBack(SLTNode* *pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾结点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}
//尾删
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);

	assert(*pphead != NULL);
	
	if ((*pphead)->next==NULL)
	{//这种情况只有一个结点
		free(*pphead);
		*pphead = NULL;

	}
	else
	{
		//第一种写法
		SLTNode* tailPrev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tailPrev = tail;
			tail = tail->next;
		}
		tailPrev->next = NULL;
		free(tail);
		tail = NULL;

		//第二种写法
		/*SLTNode* tail = *pphead;
		
		while (tail->next->next!=NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/


	}
	
	
}


//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = BySListNode(x);
		newnode->next = *pphead;
		*pphead = newnode;

}
//头删
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);
	assert(pphead);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//查找  既可以查找也可以修改
SLTNode* SListFind(SLTNode* phead,SLTDataType x)
{
	
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos位置之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);//pos不能为空 做检查
	assert(pphead);
	//如果插入的位置等于pphead 调用头插即可
	if (pos==*pphead)
	{
		SListPushFront(pphead,x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode =  BySListNode(x);
		prev->next = newnode;       //newnode = prev;
		newnode->next = pos;
	}

}

//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead&&pos);
	if (*pphead==pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next!= pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}
