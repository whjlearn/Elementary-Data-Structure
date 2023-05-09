#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define N 10

//��̬�ġ�
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType a[N];
//	int top;
//}ST;

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);

void StackDestroy(ST* ps);
//��ջ
void StackPush(ST* ps,STDataType x);
//��ջ
void StackPop(ST* ps);

//ȡջ����Ԫ��
STDataType StackTop(ST* ps);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);

//ջ���ж�������
int StackSize(ST* ps);