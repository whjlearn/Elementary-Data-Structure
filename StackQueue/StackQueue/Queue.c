#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* del = cur->next;
		free(cur);
		cur = del;
	}
	pq->head = pq->tail = NULL;
}
//入队列
void QueuePush(Queue* pq, QDataType x)
{
		assert(pq);
	
		QNode* newnode = (QNode*)malloc(sizeof(QNode));
		if (newnode == NULL)
		{
			printf("malloc is fail\n");
			exit(-1);
		}
		newnode->data = x;
		newnode->next = NULL;
		if(pq->tail == NULL)
		{
			pq->head = pq->tail = newnode;
		}
		else
		{
			pq->tail->next = newnode;
			pq->tail = newnode;
		}
		
	
}


//出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	//只有一个结点
	if (pq->head->next==NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;

	}
	else//多个结点
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//取 队头 的数据
QDataType QueueFront(Queue* pq)
{ 
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;

}

//取 队尾 的数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

//
int QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}