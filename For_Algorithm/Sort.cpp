#include "For_Algorithm.h"

/*
ð������
�㷨���Ӷ� O(n)
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
ѡ������
�㷨���Ӷ� O(n^2)
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
O(n^2)
*/
int InsertSort(int* Array, int iLen)
{
	for (int i = 1; i < iLen; i++)
	{
		/* ����һ,��ǰԪ����ǰһ��Ԫ�رȽϣ������<ǰ���򽻻�����֮�������������
		for (int j = i - 1; (j > 0) && (Array[j] < Array[i]); --j)
		{
			int tmp = Array[i];
			Array[i] = Array[j];
			Array[j] = tmp;
		}
		*/
	
		//����������ǰԪ��<ǰ��Ԫ�أ���ǰ��Ԫ��˳�������ƣ�ֱ����>��ǰλ�Ƶ�Ԫ�أ���ֱ�ӽ����ֵ�Ԫ�ز���(������Ԫ���Ѻ���)
		int tmp = Array[i], j = 0;
		for (j = i - 1; (j > 0) && (Array[j] < Array[i]); --j)
		{
			Array[i] = Array[j];
		}
		Array[j] = tmp;
	}
	return 0;
}
