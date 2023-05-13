#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int HPDataType;
typedef struct HeaP
{
	HPDataType* a;
	int size;
	int capacity;
}HP;


void HeapPrint(HP* php);
void Swap(HPDataType* p1, HPDataType* p2);
void HeapInit(HP* php);
void HeapDestroy(HP* php);
//
void HeapPush(HP* php, HPDataType x);

//删除堆顶的元素
void HeapPop(HP* php);

//取堆顶的数据
HPDataType HeapTop(HP* php);

bool HeapEmpty(HP* php);
int HeapSize(HP* php);

//向下调整
void AdjustDown(HPDataType* a, int size, int parent);

//向上调整
void AdjustUp(HPDataType* a, int child);//在数组当中 父亲在的位置   等于  （左右孩子-1）/2
