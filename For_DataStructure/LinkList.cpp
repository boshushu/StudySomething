#include "LinkList.h"
using namespace std;

LinkList::LinkList()
{
	if (head == nullptr)
	{
		head = new Node;
		head->next = nullptr;
		length = 0;
	}
}

LinkList::~LinkList()
{
	if (head != nullptr)
		delete head;
}

int LinkList::GetLen()
{
	if (head->next == nullptr)
		return -1;
	return length;
}

int LinkList::GetValue(int pos)
{
	Node *p = head;
	int cnt = 0;

	if (pos > length || length == 0)
		return -1;

	while (p->next != nullptr&&cnt++ != pos)
	{
		p = p->next;
	}

	return p->value;
}

int LinkList::Insert(int value)
{
	Node *p = head;
	Node *newNode = new Node;
	
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = newNode;
	newNode->value = value;
	newNode->next = nullptr;
	++length;

	return 0;
}

int LinkList::Insert(int pos, int value)
{
	Node *p = head;
	Node *newNode = new Node;
	int cnt = 0;
	if (pos > length)
		return -1;
	
	while (p->next != nullptr&&++cnt != pos)
	{
		p = p->next;
	}
	newNode->next = p->next;
	newNode->value = value;
	p->next = newNode;
	++length;

	return 0;
}

int LinkList::Remove()
{
	Node *p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}

	p->next = nullptr;
	--length;
	return 0;
}

int LinkList::Remove(int pos)
{
	Node *p = head;
	int cnt = 0;
	while (p->next != nullptr &&cnt++ != pos)
	{
		p = p->next;
	}
	p->next = p->next->next;
	--length;
	return 0;
}
