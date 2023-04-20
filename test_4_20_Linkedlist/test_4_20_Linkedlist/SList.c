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


//β��1.�ҵ�β��
void SListPushBack(SLTNode* *pphead, SLTDataType x)
{
	SLTNode* newnode = BySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//��β���
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}
//βɾ
void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);
	
	if ((*pphead)->next==NULL)
	{//�������ֻ��һ�����
		free(*pphead);
		*pphead = NULL;

	}
	else
	{
		//��һ��д��
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

		//�ڶ���д��
		/*SLTNode* tail = *pphead;
		
		while (tail->next->next!=NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/


	}
	
	
}


//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BySListNode(x);
		newnode->next = *pphead;
		*pphead = newnode;

}
//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//����  �ȿ��Բ���Ҳ�����޸�
SLTNode* SListFind(SLTNode* phead,SLTDataType x)
{
	assert(phead);
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
