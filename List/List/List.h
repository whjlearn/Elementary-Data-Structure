#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
typedef int LTDateType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDateType date;
}LTNode;

//ÉùÃ÷
LTNode* BuyListNode(LTDateType x);

//void ListInit(LTNode** pphead);
LTNode* ListInit();
void ListPushBack(LTNode* phead,LTDateType x);