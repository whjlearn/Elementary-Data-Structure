#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;
typedef struct SListNodt
{
	SLTDataType data;
	struct SListNode* next;
} SLTNode;

void SListPrint(SLTNode* phead);

SLTNode* BySListNode(SLTDataType x);
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x);
//βɾ
void SListPopBack(SLTNode** pphead);

//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);
//ͷɾ
void SListPopFront(SLTNode** pphead);
//����
SLTNode* SListFind(SLTNode* phead ,SLTDataType x);
