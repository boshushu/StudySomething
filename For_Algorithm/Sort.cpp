#include "For_Algorithm.h"

/*
冒泡排序
算法复杂度 O(n)
*/
int BubbleSort(int* Array, int iLen)
{
	for (int i = 0; i < iLen - 1; i++)
	{
		if (Array[i] > Array[i + 1])
			swap(Array[i], Array[i + 1]);
	}
	return 0;
}


/*
选择排序
算法复杂度 O(n^2)
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
O(n^2)
*/
int InsertSort(int* Array, int iLen)
{
	for (int i = 1; i < iLen; i++)
	{
		/* 方法一,当前元素与前一个元素比较，如果后<前，则交换；反之，该轮排序完成
		for (int j = i - 1; (j > 0) && (Array[j] < Array[i]); --j)
		{
			int tmp = Array[i];
			Array[i] = Array[j];
			Array[j] = tmp;
		}
		*/
	
		//方法二：当前元素<前面元素，则前面元素顺序往后移，直到后>当前位移的元素，则直接将该轮的元素插入(因其他元素已后移)
		int tmp = Array[i], j = 0;
		for (j = i - 1; (j > 0) && (Array[j] < Array[i]); --j)
		{
			Array[i] = Array[j];
		}
		Array[j] = tmp;
	}
	return 0;
}
