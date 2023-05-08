#include"List.h"


//void TestList1()
//{
//	//LTNode* plist = NULL;
//	//ListInit(&plist);
//
//	LTNode* plist = ListInit();
//	ListPushFront(plist,1);
//	ListPrint(plist);
//
//	ListPushBack(plist,2);
//	ListPushBack(plist,3);
//	ListPushBack(plist,4);
//	ListPushBack(plist,5);
//	ListPushBack(plist, 6);
//	ListPushBack(plist, 7);
//	ListPushBack(plist, 8);
//
//	ListPrint(plist);
//
//}

//Í·²å
//void TestList1()
//{
//	//LTNode* plist = NULL;
//	//ListInit(&plist);
//
//	LTNode* plist = ListInit();
//	ListPushFront(plist, 1);
//	ListPushFront(plist, 2);
//	ListPushFront(plist, 3);
//	ListPushFront(plist, 4);
//	ListPushFront(plist, 5);
//
//
//
//
//	ListPrint(plist);
//
//}
//Î²É¾
//void TestList1()
//{
//	//LTNode* plist = NULL;
//	//ListInit(&plist);
//
//	LTNode* plist = ListInit();
//	ListPushFront(plist,1);
//	ListPushBack(plist,2);
//	ListPushBack(plist,3);
//	ListPrint(plist);
//
//	ListPopBack(plist); 
//	ListPrint(plist);
//	ListPopBack(plist);
//	ListPrint(plist);
//
//	ListPopBack(plist);
//	ListPrint(plist);
//	printf("123    ");
//	ListPushFront(plist, 1);
//
//	ListPushBack(plist, 3);
//	ListPushBack(plist, 3);
//	ListPrint(plist);
//
//
//	/*ListPopBack(plist);
//	ListPrint(plist);*/
//}

void TestList1()
{
	//LTNode* plist = NULL;
	//ListInit(&plist);

	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);

	ListPrint(plist);

	//ListPushBack(plist, 2);
	//ListPushBack(plist, 3);
	//ListPrint(plist);
	//ListPopFront(plist);


}

void TestList2()
{
	//LTNode* plist = NULL;
	//ListInit(&plist);

	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);

	ListPushFront(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	printf("É¾³ý¿ÕÁË");

	//ListPushBack(plist, 2);
	//ListPushBack(plist, 3);
	//ListPrint(plist);
	//ListPopFront(plist);


}

void TestList3()
{
	//LTNode* plist = NULL;
	//ListInit(&plist);

	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPrint(plist);

	int ret = ListSize(plist);
	printf("%d", ret);
}

int main()
{
	TestList3();
	return 0;
}