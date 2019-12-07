#pragma once
#include"stdafx.h"
using namespace std;

//// ֻ�ܽ���һ��
class MaxProfit
{
public:
	int maxProfit(vector<int>& prices);
};


//// ���Զ�ν���
class MaxProfitII
{
public:
	//// �ǳ������ķ���
	int maxProfit(vector<int>& prices);

	//// �ǳ����ķ���
	int maxProfitII(vector<int>& prices);
};

class MaxProfitIII
{
public:
	int maxProfit(vector<int>& prices);
};

//// LeetCode.198 ��ҽ���
class DJJS
{
public:
	int rob(vector<int>& nums);

	//// ��ʹ������
	int robII(vector<int>& nums);
};

class JudgeSubsequence
{
public:
	bool isSubsequence(string s, string t);
};

class LeastCostJump
{
public:
	int minCostClimbingStairs(vector<int> &cost);
};

//// ������Ӵ�
class LongestSubStr {
public:
	string longestPalindrome(string s);
};

//// ������
class MaxRectangle {
public:
	int maximalRectangle(vector<vector<char>>& matrix);
};

//// LeetCode 62��63
class DifferentPath {
public:
	int uniquePathsI(int m, int n);

	//// �Ż�1
	int uniquePathsOptimizeI(int m, int n);

	//// �Ż�2
	int uniquePathsOptimizeII(int m, int n);

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
};


class MinPath {
public:
	int minPathSum(vector<vector<int>>& grid);
};