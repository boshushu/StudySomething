#include "For_Algorithm.h"


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