// FindShortestSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct MyTmpStruct
{
	int iStart;
	int iEnd;
	int iCount;
};

int findShortestSubArray(vector<int>& nums) {
	map<int, MyTmpStruct> MapArr;
	int iMaxDim = 0;
	int iMinLen = nums.size();
	for (int i = 0; i < nums.size(); i++)
	{
		if (MapArr.count(nums[i]) == 0)
		{
			MyTmpStruct pTmp{0, 0, 0
			};

			pTmp.iStart = i;
			pTmp.iCount++;
			MapArr.insert(pair<int, MyTmpStruct>(nums[i], pTmp));
		}
		else
		{
			MyTmpStruct &pTmp = MapArr[nums[i]];
			pTmp.iCount++;
			pTmp.iEnd = i;
			int iCurLen = pTmp.iEnd - pTmp.iStart + 1;
			if (pTmp.iCount > iMaxDim)
			{
				iMaxDim = pTmp.iCount;
				iMinLen = iCurLen;
			}
			else if (pTmp.iCount == iMaxDim && iCurLen < iMinLen)
			{
				iMinLen = iCurLen;
			}
		}
	}

	return iMinLen;
}

int main()
{
	vector<int> iVec = { 2,1,1,2,1,3,3,3,1,3,1,3,2 };
	int i = findShortestSubArray(iVec);
    return 0;
}

