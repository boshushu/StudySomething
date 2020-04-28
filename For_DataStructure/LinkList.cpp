#include "LinkList.h"

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

int LinkList::Insert(Node *p)
{
	Node *tmp;
	head->next = tmp;
	for (int i = 0; i < length; i++)
	{
		tmp = tmp->next;
	}
	tmp->next = p;
	p->next = nullptr;
	++length;

	return 0;
}
int LinkList::Insert(int pos, Node *p)
{
	return 0;
}
