#include"List.h"
void TestList1()
{
	//LTNode* plist = NULL;
	//ListInit(&plist);

	LTNode* plist = ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	ListPushBack(plist,4);
	ListPushBack(plist,5);

}
int main()
{
	TestList1();
	return 0;
}