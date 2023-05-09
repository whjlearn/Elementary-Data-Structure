#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
//入队列
void QueuePush(Queue* pq,QDataType x);
//出队列
void QueuePop(Queue* pq);

//取 队头 的数据
QDataType QueueFront(Queue* pq);

//取 队尾 的数据
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);

//
int QueueSize(Queue* pq);

