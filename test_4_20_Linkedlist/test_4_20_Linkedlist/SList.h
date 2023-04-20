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
//Œ≤≤Â
void SListPushBack(SLTNode** pphead, SLTDataType x);
//Œ≤…æ
void SListPopBack(SLTNode** pphead);

//Õ∑≤Â
void SListPushFront(SLTNode** pphead, SLTDataType x);
//Õ∑…æ
void SListPopFront(SLTNode** pphead);
//≤È’“
SLTNode* SListFind(SLTNode* phead ,SLTDataType x);
