#include "For_Algorithm.h"



int BFS(struct _Node *p_Node)
{
	return 0;
}



int DFS(struct _Node *p_Node)
{
	cout << "Node Value=" << p_Node->value << endl;
	p_Node->bIsVisited = true;

	if (p_Node->Left == NULL && p_Node->Right == NULL)
	{
		return 0;
	}

	if (p_Node->Left&&p_Node->bIsVisited == false)
	{
		DFS(p_Node->Left);
	}
	if (p_Node->Right&&p_Node->bIsVisited == false)
	{
		DFS(p_Node->Right);
	}
	return 0;
}