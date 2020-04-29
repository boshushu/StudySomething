#pragma once
#include "For_Algorithm.h"
#include <stack>
/*
ð������
ʱ�临�Ӷ� O(n^2)
*/
int BubbleSort(int* Array, int iLen)
{
	for (int i = 0; i < iLen; i++)
		for (int j = i; j < iLen; j++)
		{
			if (Array[i] > Array[j])
				swap(Array[i], Array[j]);
		}
	return 0;
}


/*
ѡ������
ʱ�临�Ӷ� O(n^2)
*/
int SelectSort(int* Array, int iLen)
{
	for (int i = 0; i < iLen - 1; i++)
	{
		int MinValue= Array[i];
		for (int j = i + 1; j < iLen; j++)
		{
			if (MinValue> Array[j])
				swap(MinValue, Array[j]);
		}
		Array[i] = MinValue;
	}
	return 0;
}



/*
��������
ʱ�临�Ӷ� O(n^2)
*/
int InsertSort(int* Array, int iLen)
{
	for (int i = 1; i < iLen; i++)
	{
		/* ����һ,��ǰԪ����ǰһ��Ԫ�رȽϣ������<ǰ���򽻻�����֮�������������*/
		/*for (int j = i; j >= 0&& (Array[j-1] > Array[j]); --j)
		{
			int tmp = Array[j];
			Array[j] = Array[j - 1];
			Array[j - 1] = tmp;
		}*/

		//����������ǰԪ��<ǰ��Ԫ�أ���ǰ��Ԫ��˳�������ƣ�ֱ����>��ǰλ�Ƶ�Ԫ�أ���ֱ�ӽ����ֵ�Ԫ�ز���(������Ԫ���Ѻ���)
		int tmp = Array[i], j = 0;
		for (j = i; (j >= 0) && (Array[j - 1] > tmp); --j)
		{
			Array[j] = Array[j - 1];
		}
		Array[j] = tmp;

	}
	return 0;
}


/*
ϣ������
ʱ�临�Ӷ� O(n^2)
*/
int ShellSort(int* Array, int iLen)
{
	for (int i = iLen / 2; i > 0; i /= 2)	//������
	{
		for (int j = i; j < iLen; j++)
		{
			/* ��������������*/
			/*for (int k = j; k >= 0 && (Array[k - i] > Array[k]); k-=i)
			{
				int tmp = Array[k];
				Array[k] = Array[k - i];
				Array[k - i] = tmp;
			}*/


			//��������λ�Ʒ���������
			int tmp = Array[j], k = 0;
			for (k = j; (k >= 0) && (Array[k - i] > tmp); k -= i)
			{
				Array[k] = Array[k - i];
			}
			Array[k] = tmp;
		}
	}
	return 0;
}

/*
��������
ʱ�临�Ӷ� O(Nlog2(N))
*/
int DivisionArray(int* Array, int Left, int Right)
{
	//ѡ����׼��a
	int BaseNum = Array[Left];
	while (Left < Right)
	{
		while ((Left < Right) && (Array[Right] >= BaseNum))	//�����ҿ�ʼ�������Ȼ�׼����ķ��ұ�
			--Right;
		Array[Left] = Array[Right];		//swap(Array[Left], Array[Right]);

		while ((Left < Right) && (Array[Left] <= BaseNum))	//������ʼ�����Ȼ�׼��С�ķ����
			++Left;
		Array[Right] = Array[Left];		//swap(Array[Left], Array[Right]);
	}
	Array[Left] = BaseNum;				//����swap,�˴���ע��
	return Left;
}

int QuickSort(int* Array, int Left, int Right)
{
	if (Left < Right)
	{
		int i = DivisionArray(Array, Left, Right);
	
		QuickSort(Array, Left, i - 1);

		QuickSort(Array, i + 1, Right);
	}

	return 0;
}

//�ǵݹ�
void qSort(int lst[], int length)
{
	stack<pair<int, int>> mystack;
	mystack.push(make_pair(0, length - 1));

	while (!mystack.empty())
	{
		pair<int, int> top = mystack.top();
		mystack.pop();
		
		int i = top.first, j = top.second;
		int BaseNum = lst[i];

		while (i < j)
		{
			while ((i < j) && (lst[j] >= BaseNum)) j--;
			swap(lst[i], lst[j]);

			while ((i < j) && (lst[i] <= BaseNum)) i++;
			swap(lst[i], lst[j]);
		}

		if (i > top.first) mystack.push(make_pair(top.first, i - 1));
		if (j < top.second) mystack.push(make_pair(j + 1, top.second));
	}
}
