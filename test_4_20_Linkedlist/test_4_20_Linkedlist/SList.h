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
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
//尾删
void SListPopBack(SLTNode** pphead);

//头插
void SListPushFront(SLTNode** pphead, SLTDataType x);
//头删
void SListPopFront(SLTNode** pphead);
//查找
SLTNode* SListFind(SLTNode* phead ,SLTDataType x);

//在pos位置之前插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);

// 在pos位置之后插入
void SListInsertAfter(SLTNode * pos, SLTDataType x);

//删除pos位置之后的值
void SListErase(SLTNode* pos);
