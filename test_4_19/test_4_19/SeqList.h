#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once //��ֹͷ�ļ����ظ�����


//��̬˳���̫С�����ã�̫���˷ѿռ�

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;//ָ��̬�����ָ��
	int size;//���ݸ���
	int capacity;//����-�ռ��С
}SL;

void SLCheckCapacity(SL* ps);//���Capacity

void SLPrint(SL* ps);//��ӡ 

//��ɾ���
void SLInit(SL* ps);//��ʼ��

//O(1)
//β��
void SLPushBack(SL* ps,SLDataType x);
//βɾ
void SLPopBack(SL* ps);

//O(N)ʱ�临�Ӷ�
//ͷ��
void SLPushFront(SL* ps, SLDataType x);
//ͷɾ
void SLPopFront(SL* ps);

//�����λ�ò���ɾ��
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//���Һ��޸�
//����
int SLFind(SL* ps,SLDataType x );
//�޸�
void SLModify(SL* ps, int pos,SLDataType x);