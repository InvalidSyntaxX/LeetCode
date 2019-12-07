#pragma once
#include"stdafx.h"
using namespace std;

//// 只能交易一次
class MaxProfit
{
public:
	int maxProfit(vector<int>& prices);
};


//// 可以多次交易
class MaxProfitII
{
public:
	//// 非常繁琐的方法
	int maxProfit(vector<int>& prices);

	//// 非常简答的方法
	int maxProfitII(vector<int>& prices);
};

class MaxProfitIII
{
public:
	int maxProfit(vector<int>& prices);
};

//// LeetCode.198 打家劫舍
class DJJS
{
public:
	int rob(vector<int>& nums);

	//// 不使用数组
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

//// 最长回文子串
class LongestSubStr {
public:
	string longestPalindrome(string s);
};

//// 最大矩形
class MaxRectangle {
public:
	int maximalRectangle(vector<vector<char>>& matrix);
};

//// LeetCode 62、63
class DifferentPath {
public:
	int uniquePathsI(int m, int n);

	//// 优化1
	int uniquePathsOptimizeI(int m, int n);

	//// 优化2
	int uniquePathsOptimizeII(int m, int n);

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
};


class MinPath {
public:
	int minPathSum(vector<vector<int>>& grid);
};