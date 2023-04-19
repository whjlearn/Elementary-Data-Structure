#define _CRT_SECURE_NO_WARNINGS 1
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数
#include<stdio.h>
//void revers(int *arr,int left ,int right)
//{
//	while (left<right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		++left;
//		--right;
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	int k = 3;
//	k %= n;
//	revers(arr,0,n-k-1);
//	revers(arr, n-k, n-1);
//	revers(arr,0,n-1);
//	for ( i = 0; i <n; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//
//
//	return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////
#include"SeqList.h"
void TestSeqList1()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1,5);
	SLPushBack(&s1,5);
	SLPushBack(&s1,5);
	SLPushBack(&s1,5);
	
	SLPushBack(&s1,5);
	SLPrint(&s1);
	SLPushBack(&s1, 5);
	SLPushBack(&s1, 5);
	SLPrint(&s1);
}
void TestSeqList2()
{
	SL s1;
	SLInit(&s1);//不要忘记初始化
	SLPushFront(&s1, 5);
	SLPushFront(&s1, 4);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 2);
	SLPushBack(&s1, 15);
	SLPrint(&s1);
	SLPushFront(&s1, 1);
	SLPushFront(&s1, -1);
	SLPushFront(&s1, 5);
	SLPushFront(&s1, 4);
	SLPrint(&s1);
}
void TestSeqList3()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);

	SLPushBack(&s1, 5);
	SLPrint(&s1);
	SLPopBack(&s1);
	SLPrint(&s1);
	SLPopBack(&s1);
	SLPrint(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);
	SLPopBack(&s1);

}

void TestSeqList4()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPushFront(&s1, 12);
	SLPrint(&s1);
	SLErase(&s1,0);
	SLPrint(&s1);

	
	SLPopFront(&s1);
	SLPrint(&s1);
	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPrint(&s1);


}


void TestSeqList5()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	SLPrint(&s1);

	SLPopFront(&s1);
	SLPrint(&s1);

	SLPopBack(&s1);
	SLPrint(&s1);
	
	


}

int main()
{
	TestSeqList5();
	return 0;
}