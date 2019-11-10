// MaxSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSubArr(vector<int> iVec)
{
	int iTmpMax = 0;
	int iCurMax = INT_MIN;
	for (int i = 0; i < iVec.size(); i++)
	{
		iTmpMax += iVec[i];
		if (iTmpMax > iCurMax)
		{
			iCurMax = iTmpMax;
		}
		if (iTmpMax < 0)
		{
			iTmpMax = 0;
		}
	}

	return iCurMax;
}


int MaxSubArr2(vector<int> ivec)
{
	int iDP[100];
	iDP[0] = ivec[0];
	int iMax = ivec[0];
	for (int i = 1; i < ivec.size(); i++)
	{
		if (iDP[i - 1] < 0)
		{
			iDP[i] = ivec[i];
		}
		else
		{
			iDP[i] = iDP[i - 1] + ivec[i];
		}

		iMax = max(iMax, iDP[i]);
	}

	return iMax;
}

int main()
{
	vector<int> iVec = { -2,1,-3,4,-1,2,1,-5,4 };
	int i = MaxSubArr2(iVec);
		
    return 0;
}



