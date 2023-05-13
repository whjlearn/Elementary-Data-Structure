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

//ɾ���Ѷ���Ԫ��
void HeapPop(HP* php);

//ȡ�Ѷ�������
HPDataType HeapTop(HP* php);

bool HeapEmpty(HP* php);
int HeapSize(HP* php);

//���µ���
void AdjustDown(HPDataType* a, int size, int parent);

//���ϵ���
void AdjustUp(HPDataType* a, int child);//�����鵱�� �����ڵ�λ��   ����  �����Һ���-1��/2
