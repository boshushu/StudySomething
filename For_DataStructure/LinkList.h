#pragma once
#include <iostream>
using namespace std;

typedef struct _NODE
{
	int value;
	_NODE *next;
}Node, *pNode;

class LinkList 
{
public:
	LinkList();
	~LinkList();

	int GetLen();
	int GetValue(int pos);

	int Insert(int value);
	int Insert(int pos, int value);
	int Remove();
	int Remove(int pos);

private:
	Node *head;
	int length;
	

};
