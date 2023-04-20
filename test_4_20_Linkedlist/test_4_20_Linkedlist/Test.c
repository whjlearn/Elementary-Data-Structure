#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void TestSList1()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);

	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n2);

	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n3);

	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n4);

	SLTNode* n5 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n5);

	SLTNode* n6 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n6);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;//最后一个元素指向空

	SLTNode* plist = n1;

	SListPrint(plist);
	SListPushBack(plist,8);
	SListPushBack(plist,9);
	SListPushBack(plist,10);
	SListPrint(plist);


}
void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist,8);
	SListPushBack(&plist,9);
	SListPushBack(&plist,10);
	SListPushBack(&plist,11);
	SListPrint(plist);
}
void TestSList3()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 9);
	
	SListPrint(plist);

	SListPushFront(&plist, 10);
	SListPushFront(&plist, 11);
	SListPrint(plist);
}
void TestSList4()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 9);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);
}

void TestSList5()
{
	SLTNode* plist = NULL;
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 9);
	SListPushFront(&plist, 10);
	SListPushFront(&plist, 11);

	SListPrint(plist);

	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);


}

int main()
{
	TestSList5();
	return 0;
}