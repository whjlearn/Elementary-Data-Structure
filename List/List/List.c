#include"List.h"

//����
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d ",cur->date);
		cur = cur->next;
	}
	printf("\n");
}

//�������
LTNode* BuyListNode(LTDateType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc is fail");
		exit(-1);//��ֹ����
	}
	node->date = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//void ListInit(LTNode** pphead) {
//   *pphead = BuyListNode(-1);
//   (*pphead)->next = *pphead;
//   (*pphead)->prev = *pphead;
//}
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//β��
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	/*LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/


	ListInsert(phead, x);

}
//ͷ��
void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);

	//LTNode* newnode = BuyListNode(x);

	//LTNode* head = phead->next;
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = head;
	//head->prev = newnode;


	ListInsert(phead->next, x);
}

//βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next!=phead);
	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;
	//free(tail);

	//tailPrev->next = phead;
	//phead->prev = tailPrev;
	ListErase(phead->prev);
	
}
//ͷɾ
void ListPopFront(LTNode* phead)
{
	
	assert(phead);
	assert(phead->next != phead);


	//LTNode* head = phead->next;
	//LTNode* next = head->next;
	//phead->next = next;
	//next->prev = phead;
	//free(head);

	ListErase(phead->next);
}

//�ж�
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

//��posλ��֮ǰ��������
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}
//ɾ��posλ�õĽ��
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;

}

int ListSize(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	int size = 0;
	while (cur!=phead)
	{
		cur = cur->next;
		++size;
	}
	return size;
}

//��������
void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		LTNode* next = cur->next;
		ListErase(cur);
		cur = next;
	}
	free(phead);
}