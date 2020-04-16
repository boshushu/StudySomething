#include "For_Algorithm.h"


/*
KMP�㷨
*/
int KMP(char *p_Text, char *p_Pattern)
{
	bool bIsPat = false;
	int iIndex[2] = { 0,0 };
	iIndex[0] = 0, iIndex[1] = strlen(p_Pattern);

	for (int i = 0; i < strlen(p_Text); i++)
	{
		if ((p_Pattern[iIndex[0]] == p_Text[iIndex[0]]) 
			&& (p_Pattern[iIndex[1]] == p_Text[iIndex[1]]))
		{
			for (int j = 0; j < iIndex[1]; j++)
			{
				if (p_Text[j] == p_Pattern[j])
				{
					bIsPat = true; continue;
				}
				else
				{
					bIsPat = false, iIndex[0] += j, iIndex[1] += j;
				}
			}
			if (bIsPat == true)
				return i;
			else
				continue;
		}
		
		if (p_Pattern[iIndex[0]] == p_Text[iIndex[0]]) 
		{
			for (int j = 1; j < iIndex[1]; j++)
			{
				if (p_Text[j] != p_Pattern[j])
				{
					iIndex[0] += j, iIndex[1] += j;
					break;
				}
			}
		}
	}
	return -1;
}



/*
BM�㷨
*/
int BMSearch(char *p_Str, char *p_Pat)
{
	return 0;
}



/*
Sunday�㷨
��ǰ����ƥ�䣬��ƥ��ʧ��ʱ��ע�����ı����вμ�ƥ�����ĩλ�ַ�����һλ�ַ���
 */
int IsBitInStr(char a, char* b)
{
	for (int i = 0; i < strlen(b); i++)
		if (a == b[i])
			return i;
	return -1;
}

int SundaySearch(char *p_Str, char *p_Pat)
{
	int iIndex = 0, iLength = strlen(p_Pat);
	bool bIsPat = false;
	while (iIndex < (strlen(p_Str) - iLength))
	{
		for (int j = 0; j < iLength; j++)
		{
			if (p_Str[j + iIndex] == p_Pat[j])
				bIsPat = true;
			else
			{
				//1.������ַ�û����ģʽ���г�����ֱ�����������ƶ�λ�� = ƥ�䴮���� + 1;
				//2.�������ƶ�λ�� = ģʽ�������Ҷ˵ĸ��ַ���ĩβ�ľ���+1;
				int tmpIndex = IsBitInStr(p_Str[iIndex + iLength], p_Pat);
				iIndex += ((-1 == tmpIndex) ? (iLength + 1) : tmpIndex);
				bIsPat = false;
				break;
			}
		}

		if (bIsPat == true)
			return iIndex;
	}
	return -1;
}
