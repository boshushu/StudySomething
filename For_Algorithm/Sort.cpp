#pragma once
#include "For_Algorithm.h"
#include <stack>
/*
冒泡排序
时间复杂度 O(n^2)
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
选择排序
时间复杂度 O(n^2)
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
插入排序
时间复杂度 O(n^2)
*/
int InsertSort(int* Array, int iLen)
{
	for (int i = 1; i < iLen; i++)
	{
		/* 方法一,当前元素与前一个元素比较，如果后<前，则交换；反之，该轮排序完成*/
		/*for (int j = i; j >= 0&& (Array[j-1] > Array[j]); --j)
		{
			int tmp = Array[j];
			Array[j] = Array[j - 1];
			Array[j - 1] = tmp;
		}*/

		//方法二：当前元素<前面元素，则前面元素顺序往后移，直到后>当前位移的元素，则直接将该轮的元素插入(因其他元素已后移)
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
希尔排序
时间复杂度 O(n^2)
*/
int ShellSort(int* Array, int iLen)
{
	for (int i = iLen / 2; i > 0; i /= 2)	//定义间隔
	{
		for (int j = i; j < iLen; j++)
		{
			/* 交换法插入排序*/
			/*for (int k = j; k >= 0 && (Array[k - i] > Array[k]); k-=i)
			{
				int tmp = Array[k];
				Array[k] = Array[k - i];
				Array[k - i] = tmp;
			}*/


			//方法二：位移法插入排序
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
快速排序
时间复杂度 O(Nlog2(N))
*/
int DivisionArray(int* Array, int Left, int Right)
{
	//选定基准数a
	int BaseNum = Array[Left];
	while (Left < Right)
	{
		while ((Left < Right) && (Array[Right] >= BaseNum))	//从最右开始遍历，比基准数大的放右边
			--Right;
		Array[Left] = Array[Right];		//swap(Array[Left], Array[Right]);

		while ((Left < Right) && (Array[Left] <= BaseNum))	//从最左开始遍历比基准数小的放左边
			++Left;
		Array[Right] = Array[Left];		//swap(Array[Left], Array[Right]);
	}
	Array[Left] = BaseNum;				//如用swap,此处可注释
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

//非递归
void qSort(int lst[], int length)
{
	stack<pair<int, int>> mystack;
	mystack.push(make_pair(0, length - 1));

	while (!mystack.empty())
	{
		pair<int, int> top = mystack.top();
		mystack.pop();
		
		int i = top.first, int j = top.second;
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
