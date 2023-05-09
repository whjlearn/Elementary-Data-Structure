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
//�����
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


//������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	//ֻ��һ�����
	if (pq->head->next==NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;

	}
	else//������
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//ȡ ��ͷ ������
QDataType QueueFront(Queue* pq)
{ 
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;

}

//ȡ ��β ������
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