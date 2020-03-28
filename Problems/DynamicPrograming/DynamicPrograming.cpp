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

MyLinkedList::LinkNode * MyLinkedList::removeNthFromEnd(LinkNode * head, int n)
{
	int k = 0;
	LinkNode* pFirst = head;

	//// 这里注意一下链表长度和n一致的情况。
	while (k++ <= n && pFirst != NULL)
	{
		pFirst = pFirst->Next;
	}

	if (k < n)
	{
		return head->Next;
	}

	LinkNode* pSecond = head;
	while (pFirst != NULL)
	{
		pFirst = pFirst->Next;
		pSecond = pSecond->Next;
	}

	LinkNode* pCur = pSecond->Next;
	pSecond->Next = pCur->Next;
	delete pCur;

	return head;
}

MyLinkedList::LinkNode * MyLinkedList::mergeKLists(vector<LinkNode*>& lists)
{

	return nullptr;
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

	int iCurStep = 0;
	while (iCurStep < iSize)
	{
		int iMaxVal = 0;
		int iCurVal = heights[iCurStep];
		int iNextIdx;
		int iTmpCurStep = iCurStep;
		for (int i = 1; i <= iCurVal; i++)
		{
			iNextIdx = iTmpCurStep + i;
			if (iNextIdx >= iSize - 1)
			{
				return true;
			}

			if (iMaxVal < iNextIdx + heights[iNextIdx])
			{
				iMaxVal = iNextIdx + heights[iNextIdx];
				iCurStep = iNextIdx;
			}
		}
		
		if (iMaxVal >= iSize - 1)
		{
			return true;
		}

		if (heights[iCurStep] == 0)
		{
			return false;
		}

		iCurVal = heights[iCurStep];
	}    

	return true;
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
	int iRow = board.size();
	int iCol = board[0].size();
	vector<vector<bool>> visited(iRow, vector<bool>(iCol, false));
	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iCol; j++)
		{
			if (board[i][j] == word[0])
			{
				visited[i][j] = true;
				if (Find(board, visited, i, j, word.substr(1)))
				{
					return true;
				}

				visited[i][j] = false;
			}
		}
	}

	return false;
}

bool FindWord::Find(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string substr)
{
	if (substr == "")
	{
		return true;
	}

	int iRow = board.size();
	int iCol = board[0].size();
	char pChar = substr[0];
	
	bool bUpOver = i - 1 < 0;
	bool bDownOver = i + 1 >= iRow;
	bool bLeftOver = j - 1 < 0;
	bool bRightOver = j + 1 >= iCol;

	bool Existup = false;
	bool ExistDown = false;
	bool ExistLeft = false;
	bool ExistRight = false;
	if (!bUpOver && board[i - 1][j] == pChar && !visited[i - 1][j])
	{
		visited[i - 1][j] = true;
		Existup = Find(board, visited, i - 1, j, substr.substr(1));
		visited[i - 1][j] = false;
	}

	if (!bDownOver && board[i + 1][j] == pChar && !visited[i + 1][j])
	{
		visited[i + 1][j] = true;
		ExistDown = Find(board, visited, i + 1, j, substr.substr(1));
		visited[i + 1][j] = false;
	}

	if (!bLeftOver && board[i][j - 1] == pChar && !visited[i][j - 1])
	{
		visited[i][j - 1] = true;
		ExistLeft = Find(board, visited, i, j - 1, substr.substr(1));
		visited[i][j - 1] = false;
	}

	if (!bRightOver && board[i][j + 1] == pChar && !visited[i][j + 1])
	{

		visited[i][j + 1] = true;
		ExistRight = Find(board, visited, i, j + 1, substr.substr(1));
		visited[i][j + 1] = false;
	}

	return Existup || ExistDown || ExistLeft || ExistRight;
}

bool FindWord::existSaveTime(vector<vector<char>>& board, string word)
{
	int iRow = board.size();
	int iCol = board[0].size();
	vector<vector<bool>> vecFlag(iRow, vector<bool>(iCol, false));
	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iCol; j++)
		{
			if (DFS(board, vecFlag, i, j, 0, word))
			{
				return true;
			}
		}
	}

	return false;
}

bool FindWord::DFS(vector<vector<char>>& board, vector<vector<bool>>& flag, int i, int j, int iCurSize, string word)
{
	if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
	{
		return false;
	}

	if (flag[i][j] || board[i][j] != word[iCurSize])
	{
		return false;
	}

	if (iCurSize + 1 == word.size())
	{
		return true;
	}

	flag[i][j] = true;
	if (DFS(board, flag, i, j + 1, iCurSize + 1, word)
		|| DFS(board, flag, i, j - 1, iCurSize + 1, word)
		|| DFS(board, flag, i + 1, j, iCurSize + 1, word)
		|| DFS(board, flag, i - 1, j, iCurSize + 1, word))
	{
		return true;
	}

	flag[i][j] = false;

	return false;
}

vector<int> FindKClosestNum::findClosestElements(vector<int>& arr, int k, int x)
{
	queue<int> q;
	int iSize = arr.size();
	for (int i = 0; i < iSize; i++)
	{
		int iVal = arr[i];
		int iQuSize = q.size();
		if (iQuSize < 4)
		{
			q.push(iVal);
		}
		else
		{
			int iFront = q.front();
			int iFrontoff = abs(iFront - x);
			int iCurOff = abs(iVal - x);
			if (iFrontoff > iCurOff)
			{
				q.pop();
				q.push(iVal);
			}
		}
	}
	
	vector<int> vec;
	while (!q.empty())
	{
		vec.push_back(q.front());
		q.pop();
	}

	return vec;
}

vector<int> FindKClosestNum::findClosestElementsDlbPtr(vector<int>& arr, int k, int x)
{
	int iSize = arr.size();
	int iStart = 0;
	int iEnd = iSize - 1;
	while (iEnd - iStart + 1 > k)
	{
		int iStartVal = arr[iStart];
		int iEndVal = arr[iEnd];
		if (abs(iStartVal - x) <= abs(iEndVal - x))
		{
			iEnd--;
		}
		else
		{
			iStart++;
		}
	}

	return vector<int>(arr.begin() + iStart, arr.begin() + k + iStart);
}

int OpenLock::openLock(vector<string>& deadends, string target)
{
	int iDeadSize = deadends.size();
	map<string, int> mapVisit;
	for (int i = 0; i < iDeadSize; i++)
	{
		mapVisit[deadends[i]] = 1;
	}

	if (mapVisit["0000"] == 1)
	{
		return -1;
	}
	
	int iCnt = -1;
	queue<string> q;
	q.push("0000");
	while (!q.empty())
	{
		int iQueSize = q.size();
		iCnt++;	
		while (iQueSize > 0)
		{
			string sFrontVal = q.front();
			if (sFrontVal == target)
			{
				return iCnt;
			}

			q.pop();
			iQueSize--;

			for (int i = 0; i < 4; i++)
			{
				string s1 = sFrontVal, s2 = sFrontVal;
				s1[i] = s1[i] == '9' ? '0' : s1[i] + 1;
				s2[i] = s2[i] == '0' ? '9' : s2[i] - 1;
				if (mapVisit[s1] == 0)
				{
					q.push(s1);
					mapVisit[s1] = 1;
				}
				
				if (mapVisit[s2] == 0)
				{
					q.push(s2);
					mapVisit[s2] = 1;
				}
			}
		}
	}

	return -1;
}

vector<vector<int>> MergeSection::merge(vector<vector<int>>& intervals)
{
	vector<vector<int>> vecRes;
	sort(intervals.begin(), intervals.end(), cmp1);
	
	intervals.push_back({ INT32_MAX, INT32_MAX });

	int iSize = intervals.size();

	int iMerStart = 1;
	int iMax = intervals[0][1];
	for (int i = 1; i < iSize; i++)
	{
		vector<int> vecCur = intervals[i];
		if (iMax >= vecCur[0])
		{
			//// 比较右侧值大小
			iMax = max(iMax, vecCur[1]);
		}
		else
		{
			if (iMerStart == i)
			{
				vecRes.push_back(intervals[iMerStart - 1]);
			}
			else
			{
				vecRes.push_back({ intervals[iMerStart - 1][0], iMax });
			}

			iMax = intervals[i][1];
			iMerStart = i + 1;
		}
	}

	return vecRes;
}

string MaxNum::largestNumber(vector<int>& nums)
{
	vector<string> vecStr;
	int iSize = nums.size();
	for (int i = 0; i < iSize; i++)
	{
		vecStr.push_back(to_string(nums[i]));
	}

	sort(vecStr.begin(), vecStr.end(), cmp);

	string str;
	if (vecStr[0] == "0")
	{
		return "0";
	}

	for (int i = 0; i < iSize; i++)
	{
		str += vecStr[i];
	}

	return str;
}

string MaxNum::largestNumberSuccinct(vector<int>& nums)
{
	sort(nums.begin(), nums.end(), [](int &a, int &b)
	{
		string sa = to_string(a);
		string sb = to_string(b);
		return sa + sb > sb + sa;
	});


	string res;
	bool bNoneZero = false;
	for (int iNum : nums)
	{
		res += to_string(iNum);
		if (iNum)
		{
			bNoneZero = true;
		}
	}

	res = bNoneZero ? res : "0";
	return res;
}

void WiggleSort::wiggleSort(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int iSize = nums.size();
	int iMid = (iSize + 1) / 2;
	vector<int> vec1 = vector<int>(nums.begin(), nums.begin() + iMid);
	vector<int> vec2 = vector<int>(nums.begin() + iMid, nums.end());
	int iVec1Size = vec1.size() - 1;
	int iVec2Size = vec2.size() - 1;
	vector<int> resVec;

	//// 不能从0开始遍历，因为【4，5，5，6】的情况通过不了
	for (int i = iVec2Size; i >= 0; i--)
	{
		resVec.push_back(vec1[iVec1Size--]);
		resVec.push_back(vec2[iVec2Size--]);
	}

	if (iVec1Size > iVec2Size)
	{
		resVec.push_back(vec1[0]);
	}
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
	nums = resVec;
}

void WiggleSort::wiggleSortII(vector<int>& nums)
{
	int iSize = nums.size();
	int iMid = (iSize - 1) / 2;
	sort(nums.begin(), nums.end());
	vector<int> Res(nums);
	int iTmpMid = iMid;
	int i = 0;
	int k = iSize - 1;
	while (iSize--)
	{
		if (iMid >= 0)
		{
			nums[i++] = Res[iMid--];
		}

		if (k > iTmpMid)
		{
			nums[i++] = Res[k--];
		}
	}
}

int FindDuplicate::findDuplicate(vector<int>& nums)
{

	return 0;
}

ExchangeNode::ListNode* ExchangeNode::swapPairs(ListNode * head)
{
	if (head == NULL || head->next)
	{
		return head;
	}

	ListNode *First = head;
	ListNode* Tmphead = head->next;
	

	ListNode *Second = First->next;
	ListNode *Third = Second->next;

	Second->next = First;
	First->next = Third;

	while (First != NULL)
	{
		Second = First->next;
		if (Second == NULL)
		{
			break;
		}

		Third = Second->next;
		if (Third == NULL)
		{
			break;
		}

		Second->next = Third->next;
		First->next = Third;
		Third->next = Second;

		First = Second;
	}
	      
	return Tmphead;
}

ExchangeNode::ListNode * ExchangeNode::swapPairsII(ListNode * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	ListNode *next = head->next;
	head->next = swapPairsII(next->next);
	next->next = head;
	return next;
}

bool DividSubset::canPartitionKSubsets(vector<int>& nums, int k)
{
	sort(nums.begin(), nums.end());
	int iSum = 0;
	int iSize = nums.size();
	for (int i = 0; i < iSize; i++)
	{
		iSum += nums[i];
	}

	if (iSum % k != 0)
	{
		return false;
	}

	int iAverage = iSum / k;

	int iStart = 0;
	int iEnd = 0;
	//while (iStart < iEnd)
	//{
	//	if (nums[iStart] == iAverage)
	//	{
	//		iStart++;
	//	}

	//	if (nums[iEnd] == iAverage)
	//	{
	//		iEnd++;
	//	}

	//	if(nums) 
	//}

	return false;
}

int MaxSameValuePath::longestUnivaluePath(TreeNode * root)
{
	if (root == NULL)
	{
		return 0;
	}

	GetMax(root, root->val);

	return iMax;
}

int MaxSameValuePath::GetMax(TreeNode * root, int iVal)
{
	if (root == NULL)
	{
		return 0;
	}

	int iLeftLen = GetMax(root->left, root->val);
	int iRightLen = GetMax(root->right, root->val);

	iMax = max(iMax, iLeftLen + iRightLen);
	if (root->val == iVal)
	{
		return max(iLeftLen, iRightLen) + 1;
	}

	return 0;
}



void longestpath1(MaxSameValuePath::TreeNode *r, char path[], int len, char longpath[], int &longlen)
{
	int i;
	if (r == NULL)
	{
		if (len > longlen)
		{
			for (i = 0; i < len; i++)
				longpath[i] = path[i];
		}

		longlen = len;
	}
	else
	{
		path[len] = r->val;
		len++;
		longestpath1(r->left, path, len, longpath, longlen);
		longestpath1(r->right, path, len, longpath, longlen);
		len--;
	}

}

vector<int> FindFirstAndLast::searchRange(vector<int>& nums, int target)
{
	int iSize = nums.size();
	int iStart = 0;
	int iEnd = iSize - 1;
	int iIdx = 0;
	vector<int> Res(2, -1);
	while (iStart < iEnd)
	{
		int iMid = (iStart + iEnd) / 2;
		if (nums[iMid] == target)
		{
			iIdx = iMid;
			break;
		}

		if (nums[iMid] > target)
		{
			iEnd = iMid - 1;
		}
		else if (nums[iMid] < target)
		{
			iStart = iMid + 1;
		}
	}

	if (nums[iIdx] != target)
	{
		return Res;
	}

	iStart = 0;
	iEnd = iIdx;
	int iLeft = 0;
	while (iStart < iEnd)
	{
		int iMid = (iStart + iEnd) / 2;

		if (nums[iMid] < target && nums[iMid + 1] == target)
		{
			iLeft = iMid + 1;
			break;
		}

		if (nums[iMid] < target)
		{
			iStart = iMid + 1;
		}
		else
		{
			iEnd = iMid - 1;
		}
	}

	Res[0] = iLeft;

	iStart = iIdx;
	iEnd = iSize - 1;
	int iRight = 0;
	while (iStart <= iEnd)
	{
		int iMid = (iStart + iEnd) / 2;

		if (nums[iMid] > target && nums[iMid - 1] == target)
		{
			iRight = iMid - 1;
			break;
		}

		if (nums[iMid] > target)
		{
			iEnd = iMid - 1;
		}
		else
		{
			iStart = iMid + 1;
		}
	}

	Res[1] = iRight;

	return Res;
}

vector<int> FindFirstAndLast::searchRangeII(vector<int>& nums, int target)
{
	return vector<int>();
}

int LongestIncreasingPath::longestIncreasingPath(vector<vector<int>>& matrix)
{
	if (matrix.empty())
	{
		return 0;
	}

	int iRow = matrix.size();
	int iCol = matrix[0].size();
	int iMaxLen = 1;
	int iMin = INT32_MIN;

	int iSize = iRow * iCol;
	vector<int> Res(iSize, 0);
	int iCnt = 0;

	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iCol; j++)
		{
			Res[iCnt++] = matrix[i][j];
		}
	}

	sort(Res.begin(), Res.end());
	int iThreshold = Res[iSize - 1];
	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iCol; j++)
		{
			if (matrix[i][j] >= iThreshold)
			{
				continue;
			}

			int iTmpMax = DFS(matrix, i, j, iMin);
			if (iTmpMax > iMaxLen)
			{
				iMaxLen = iTmpMax;
				iThreshold = Res[iSize - iTmpMax];
			}
		}
	}

	return iMaxLen;
}

int LongestIncreasingPath::DFS(vector<vector<int>>& matrix, int i, int j, int iCurVal)
{
	int iRow = matrix.size();
	int iCol = matrix[0].size();

	if (i < 0 || j < 0 || i > iRow - 1 || j > iCol - 1
		|| matrix[i][j] <= iCurVal)
	{
		return 0;
	}

	int iUp = DFS(matrix, i - 1, j, matrix[i][j]);
	int iDown = DFS(matrix, i + 1, j, matrix[i][j]);
	int iLeft = DFS(matrix, i, j - 1, matrix[i][j]);
	int iRight = DFS(matrix, i, j + 1, matrix[i][j]);

	int iMax = max(iUp, max(iDown, max(iLeft, iRight))) + 1;

	return iMax;
}

int LongestIncreasingPath::longestIncreasingPathSaveTime(vector<vector<int>>& matrix)
{
	return 0;
}

vector<int> CountSmaller::countSmaller(vector<int>& nums)
{
	TreeNode* TopNode = ConstructTree(nums);
	int iSize = nums.size();
	vector<int> Res(iSize);
	//for (int i = 0; i < iSize; i++)
	//{
	//	TreeNode* TmpNode = TopNode;
	//	int iCnt = 1;
	//	while (iCnt++ <= i)
	//	{
	//		if (TmpNode->val <= nums[i])
	//		{
	//			TmpNode = TmpNode->right;
	//		}
	//		else
	//		{
	//			TmpNode = TmpNode->left;
	//		}
	//	}

	//	Res[i] = NodeCnt(TmpNode->left);
	//}

	return Res;
}

vector<AllPossibleFBT::TreeNode*> AllPossibleFBT::allPossibleFBT(int N)
{
	vector<TreeNode*> vecRes;
	if (N % 2 == 0)
	{
		return vecRes;
	}

	if (N == 1)
	{
		TreeNode* head = new TreeNode(0);
		vecRes.push_back(head);
	}

	for (int i = 1; i < N; i += 2)
	{
		vector<TreeNode*> vecLeft = allPossibleFBT(i);
		vector<TreeNode*> vecRight = allPossibleFBT(N - 1 - i);

		for (TreeNode* left : vecLeft)
		{
			for (TreeNode* right : vecRight)
			{
				TreeNode* head = new TreeNode(0);
				head->left = left;
				head->right = right;

				vecRes.push_back(head);
			}
		}
	}

	return vecRes;
}

string AtomCnt::countOfAtoms(string formula)
{
	stack<Atom*> pStack;
	int i = 0;
	while(i < formula.length())
	{
		int j;
		if (formula[i] >= 'A' && formula[i] <= 'Z')
		{
			j = i + 1;
			int iAtomCnt = 1;
			string sName;
			sName += formula[i];
			while (formula[j] >= 'a' && formula[j] <= 'z')
			{
				sName += formula[j];
				j++;
			}
			 
			string sNum = "";
			while (formula[j] >= '0' && formula[j] <= '9')
			{
				sNum += formula[j];
				j++;
			}

			iAtomCnt = sNum == "" ? 1 : stoi(sNum);

			Atom* pAtom = new Atom(sName, iAtomCnt);
			pStack.push(pAtom);
			i = j;
		}
		else if(formula[i] == '(')
		{
			pStack.push(new Atom("(", 0));
			i++;
		}
		else
		{
			Atom* pAtomTop = pStack.top();
			stack<Atom*> pStackTmp;
			string sNum = "";
			int j = i + 1;
			while (formula[j] >= '0' && formula[j] <= '9')
			{
				sNum += formula[j];
				j++;
			}

			int iExp = stoi(sNum);
			while (!pStack.empty() && pAtomTop->Name != "(")
			{
				pAtomTop->iCnt = pAtomTop->iCnt * iExp;
				pStackTmp.push(pAtomTop);
				pStack.pop();
				pAtomTop = pStack.top();
			}

			pStack.pop();
			while (!pStackTmp.empty())
			{
				pStack.push(pStackTmp.top());
				pStackTmp.pop();
			}

			i = j;
		}
	}

	map<string, int> pMap;
	while (!pStack.empty())
	{
		pMap[pStack.top()->Name] += pStack.top()->iCnt;
		pStack.pop();
	}

	string sRes;
	for (auto key : pMap)
	{
		sRes += key.first + (key.second == 1 ? "" : to_string(key.second));
	}

	return sRes;
}

int GiveOutCandy::candy(vector<int>& ratings)
{
	if (ratings.empty())
	{
		return 0;
	}

	return 0;
}

vector<int> BinaryTree::preorderTraversal(TreeNode * root)
{
	vector<int> Res;
	stack<TreeNode *> pStack;
	TreeNode *TmpNode = root;

	pStack.push(TmpNode);
	while (!pStack.empty())
	{
		TmpNode = pStack.top();
		pStack.pop();

		while (TmpNode != NULL)
		{
			Res.push_back(TmpNode->val);
			if (TmpNode->right)
			{
				pStack.push(TmpNode->right);
			}
			
			TmpNode = TmpNode->left;
			
		}
	}

	return Res;
}

vector<vector<int>> BinaryTree::levelOrder(TreeNode * root)
{
	vector<vector<int>> Res;
	if (root == NULL)
	{
		return Res;
	}

	queue<TreeNode *> pQueue;
	pQueue.push(root);
	while (!pQueue.empty())
	{
		int iSize = pQueue.size();
		vector<int> pLevVec(iSize);
		for (int i = 0; i < iSize; i++)
		{
			TreeNode *TmpNode = pQueue.front();
			pLevVec[i] = TmpNode->val;

			pQueue.pop();

			if (TmpNode->left != NULL)
			{
				pQueue.push(TmpNode->left);
			}

			if (TmpNode->right != NULL)
			{
				pQueue.push(TmpNode->right);
			}
		}

		Res.push_back(pLevVec);
	}

	return Res;
}

vector<BinaryTree::TreeNode*> BinaryTree::findDuplicateSubtrees(TreeNode * root)
{
	map<string, int> pMap;
	vector<TreeNode*> pAllNode;
	PreOrder(pAllNode, root);

	vector<TreeNode*> ResVec;
	for (auto pNode : pAllNode)
	{
		if (pNode == NULL)
		{
			continue;
		}

		vector<TreeNode*> pTmpVec;
		PreOrder(pTmpVec, pNode);

		string str = "";
		for (auto head : pTmpVec)
		{
			if (head == NULL)
			{
				str += "null";
			}
			else
			{
				str += to_string(head->val);
			}
		}

		if (pMap[str] == 1)
		{
			ResVec.push_back(pNode);
		}
		
		pMap[str] += 1;
	}

	return ResVec;
}

int BinaryTree::GetMaxLen(TreeNode * root, int iCurMaxVal, int &iMax)
{
	if (root == NULL)
	{
		return 0;
	}

	int iLeftLen = GetMaxLen(root->left, root->val, iMax);
	int iRightLen = GetMaxLen(root->right, root->val, iMax);

	iMax = max(iMax, iLeftLen + iRightLen);
	if (root->val == iCurMaxVal)
	{
		return max(iLeftLen, iRightLen) + 1;
	}

	return 0;
}

int BinaryTree::maxPathSum(TreeNode * root, int& iMax)
{
	if (root == NULL)
	{
		return INT32_MIN;
	}

	int iLeft = maxPathSum(root->left, iMax);
	int iRight = maxPathSum(root->right, iMax);
	if (root->val > 0)
	{
		iMax = max(iMax, root->val);
		if (iLeft >= 0)
		{
			iMax = max(iMax, iLeft + root->val);
		}

		if (iRight >= 0)
		{
			iMax = max(iMax, iRight + root->val + iLeft);
		}
	}
	else
	{
		iMax = max(root->val, max(iLeft, iRight));
	}
	
	return max(iLeft, iRight);;
}

//bool BinaryTree::isValidBST(TreeNode * root)
//{
//	while (root->left != NULL)
//	{
//		root = root->left;
//	}
//
//	int iPre = INT32_MIN;
//}

int UglyNum::nthUglyNumber(int n)
{
	vector<int> dp;
	int idx2 = 0;
	int idx3 = 0;
	int idx5 = 0;
	dp.push_back(1);
	for (int i = 1; i < n; i++)
	{
		dp.push_back(min(dp[idx2] * 2, min(dp[idx3] * 3, dp[idx5] * 5)));
		if (dp[i] == dp[idx2] * 2)
		{
			idx2++;
		}

		if (dp[i] == dp[idx3] * 3)
		{
			idx3++;
		}

		if (dp[i] == dp[idx5] * 5)
		{
			idx5++;
		}
	}

	return dp.back();
}

int UglyNum::nthUglyNumberMinHeap(int n)
{
	//priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> minHeap;
	//vector<uint64_t> dp(n + 1, 0);
	//set<uint64_t> pSet;
	//vector<int> pResVec = { 2,3,5 };
	//dp[1] = 1;
	//for (int i = 2; i < n; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		uint64_t tmpVal = dp[i - 1] * pResVec[j];
	//		if (!pSet.count(tmpVal))
	//		{
	//			pSet.insert(tmpVal);
	//			minHeap.push(tmpVal);
	//		}
	//	}

	//	dp[i] = minHeap.top();
	//	minHeap.pop();
	//}

	return 0;
}

vector<string> TopKFrequent::topKFrequent(vector<string>& words, int k)
{
	map<string, int> pMap;
	for (auto pSingle : words)
	{
		pMap[pSingle]++;
	}

	vector<pair<string, int>> pVec;
	for (auto i : pMap)
	{
		pVec.push_back(i);
	}

	vector<string> pRes(k);
	sort(pVec.begin(), pVec.end(), cmp);
	for (int i = 0; i < k; i++)
	{
		pRes[i] = pVec[i].first;
	}

	return pRes;
}

bool IsValidSudoku::isValidSudoku(vector<vector<char>>& board)
{
	vector<vector<int>> row(9, vector<int>(9));
	vector<vector<int>> col(9, vector<int>(9));;
	vector<vector<int>> block(9, vector<int>(9));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
			{
				continue;
			}

			int iNum =  - '1';
			int iBlock = i / 3 * 3 + j / 3;
			if (row[i][iNum] || col[j][iNum] || block[iBlock][iNum])
			{
				return false;
			}

			row[i][iNum] = true;
			col[j][iNum] = true;
			block[iBlock][iNum] = true;

		}
	}

	return true;
}

int NumIslands::numIslands(vector<vector<char>>& grid)
{
	int iRow = grid.size();
	int iCol = grid[0].size();
	queue<int> pQue;
	int iCnt = 0;

	for (int i = 0; i < iRow; i++)
	{
		for (int j = 0; j < iCol; j++)
		{
			if (grid[i][j] == '0')
			{
				continue;
			}

			iCnt++;
			pQue.push(i);
			pQue.push(j);
			grid[i][j] = '0';
			while (!pQue.empty())
			{
				int iSize = pQue.size() / 2;
				for (int k = 0; k < iSize; k++)
				{
					int rowIdx = pQue.front();
					pQue.pop();
					int colIdx = pQue.front();
					pQue.pop();

					//// 下
					if (rowIdx + 1 < iRow && grid[rowIdx + 1][colIdx] == '1')
					{
						//// 这边可以直接置位为0;
						grid[rowIdx + 1][colIdx] = '0';
						pQue.push(rowIdx + 1);
						pQue.push(colIdx);
					}

					//// 右
					if (colIdx + 1 < iCol && grid[rowIdx][colIdx + 1] == '1')
					{
						grid[rowIdx][colIdx + 1] = '0';
						pQue.push(rowIdx);
						pQue.push(colIdx + 1);
					}

					//// 左
					if (colIdx - 1 >= 0 && grid[rowIdx][colIdx - 1] == '1')
					{
						grid[rowIdx][colIdx - 1] = '0';
						pQue.push(rowIdx);
						pQue.push(colIdx - 1);
					}

					//// 上
					if (rowIdx - 1 >= 0 && grid[rowIdx - 1][colIdx] == '1')
					{
						grid[rowIdx - 1][colIdx] = '0';
						pQue.push(rowIdx - 1);
						pQue.push(colIdx);
					}
				}
			}
		}
	}

	return iCnt;
}

int NumIslands::numIslandsDFS(vector<vector<char>>& grid)
{

	return 0;
}

void NumIslands::DFS(vector<vector<char>>& grid, int i, int j)
{
}

int FindJudge::findJudge(int N, vector<vector<int>>& trust)
{
	vector<int> pVecIn(N + 1, 0);
	vector<int> pVecOut(N + 1, 0);
	int iSize = trust.size();
	for (int i = 0; i < iSize; i++)
	{
		pVecOut[trust[i][0]]++;
		pVecIn[trust[i][1]]++;
	}

	int iJudge = 0;
	for (int i = 1; i <= N; i++)
	{
		if (pVecIn[i] == N - 1)
		{
			iJudge = i;
		}
	}

	if (!iJudge)
	{
		return -1;
	}

	if (pVecOut[iJudge])
	{
		return -1;
	}

	return iJudge;
}

int LadderLength::ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	set<string> pSet;
	for (auto p : wordList)
	{
		pSet.insert(p);
	}

	set<string> pSearched;
	queue<string> pQue;
	pQue.push(beginWord);
	int iLength = beginWord.length();
	int iCnt = 0;

	while (!pQue.empty())
	{
		int iSize = pQue.size();
		iCnt++;

		for (int i = 0; i < iSize; i++)
		{
			string sFront = pQue.front();
			if (sFront == endWord)
			{
				return iCnt;
			}

			pQue.pop();
			for (int j = 0; j < iLength; j++)
			{
				char pChar = sFront[j];

				string sTmpWord = sFront;
				while (pChar < 'z')
				{
					pChar++;
					sTmpWord[j] = pChar;
					if (pSearched.count(sTmpWord))
					{
						continue;
					}

					pSearched.insert(sTmpWord);
					if (pSet.count(sTmpWord))
					{
						pQue.push(sTmpWord);
					}
				}

				pChar = sFront[j];
				while (pChar > 'a')
				{
					pChar--;
					sTmpWord[j] = pChar;
					if (pSearched.count(sTmpWord))
					{
						continue;
					}

					pSearched.insert(sTmpWord);
					if (pSet.count(sTmpWord))
					{
						pQue.push(sTmpWord);
					}
				}
			}
		}
	}

	return 0;
}

int LadderLength::ladderLengthI(string beginWord, string endWord, vector<string>& wordList)
{
	queue<string> pQue;
	pQue.push(beginWord);

	int iRes = 0;
	while (!pQue.empty())
	{
		for (int i = pQue.size() - 1; i >= 0; i--)
		{
			string sVal = pQue.front();
			if (sVal == endWord)
			{
				return iRes;
			}

			pQue.pop();
			for (auto & w : wordList)
			{
				if (w.empty() || w.length() != beginWord.length())
				{
					continue;
				}

				int iDiff = 0;
				for (int j = 0; j < w.length(); j++)
				{
					if (w[j] != sVal[j])
					{
						iDiff++;
					}

					if (iDiff > 1)
					{
						break;
					}
				}

				if (iDiff <= 1)
				{
					pQue.push(w);
				}
			}
		}
	}

	return 0;
}

int LadderLength::ladderLengthII(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> pWordDic(wordList.begin(), wordList.end());
	if (pWordDic.find(endWord) != pWordDic.end())
	{
		return 0;
	}

	unordered_set<string> pBegin{ beginWord };
	unordered_set<string> pEnd{ endWord };
	int iRes = 0;
	while (!pBegin.empty())
	{
		iRes++;
		unordered_set<string> pTmpDic;
		for (auto word : pBegin)
		{
			pWordDic.erase(word);
		}

		for (auto word : pBegin)
		{
			for (int i = 0; i < word.length(); i++)
			{
				string sTmpWord = word;
				for (char pChar = 'a'; pChar < 'z'; pChar++)
				{
					sTmpWord[i] = pChar;
					if (pEnd.find(sTmpWord) != pEnd.end())
					{
						return iRes;
					}

					if (pWordDic.find(sTmpWord) != pWordDic.end())
					{
						pTmpDic.insert(sTmpWord);
					}
				}
			}
		}

		//// 从中间结果少的那一端来遍历
		pBegin = pTmpDic;
		if (pBegin.size() > pEnd.size())
		{
			swap(pBegin, pEnd);
		}
	}

	return 0;
} 

vector<int> MaxSlidingWindow::maxSlidingWindow(vector<int>& nums, int k)
{
	/*priority_queue<int, vector<int>, less<int>> pQue;
	vector<int> pVec;
	pVec.*/
	return vector<int>();
}

vector<vector<int>> SumOfKNum::fourSum(vector<int>& nums, int target)
{
	//sort(nums.begin(), nums.end());
	//for(int i = 0)

	return vector<vector<int>>();
}

int FindKLargest::findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> pQue;
	int iSize = nums.size();
	for (int i = 0; i < iSize; i++)
	{
		if (pQue.size() < k)
		{
			pQue.push(nums[i]);
		}
		else
		{
			int iTopVal = pQue.top();
			if (iTopVal < nums[i])
			{
				pQue.pop();
				pQue.push(nums[i]);
			}
		}
	}

	return pQue.top();
}

vector<vector<string>> GroupAnagrams::groupAnagrams(vector<string>& strs)
{
	unordered_map<string, vector<string>> map;
	for (auto pWord : strs)
	{
		string sTmpword = pWord;
		sort(sTmpword.begin(), sTmpword.end());
		map[sTmpword].push_back(pWord);
	}

	vector<vector<string>> pRes;
	for (auto pDic : map)
	{
		vector<string> pTmpVec = pDic.second;
		pRes.push_back(pTmpVec);
	}

	return pRes;
}

int LongestSubstring::longestSubstring(string s, int k)
{
	//map<char, int> pMap;
	//for (int i = 0; i < s.length(); i++)
	//{
	//	pMap[s[i]]++;
	//}

	//for (auto pPair : pMap)
	//{
	//	if (pPair.second >= k)
	//	{
	//		continue;
	//	}

	//	char pChar = pPair.first;
	//	for()
	//}

	return 0;
}
