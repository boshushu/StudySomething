#pragma once

#include <iostream>
using namespace std;


/*
File: BitCount.cpp
Func: �����������1�ĸ���
*/
unsigned int BitCount(unsigned int n);
unsigned int BitCount2(unsigned int n);
unsigned int BitCount3(unsigned int n);
unsigned int BitCount_0(unsigned int n);

/*
File: KMP.cpp
Func: KMP�㷨ʵ��
*/
int KMP(char *p_Text, char *p_Pattern);
int BMSearch(char *p_Str, char *p_Pat);
int SundaySearch(char *p_Str, char *p_Pat);


/*
File: BFS_And_DFS.cpp
Func: BFS��DFS�㷨ʵ��
*/
typedef struct _Node
{
	int value;
	bool bIsVisited;
	_Node *Left;
	_Node *Right;
} MyNode, p_MyNode;

int BFS(struct _Node *p_Node);
int DFS(struct _Node *p_Node);


/*
File:	Sort.cpp
*/
int BubbleSort(int* Array, int iLen);
int SelectSort(int* Array, int iLen);
int InsertSort(int* Array, int iLen);
