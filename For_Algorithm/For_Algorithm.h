#pragma once

#include <iostream>
using namespace std;


/*
File: BitCount.cpp
Func: 计算整数里的1的个数
*/
unsigned int BitCount(unsigned int n);
unsigned int BitCount2(unsigned int n);
unsigned int BitCount3(unsigned int n);
unsigned int BitCount_0(unsigned int n);

/*
File: KMP.cpp
Func: KMP算法实现
*/
int KMP(char *p_Text, char *p_Pattern);
int BMSearch(char *p_Str, char *p_Pat);
int SundaySearch(char *p_Str, char *p_Pat);


/*
File: BFS_And_DFS.cpp
Func: BFS与DFS算法实现
*/
typedef struct _Node
{
	int value;
	_Node *Left;
	_Node *Right;
} MyNode, p_MyNode;

int BFS(struct _Node *p_Node);
int DFS(struct _Node *p_Node);
