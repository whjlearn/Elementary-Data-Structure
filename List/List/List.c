#include"List.h"

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
void ListPushBack(LTNode* phead, LTDateType x);