#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
typedef int LTDateType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDateType date;
}LTNode;

//struct List
//{
//	LTNode* phead;
//	int size;
//};

//声明
//LTNode* BuyListNode(LTDateType x);

//遍历
void ListPrint(LTNode* phead);
//void ListInit(LTNode** pphead);
LTNode* ListInit();
void ListPushBack(LTNode* phead,LTDateType x);
void ListPushFront(LTNode* phead, LTDateType x);

void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);
bool ListEmpty(LTNode* phead);

//插入
//在pos位置之前插入数据
void ListInsert(LTNode* pos,LTDateType x);
//删除pos位置的结点
void ListErase(LTNode* pos);

//求链表的长度
int ListSize(LTNode* phead);

//链表销毁
void ListDestory(LTNode* phead);