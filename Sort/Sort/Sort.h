#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


void ArryPrint(int* a, int n);
//直接插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//冒泡排序
void BubbleSort(int *a,int n );

//快速排序
void QuickSort(int* a, int begin, int end);


//归并排序
void MergeSort(int* a, int n);

//归并排序 非递归写法
void MergeSortNonR(int* a, int n);


//计数排序
void CountSort(int* a, int n);