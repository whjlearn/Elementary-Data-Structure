#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define N 10

//静态的、
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
//进栈
void StackPush(ST* ps,STDataType x);
//出栈
void StackPop(ST* ps);

//取栈顶的元素
STDataType StackTop(ST* ps);

//判断栈是否为空
bool StackEmpty(ST* ps);

//栈里有多少数据
int StackSize(ST* ps);