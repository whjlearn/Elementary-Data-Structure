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

//����
//LTNode* BuyListNode(LTDateType x);

//����
void ListPrint(LTNode* phead);
//void ListInit(LTNode** pphead);
LTNode* ListInit();
void ListPushBack(LTNode* phead,LTDateType x);
void ListPushFront(LTNode* phead, LTDateType x);

void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);
bool ListEmpty(LTNode* phead);

//����
//��posλ��֮ǰ��������
void ListInsert(LTNode* pos,LTDateType x);
//ɾ��posλ�õĽ��
void ListErase(LTNode* pos);

//������ĳ���
int ListSize(LTNode* phead);

//��������
void ListDestory(LTNode* phead);