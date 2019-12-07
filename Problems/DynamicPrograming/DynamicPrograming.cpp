// DynamicPrograming.cpp : 定义控制台应用程序的入口点。
#pragma once
#include "stdafx.h";
#include"DynamicPrograming.h"
using namespace std;

int MaxProfit::maxProfit(vector<int>& prices) {
	int iMinPrice = prices[0];
	int iMaxPro = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < iMinPrice)
		{
			iMinPrice = prices[i];
			continue;
		}

		iMaxPro = max(iMaxPro, prices[i] - iMinPrice);
	}

	return iMaxPro;
};

int MaxProfitII::maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
	{
		return 0;
	}

	int iBuyPri = prices[0];
	int iSellPri = iBuyPri;
	int iBonus = 0;
	bool bBuy = false;


	for (int i = 1; i < prices.size(); i++)
	{
		if (iBuyPri >= prices[i])
		{
			iBuyPri = prices[i];
			iSellPri = iBuyPri;
		}

 		if (iSellPri <= prices[i])
		{
			if (!bBuy)
			{
				iBuyPri = iSellPri;
				bBuy = true;
			}

			iSellPri = prices[i];
		}

		int iNxt = i + 1;
		if ((iNxt == prices.size() - 1 && iSellPri > prices[iNxt]) 
			|| iNxt > prices.size() - 1)
		{
			iBonus += iSellPri - iBuyPri;
			return iBonus;
		}
		else if (iSellPri > prices[iNxt])
		{
			iBonus += iSellPri - iBuyPri;
			iBuyPri = iSellPri = prices[i + 1];
			bBuy = false;
		}
	}

	return iBonus;
}

int MaxProfitII::maxProfitII(vector<int>& prices)
{
	int iBonus = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		int iTmp = prices[i] - prices[i - 1];
		if (iTmp > 0)
		{
			iBonus += iTmp;
		}
	}

	return iBonus;
}

int MaxProfitIII::maxProfit(vector<int>& prices)
{
	return -1;
}

int DJJS::rob(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	int* ptr = new int[nums.size()];
	if (nums.size() == 1)
	{
		return ptr[0];
	}

	ptr[0] = nums[0];

	if (nums.size() == 2)
	{
		ptr[1] = max(ptr[0], nums[1]);
		return ptr[1];
	}

	ptr[1] = max(ptr[0], nums[1]);

	for (int i = 2; i < nums.size(); i++)
	{
		ptr[i] = max(ptr[i - 1], ptr[i - 2] + nums[i]);
	}

	return ptr[nums.size() -1];
}

int DJJS::robII(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	int iFirst = nums[0];
	if (nums.size() == 1)
	{
		return iFirst;
	}

	int iSecond = max(iFirst, nums[1]);
	if (nums.size() == 2)
	{
		return iSecond;
	}

	int iTmp = 0;
	for (int i = 2; i < nums.size(); i++)
	{
		iTmp = iSecond;
		iSecond = max(iSecond, iFirst + nums[i]);
		iFirst = iTmp;
	}

	return iSecond;
}

bool JudgeSubsequence::isSubsequence(string s, string t)
{
	if (s == "")
	{
		return true;
	}

	if (t == "")
	{
		return false;
	}

	int iSize = s.size();
	int j = 0;

	for (int i = 0; i < t.length(); i++)
	{
		if (t[i] != s[j])
		{
			continue;
		}

		j++;
		if (j == iSize)
		{
			return true;
		}
	}

	return false;
}

int LeastCostJump::minCostClimbingStairs(vector<int> &cost)
{
	int iFirst = cost[0];
	int iSecond = min(cost[1], iFirst);
	int iTmp = 0;
	for (int i = 2; i < cost.size(); i++)
	{
		iTmp = iSecond;
		iSecond = min(iFirst + cost[i], iSecond);
		iFirst = iTmp;
	}
	
	return iSecond;
}

string LongestSubStr::longestPalindrome(string s)
{
	if (s == "")
	{
		return "";
	}

	int iStart = 0;
	int iMax = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int j = 0;
		while ((i - j) >= 0 && (i + j) <= s.size() - 1 && s[i - j] == s[i + j])
		{
			j++;
		}

		int k = 0;
		while ((i - k) >= 0 && (i + 1 + k) <= s.size() - 1 && s[i - k] == s[i + 1 + k])
		{
			k++;
		}

		int iTmpMax = max(2 * j - 1, 2 * k <= 0 ? 1 : 2 * k);
		if (iTmpMax > iMax)
		{
			iStart = i;
			iMax = iTmpMax;
		}
	}

	return iMax % 2 == 0 ? s.substr(iStart - iMax / 2 + 1, iMax) : s.substr(iStart - iMax / 2, iMax);
}

int MaxRectangle::maximalRectangle(vector<vector<char>>& matrix)
{
	int iRow = matrix.size();
	int iCol = matrix[0].size(); 
	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iCol; j++)
		{
			char s = matrix[i][j];
			if (s == '0')
			{
				continue;
			}

			int iTmpi = 0;
			int iTmpj = 0;
			for (; i + iTmpi < iRow; iTmpi++)
			{

			}
		}
	}

	return -1;
}

int DifferentPath::uniquePathsI(int m, int n)
{
	vector<vector<int>> iVec(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		iVec[i][0] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		iVec[0][i] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			iVec[i][j] = iVec[i - 1][j] + iVec[i][j - 1];
		}
	}

	return iVec[m - 1][n - 1];
}

int DifferentPath::uniquePathsOptimizeI(int m, int n)
{
	vector<int> iVec(n);
	for (int i = 0; i < n; i++)
	{
		iVec[i] = 1;
	}
	
	for (int i = 1; i < m; i++)
	{
		int iTmpLeft = 1;
		for (int j = 1; j < n; j++)
		{
			iVec[j] = iVec[j] + iTmpLeft;
			iTmpLeft = iVec[j];
		}
	}

	return iVec[n - 1];
}

int DifferentPath::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();

	vector<int> iVec(n);
	bool oObs = false;
	for (int i = 0; i < n; i++)
	{
		if (obstacleGrid[0][i] == 1 || oObs)
		{
			oObs = true;
			iVec[i] = 0;
		}
		else
		{
			iVec[i] = 1;
		}
	}

	for (int i = 1; i < m; i++)
	{
		int iTmpLeft = 0;
		for (int j = 0; j < n; j++)
		{
			iVec[j] = obstacleGrid[i][j] == 1 ? 0 : iVec[j] + iTmpLeft;
			iTmpLeft = iVec[j];
		}
	}

	return iVec[n - 1];
}

int MinPath::minPathSum(vector<vector<int>>& grid)
{
	int m = grid.size();
	int n = grid[0].size();

	vector<int> iVec(n);
	int iSum = 0;
	for (int i = 0; i < n; i++)
	{
		iSum += grid[0][i];
		iVec[i] = iSum;
	}

	for (int i = 1; i < m; i++)
	{
		int iLeft = 0;
		for (int j = 0; j < n; j++)
		{
			int iTmp = j == 0 ? iVec[j] : min(iLeft, iVec[j]);
			iVec[j] = iTmp + grid[i][j];
			iLeft = iVec[j];
		}
	}

	return iVec[n - 1];
}
