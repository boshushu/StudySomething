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

	int Insert(Node *p);
	int Insert(int pos, Node *p);
	int Remove();
	int Remove(int pos);

private:
	Node *head;
	int length;

};
