#include"List.h"

//创建结点
LTNode* BuyListNode(LTDateType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc is fail");
		exit(-1);//终止程序
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

//尾插
void ListPushBack(LTNode* phead, LTDateType x);