// DynamicPrograming.cpp : 定义控制台应用程序的入口点。
#pragma once
#include "stdafx.h"
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

string LongestPalindromeSubStr::longestPalindrome(string s)
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

int DecodeMethod::numDecodings(string s)
{
	char a = '`';
	
	int iFirst = 0;
	int iSecond = 1;

	int iTmp = 0;
	for (int i = 2; i < s.size(); i++)
	{
		int iSub2 = stoi(s.substr(i - 2, 2));
		int iSub1 = stoi(s.substr(i - 1, 1));
		bool bChar = iSub2 <= 26 && iSub2 >= 1;
		iTmp = iSecond + (bChar ? iFirst : 0);
		iFirst = bChar ? iSecond : 0;
		iSecond = iTmp;
	}

	return iSecond;
}

int LongestSubStr::lengthOfLongestSubstring(string s)
{
	int iMax = 0;
	int iTmpMax = 0;
	string sTmpStr;
	for (int i = 0; i < s.size(); i++)
	{
		string sPos = s.substr(i, 1);
		int iFind = sTmpStr.find(sPos);
		if (iFind != -1)
		{
			iTmpMax = 0;
			sTmpStr = sTmpStr.substr(iFind + 1) + sPos;
			continue;
		}

		sTmpStr += sPos;
		iTmpMax = sTmpStr.size();
		if (iTmpMax > iMax)
		{
			iMax = iTmpMax;
		}
	}

	return iMax;
}

string Convert::convert(string s, int numRows)
{
	if (numRows == 1)
	{
		return s;
	}

	string *ptr = new string[numRows];
	int iRowCnt = 0;

	//// 正逆序判断
	bool bPositive = true;
	for (int i = 0; i < s.size(); i++)
	{
		ptr[iRowCnt] += s.substr(i, 1);
		if (bPositive)
		{
			//// 正序递增
			iRowCnt++;
			bPositive = iRowCnt == numRows - 1 ? false : true;
		}
		else
		{
			//// 逆序递减
			iRowCnt--;
			bPositive = iRowCnt == 0 ? true : false;
		}
	}

	string sResult;
	for (int i = 0; i < numRows; i++)
	{
		sResult = sResult + ptr[i];
	}

	return sResult;
}

int CommonSubstr::longestCommonSubsequence(string text1, string text2)
{
	int iCol = text1.size();
	int iRow = text2.size();
	vector<vector<int>> sVec(iRow + 1, vector<int>(iCol + 1, 0));
	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iCol; j++)
		{
			string sRow = text2.substr(i, 1);
			string sCol = text1.substr(j, 1);
			if (sRow == sCol)
			{
				sVec[i + 1][j + 1] = sVec[i][j] + 1;
			}
			else
			{
				sVec[i + 1][j + 1] = max(sVec[i][j + 1], sVec[i + 1][j]);
			}
		}
	}

	return sVec[iRow][iCol];
} 

int PivotIndex::pivotIndex(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return -1;
	}

	int iSumleft = 0;
	int iSumRight = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		iSumRight += nums[i];
	}

	if (iSumleft == iSumRight)
	{
		return 0;
	}

	int i = 1;
	for (; i < nums.size(); i++)
	{
		if (iSumleft != iSumRight)
		{
			iSumleft += nums[i - 1];
			iSumRight -= nums[i];
			continue;
		}
		
		return --i;
	}
	
	return iSumleft == iSumRight ? --i : -1;
}

int PivotIndex::pivotIndexI(vector<int>& nums)
{
	int sum = 0;
	int sumleft = 0;
	int len = size(nums);
	for (int i = 0; i<len; i++)
		sum += nums[i];
	for (int i = 0; i<len; i++)
	{
		if (sumleft * 2 + nums[i] == sum)
			return i;
		sumleft += nums[i];
	}

	return -1;
}


vector<int> SpiralOrder::spiralOrder(vector<vector<int>>& matrix)
{
	int iRow = matrix.size();
	int iCol = matrix[0].size();

	int iCnt = iRow * iCol;
	vector<int> vResult;
	int iStartRow = 0;
	int iStartCol = 0;
	int iEndRow = iRow - 1;
	int iEndCol = iCol - 1;
	while (iStartRow >= 0 && iStartRow <= iEndRow && iStartCol >= 0 && iStartCol <= iEndCol)
	{
		for (int i = iStartCol; i <= iEndCol; i++)
		{
			vResult.push_back(matrix[iStartRow][i]);
		}

		iStartRow++;

		for (int i = iStartRow; i <= iEndRow; i++)
		{
			vResult.push_back(matrix[i][iEndCol]);
		}

		iEndCol--;

		for (int i = iEndCol; i >= iStartCol; i--)
		{
			vResult.push_back(matrix[iEndRow][i]);
		}

		iEndRow--;

		for (int i = iEndRow; i >= iStartRow; i--)
		{
			vResult.push_back(matrix[i][iStartCol]);
		}

		iStartCol++;
	}
	
	while (vResult.size() > iCnt)
	{
		vResult.pop_back();
	}

	return vResult;
}

int MaxContainer::maxArea(vector<int>& height)
{
	int iSize = height.size();
	int iMax = 0;
	for (int i = 0; i < iSize; i++)
	{
		for (int j = i + 1; j < iSize; j++)
		{
			int iHeight = min(height[i], height[j]);
			int iWidth = j - i;
			if (iWidth * iHeight > iMax)
			{
				iMax = iWidth * iHeight;
			}
		}
	}

	return iMax;
}

int MaxContainer::maxAreaDoublePtr(vector<int>& height)
{
	int iStart = 0;
	int iSize = height.size();
	int iEnd = iSize - 1;
	int iResult = 0;
	while (iStart < iEnd)
	{
		iResult = max(min(height[iStart], height[iEnd]) * (iEnd - iStart), iResult);
		if (height[iStart] < height[iEnd])
		{
			iStart++;
		}
		else
		{
			iEnd--;
		}
	}

	return iResult;
}

vector<vector<int>> SumOfThree::threeSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int iCnt = nums.size();
	if (iCnt < 3 || nums[0] > 0 || nums[iCnt - 1] < 0)
	{
		return{};
	}

	vector<vector<int>> ResVec;
	for (int i = 0; i < iCnt - 2; i++)
	{

		//// 注意这一点
		if (nums[i] > 0)
		{
			break;
		}
		
		//// 这里同样要注意
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		
		int l = i + 1; 
		int r = iCnt - 1;
		while (l < r)
		{
			vector<int> iVec;
			if (nums[l] + nums[r] == -nums[i])
			{
				iVec.push_back(nums[l]);
				iVec.push_back(nums[r]);
				iVec.push_back(nums[i]);
				ResVec.push_back(iVec);
				l++;
				r--;
				while (l < r && nums[l] == nums[l - 1])
				{
					l++;
				}

				while (l < r && nums[r] == nums[r + 1])
				{
					r--;
				}
			}
			else if(nums[l] + nums[r] < -nums[i])
			{
				l++;
			}
			else
			{
				r--;
			}
		}
	}

	return ResVec;
}

int MinSubArr::minSubArrayLenWrong(int s, vector<int>& nums)
{
	int iCnt = nums.size();
	int iSum = 0;
	for (int i = 0; i < iCnt; i++)
	{
		iSum += nums[i];
	}

	if (iSum < s)
	{
		return 0;
	}

	int l = 0;
	int r = iCnt - 1;
	while (iSum >= s)
	{
		if (nums[l] < nums[r])
		{ 
			iSum -= nums[l];
			l++;
		}
		else if (nums[l] == nums[r])
		{
			if (nums[l + 1] < nums[r - 1])
			{
				iSum -= nums[l];
				l++;
			}
			else
			{
				iSum -= nums[r];
				r--;
			}
		}
		else
		{
			iSum -= nums[r];
			r--;
		}
	}

	//int iRes;
	//if (l == r && iSum >= s)
	//{

	//}
	return l == r ? 1 : r - l + 2;
}

int MinSubArr::minSubArrayLen(int s, vector<int>& nums)
{
	int iCnt = nums.size();
	int iSum = 0;
	for (int i = 0; i < iCnt; i++)
	{
		iSum += nums[i];
	}

	int iLeft = 0;
	int iRight = 0;
	int iRes = iCnt;
	iSum = 0;
	while (iRight < iCnt)
	{
		while (iSum < s && iRight < iCnt)
		{
			iSum += nums[iRight];
			iRight++;
		}

		while (iSum >= s && iLeft < iCnt)
		{
			iRes = min(iRes, iRight - iLeft + 1);
			iLeft--;
		}
	}

	return iRes;
}


//// CircularQueue
MyCircularQueue::MyCircularQueue(int k) {
	if (k <= 0)
	{
		return;
	}

	//// 注意这里的容量
	iLength = k + 1;
	iHead = 0;
	iRear = 0;
	arr = new int[k + 1];
}

bool MyCircularQueue:: enQueue(int value) {
	if (isFull())
	{
		return false;
	}

	arr[iRear] = value;
	iRear = (iRear + 1) % iLength;
	return true;
}

bool MyCircularQueue::deQueue() {
	if (isEmpty())
	{
		return false;
	}

	arr[iHead] = 0;
	iHead = (iHead + 1) % iLength;
	return true;
}

int MyCircularQueue::Front() {
	if (isEmpty())
	{
		return -1;
	}

	return arr[iHead];
}

int MyCircularQueue::Rear() {
	if (isEmpty())
	{
		return -1;
	}

	//// 注意这里的尾指针指向的地方
	return arr[(iRear - 1 + iLength) % iLength];
}

bool MyCircularQueue::isEmpty() {
	return iRear == iLength;
}

bool MyCircularQueue::isFull() {
	return (iRear + 1) % iLength == iHead;
}

int TaskOperator::leastInterval(vector<char>& tasks, int n)
{
	vector<int> iVec(26, 0);
	for (int i = 0; i < tasks.size(); i++)
	{
		iVec[tasks[i] - 'A']++;
	}

	int iInterval = n + 1 >= 26 ? 26 : n + 1;
	sort(iVec.begin(), iVec.end(), greater<int>());
	int iTime = 0;

	//// 按频率高低每隔 n + 1 刷一次
	while (iVec[iInterval - 1] > 0)
	{
		for (int i = 0; i < iInterval; i++)
		{
			if (iVec[i] == 0)
			{
				break;
			}

			iVec[i]--;
		}

		iTime += iInterval;
		sort(iVec.begin(), iVec.end(), greater<int>());
	}

	if (iVec[0] == 0)
	{
		return iTime;
	}

	//// 不足间隔的要单独处理
	int iExtra = 0;
	for (int i = iInterval - 2; i > 0; i--)
	{
		if (iVec[i] == 0)
		{
			continue;
		}

		int iTmp = iVec[i];
		iTime += iVec[i] * (n + 1);
		for (int j = iInterval - 2; j >= 0; j--)
		{
			iVec[j] -= iTmp;
		}

		if (iVec[0] == 0)
		{
			iExtra = i;
		}
	}

	iTime += iVec[0] == 0 ? iExtra - n : (iVec[0] - 1) * (n + 1) + 1;

	return iTime;
}

int TaskOperator::leastIntervalEasy(vector<char>& tasks, int n)
{
	vector<int> iVec(26, 0);
	for (int i = 0; i < tasks.size(); i++)
	{
		iVec[tasks[i] - 'A']++;
	}

	sort(iVec.begin(), iVec.end(), greater<int>());
	int iMaxCnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (iVec[i] == iVec[0])
		{
			iMaxCnt++;
		}
	}

	int iCnt = tasks.size();
	int iRes = max((iVec[0] - 1) * (n + 1) + iMaxCnt, iCnt);
	return iRes;
}

int PingCount::ping(int t)
{
	while (!q.empty())
	{
		int iFrontVal = q.front();
		if (t - 3000 > iFrontVal)
		{
			q.pop();
		}
		else
		{
			break;
		}
	}

	q.push(t);

	return q.size();
}

bool ValidSyntax::isValid(string s)
{
	stack<char> pStack;
	for (int i = 0; i < s.length(); i++)
	{
		char pChar = s[i];
	    if (!pStack.empty())
		{
			char pTmpChar = pStack.top();
			if ((pTmpChar == '(' && pChar == ')') ||
				(pTmpChar == '[' && pChar == ']') ||
				(pTmpChar == '{' && pChar == '}'))
			{
				pStack.pop();
				continue;
			}
		}
		
		pStack.push(pChar);
		
	}

	return pStack.empty();
}

vector<int> DailyTemperatures::dailyTempOverTime(vector<int>& T)
{
	int iFront, iEnd = 0;
	int iCnt = T.size();
	vector<int> iVec;
	for (int i = 0; i < iCnt; i++)
	{
		int iCurr = T[i];
		bool bAdd = false;
		for (int j = i; j < iCnt; j++)
		{
			int iNext = T[j];
			if (iCurr < iNext)
			{
				iVec.push_back(j - i);
				bAdd = true;
				break;
			}
		}

		if (!bAdd)
		{
			iVec.push_back(0);
		}
	}

	return iVec;
}

vector<int> DailyTemperatures::dailyTemp(vector<int>& T)
{
	stack<int> pStack;
	int iCnt = T.size();
	vector<int> iResVec(iCnt, 0);
	for (int i = 0; i < iCnt; i++)
	{
		int iCur = T[i];
		while (!pStack.empty())
		{
			int iTop = pStack.top();
			int iTopVal = T[iTop];
			if (iTopVal < iCur)
			{
				int iRes = i - iTop;
				iResVec[iTop] = iRes;
				pStack.pop();
			}
			else
			{
				pStack.push(i);
				break;
			}
		}

		pStack.push(i);
	}

	return iResVec;
}

string SimplifyPath::simplifyPath(string path)
{
	/*
	输入："/home/"
	输出："/home"

	输入："/../"
	输出："/"

	输入："/home//foo/"
	输出："/home/foo"

	输入："/a/./b/../../c/"
	输出："/c"

	输入："/a/../../b/../c//.//"
	输出："/c"

	输入："/a//b////c/d//././/.."
	输出："/a/b/c"
	*/

	return "";
}

int EvalRPN::evalRPN(vector<string>& tokens)
{
	/*输入: ["2", "1", "+", "3", "*"]
	输出: 9
	解释: ((2 + 1) * 3) = 9
	示例 2：

	输入: ["4", "13", "5", "/", "+"]
	输出: 6
	解释: (4 + (13 / 5)) = 6*/
	int iRes = 0;
	stack<int> pStack;
	int iCnt = tokens.size();
	for (int i = 0; i < iCnt; i++)
	{
		string sVal = tokens[i];
		if (sVal != "+" && sVal != "-" && sVal != "*" && sVal != "/")
		{
			int iVal = stoi(sVal);
			pStack.push(iVal);
		}
		else
		{
			int iFirst = pStack.top();
			pStack.pop();
			int iSec = pStack.top();
			pStack.pop();

			switch (sVal[0])
			{
			case '+':
				iRes = iSec + iFirst;
				break;
			case '-':
				iRes = iSec - iFirst;
				break;
			case '*':
				iRes = iSec * iFirst;
				break;
			case '/':
				iRes = iSec / iFirst;
				break;
			default:
				break;
			}

			pStack.push(iRes);
		}
	}

	return pStack.top();
}

int TrapWater::TrapHardWay(vector<int>& height)
{
	/* 错误的方法 ，考虑到两端值如果都很大就不行 例如[5,2,1,2,1,5]
	int iCnt = height.size();
	if (iCnt < 3)
	{
		return 0;
	}

	int iRes = 0;
	for (int i = 1; i < iCnt - 1; i++)
	{
		int iLeft = height[i - 1];
		int iMiddle = height[i];
		int iRight = height[i + 1];
		if (iLeft > iMiddle && iMiddle < iRight)
		{
			int iSum = 0;
			int idxLeft = i - 1;
			while (idxLeft >= 0 && height[idxLeft] > height[idxLeft + 1])
			{
				idxLeft--;
			}
			
			idxLeft = idxLeft >= 0 ? idxLeft + 1: 0;
			int idxRight = i + 1;
			while (idxRight < iCnt && height[idxRight] > height[idxRight - 1])
			{
				idxRight++;
			}

			idxRight = idxRight < iCnt ? idxRight - 1: iCnt - 1;
			int iheight = min(height[idxRight], height[idxLeft]);
			for (int j = idxLeft + 1; j < idxRight; j++)
			{
				if (height[j] < iheight)
				{
					iRes += iheight - height[j];
				}
			}

			i = idxRight + 1;
		}
	}

	return iRes;*/

	stack<MyStruct> pStack;
	int iCnt = height.size();

	int iSum = 0;
	for (int i = 0; i < iCnt; i++)
	{
		MyStruct iCur;
		iCur.iVal = height[i];
		pStack.push(iCur);

		while (pStack.size() >= 3)
		{
			MyStruct iRight = pStack.top();
			pStack.pop();

			MyStruct iMiddle = pStack.top();
			pStack.pop();

			MyStruct iLeft = pStack.top();
			pStack.pop();

			if (iMiddle.iVal < iRight.iVal && iMiddle.iVal < iLeft.iVal)
			{
				if (iRight.iVal > iLeft.iVal)
				{
					iLeft.iExp += iMiddle.iExp;
					pStack.push(iLeft);
					pStack.push(iRight);
				}
				else if (iRight.iVal == iLeft.iVal)
				{
					iLeft.iExp += iMiddle.iExp + iRight.iExp;
					pStack.push(iLeft);
				}
				else
				{
					iRight.iExp += iMiddle.iExp;
					pStack.push(iLeft);
					pStack.push(iRight);
				}

				iSum += (min(iRight.iVal, iLeft.iVal) - iMiddle.iVal) * iMiddle.iExp;
			}
			else if (iRight.iVal == iMiddle.iVal)
			{
				iRight.iExp += iMiddle.iExp;
				pStack.push(iLeft);
				pStack.push(iRight);
			}
			else if (iLeft.iVal == iMiddle.iVal)
			{
				iLeft.iExp += iMiddle.iExp;
				pStack.push(iLeft);
				pStack.push(iRight);
			}
			else
			{
				pStack.push(iLeft);
				pStack.push(iMiddle);
				pStack.push(iRight);
				break;
			}
		}
	}

	return iSum;
}

int TrapWater::TrapEasyWay(vector<int>& height)
{
	int iSize = height.size();
	int iSum = 0;
	vector<int> VecLeft(iSize, 0), VecRight(iSize, 0);
	for (int i = 1; i < iSize; i++)
	{
		VecLeft[i] = max(VecLeft[i - 1], height[i - 1]);
	}

	for (int i = iSize - 2; i >= 0; i--)
	{
		VecRight[i] = max(VecRight[i + 1], height[i + 1]);
	}

	for (int i = 0; i < iSize; i++)
	{
		int offset = min(VecLeft[i], VecRight[i]);
		iSum += max(0, offset - height[i]);
	}

	return iSum;
}



int MaxRec :: lgtRectangleArea(vector<int>& heights) {
	int iSize = heights.size();
	if (iSize == 0)
	{
		return 0;
	}
	
	int iRes = CalMinIdx(heights, 0, iSize - 1);

	return iRes;

}

int MaxRec ::CalMinIdx(vector<int>& heights, int iStart, int iEnd)
{
	int iMin = min(heights[iStart], heights[iEnd]);
	int iMinIdx = heights[iStart] < heights[iEnd] ? iStart : iEnd;
	for (int i = iStart; i <= iEnd; i++)
	{
		if (iMin > heights[i])
		{
			iMin = heights[i];
			iMinIdx = i;
		}
	}
	
	int iTmpMax = (iEnd - iStart + 1) * iMin;
	int iLeft = iStart == iMinIdx ? heights[iMinIdx] : CalMinIdx(heights, iStart, iMinIdx - 1);
	int iRight = iMinIdx == iEnd ? heights[iMinIdx] : CalMinIdx(heights, iMinIdx + 1, iEnd);
	return max(max(iTmpMax, iLeft), iRight);
}

int MaxRec::largestRectangleArea(vector<int>& heights)
{
	int iSize = heights.size();
	heights.push_back(0);
	stack<int> pStack;
	int iMaxRes = 0;
	for (int i = 0; i <= iSize; i++)
	{
		int iVal = heights[i];
		while (!pStack.empty() && iVal < heights[pStack.top()])
		{
			int iTopVal = heights[pStack.top()];
			pStack.pop();
			iMaxRes = max(iMaxRes, (pStack.empty() ? i : i - pStack.top() - 1) * iTopVal);
		}

		pStack.push(i);
	}

	return iMaxRes;
}

MyLinkedList::MyLinkedList()
{
	iLength = 0;
	Head->Next = nullptr;
	Tail->Next = nullptr;
}

int MyLinkedList::get(int index)
{
	if (index > iLength - 1)
	{
		return -1;
	}

	int idx = 0;
	LinkNode *Node = Head;
	while (idx <= index)
	{
		Node = Node->Next;
		idx++;
	}

	return Node->iVal;
}

void MyLinkedList::addAtHead(int val)
{
	LinkNode *First = Head->Next;
	LinkNode *nodeAdd = new LinkNode(val);
	nodeAdd->Next = First;
	Head->Next = nodeAdd;
	if (Tail == nullptr)
	{
		Tail = nodeAdd;
	}

	iLength++;
}

void MyLinkedList::addAtTail(int val)
{
	Tail->Next = new LinkNode(val);
	Tail = Tail->Next;
	iLength++;
}

void MyLinkedList::addAtIndex(int index, int val)
{
	if (index == iLength)
	{
		addAtTail(val);
	}

	if (index > iLength)
	{
		return;
	}

	int idx = 0;
	LinkNode *nodePre = Head;
	while (idx <= index - 1)
	{
		nodePre = nodePre->Next;
		idx++;
	}

	LinkNode *Curr = nodePre->Next;
	LinkNode *nodeAdd = new LinkNode(val);
	nodeAdd->Next = Curr;
	nodePre->Next = nodeAdd;
	iLength++;
}

void MyLinkedList::deleteAtIndex(int index)
{
	if (index > iLength - 1)
	{
		return;
	}

	int idx = 0;
	LinkNode *nodePre = Head;
	while (idx <= index - 1)
	{
		nodePre = nodePre->Next;
		idx++;
	}

	LinkNode *Curr = nodePre->Next;
	nodePre->Next = Curr->Next;
	iLength--;
	delete Curr;
}

int NumSquare::numSquare(int n)
{
	vector<int> pVec;
	for (int i = 1; i * i < n; i++)
	{
		pVec.push_back(i*i);
	}

	queue<int> q;
	q.push(n);
	int iNumCnt = 0;
	int iVecSize = pVec.size();
	while (!q.empty())
	{
		iNumCnt++;
		int iWidth = q.size();
		for (int i = 0; i < iWidth; i++)
		{
			int iVal = q.front();
			q.pop();
			for (int j = iVecSize - 1; j >= 0; j--)
			{
				if (pVec[j] < iVal)
				{
					q.push(iVal - pVec[j]);
				}
				else if(pVec[j] == iVal)
				{
					return iNumCnt;
				}
			}
		}
	}

	return iNumCnt;
	
	/*	vector<int> help;//存储小于等于n的完全平方数
        for(int i=1;i*i<=n;++i){
            help.push_back(i*i);
        }
        int minlen=0,size=help.size();
        queue<int> q;//辅助队列
        q.push(n);
        while(!q.empty()){
            ++minlen;//树的高度
            int width=q.size();//树每层的宽度
        for(int j=0;j<width;j++){
              int temp=q.front();
               q.pop();
            for(int i=size-1;i>=0;--i){
                if(help[i]<=temp)
                {
                    if(help[i]==temp)
                        return minlen;
                    else q.push(temp-help[i]);//减掉之后剩余的值入队
                }
            }
          }
        }
        return minlen;//循环里一定有返回值（不会执行）*/
}

bool JumpGame::CanJump(vector<int>& heights)
{
	int iSize = heights.size();
	if (iSize == 0)
	{
		return true;
	}

	return true;
	//int idxFirst = 0;
	//int iFirstValue = heights[0];

	//int iCurStep = idxFirst;
	//
	//while (iCurStep < iSize - 1)
	//{
	//	int iTmp = iFirstValue;
	//	int iStepCnt = 0;
	//	while (iStepCnt < iFirstValue)
	//	{
	//		if (heights[idxFirst] + idxFirst < iFirstValue)
	//		{

	//		}
	//	}

	//	idxFirst++;
	//}
}
 
string RemoveK::removeKdigits(string num, int k)
{
	stack<char> q;
	for (int i = 0; i < num.length(); i++)
	{
		char pCharFirst = num[i];
		while (!q.empty() && q.top() > pCharFirst && k > 0)
		{
			q.pop();
			k--;
		}
		
		q.push(pCharFirst);
	}

	while (k > 0)
	{
		q.pop();
		k--;
	}
	
	string str;
	while (!q.empty())
	{
		str.append(1, q.top());
		q.pop();
	}

	reverse(str.begin(), str.end());

	int idx = 0;
	while (str[idx] == '0')
	{
		idx++;
	}

	return str.substr(idx) == "" ? "0" : str.substr(idx);
}

int FindNumInRotate::search(vector<int>& nums, int target)
{
	int iSize = nums.size();
	int iStart = 0;
	int iEnd = iSize - 1;
	while (iStart <= iEnd)
	{
		int iMid = (iStart + iEnd) / 2;
		int iMidVal = nums[iMid];
		if (iMidVal == target)
		{
			return iMid;
		}

		if (iMidVal > nums[iEnd])
		{
			if (iMidVal > target && target >= nums[iStart])
			{
				iEnd = iMid - 1;
			}
			else
			{
				iStart = iMid + 1;
			}
		}
		else
		{
			if (iMidVal < target && target <= nums[iEnd])
			{
				iStart = iMid + 1;
			}
			else
			{
				iEnd = iMid - 1;
			}
		}
	}

	return -1;
}

bool FindWord::exist(vector<vector<char>>& board, string word)
{
	 
	return false;
}
