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
//�����
void QueuePush(Queue* pq,QDataType x);
//������
void QueuePop(Queue* pq);

//ȡ ��ͷ ������
QDataType QueueFront(Queue* pq);

//ȡ ��β ������
QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);

//
int QueueSize(Queue* pq);

