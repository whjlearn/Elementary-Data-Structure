#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once //防止头文件被重复包含


//静态顺序表，太小不够用，太大浪费空间

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//指向动态数组的指针
	int size;//数据个数
	int capacity;//容量-空间大小
}SL;

void SLCheckCapacity(SL* ps);//检查Capacity

void SLPrint(SL* ps);//打印 

//增删查改
void SLInit(SL* ps);//初始化

//O(1)
//尾插
void SLPushBack(SL* ps,SLDataType x);
//尾删
void SLPopBack(SL* ps);

//O(N)时间复杂度
//头插
void SLPushFront(SL* ps, SLDataType x);
//头删
void SLPopFront(SL* ps);

//任意的位置插入删除
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//查找和修改
//查找
int SLFind(SL* ps,SLDataType x );
//修改
void SLModify(SL* ps, int pos,SLDataType x);