#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"

void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 ,0,-1};
	int size = sizeof(a) / sizeof(int);
	InsertSort(a, size);

	ArryPrint(a, size);
}

void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5  };
	int size = sizeof(a) / sizeof(int);
	printf("%d ", size);
	printf("\n");
	ShellSort(a,size);

	ArryPrint(a, size);
}

void TestShellSort1()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int size = sizeof(a) / sizeof(int);
	printf("%d ", size);
	printf("\n");
	ShellSort(a, size);
	ArryPrint(a, size);
}

void TestSelectSort1()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int size = sizeof(a) / sizeof(int);
	printf("%d ", size);
	printf("\n");
	SelectSort(a, size);
	ArryPrint(a, size);
}

void TestBubbleSort1()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	int size = sizeof(a) / sizeof(int);
	printf("%d ", size);
	printf("\n");
	BubbleSort(a, size);
	ArryPrint(a, size);
}


void TestQuickSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int size = sizeof(a) / sizeof(int);
	//printf("%d ", size);
	printf("\n");
	QuickSort(a, 0,size-1);
	ArryPrint(a, size);
}

void TestPart3Sort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int size = sizeof(a) / sizeof(int);
	//printf("%d ", size);
	printf("\n");
	PartSort3(a, 0, size - 1);
	ArryPrint(a, size);
}


int main()
{
	//TestInsertSort();
	//printf("\n");
	//TestShellSort1();
	//printf("haha");
	//TestSelectSort1();
	//TestBubbleSort1();
	TestQuickSort();
	//TestPart3Sort();
	return 0;
}